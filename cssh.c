#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define LIBSSH_STATIC 1
#include <libssh/libssh.h>

struct ssh_attach
{
    char *host, *user;
    int port, verbosity, timeout;
    char *password, *ssh_directory;
};


int main(void)
{
    int cb, rc;

    struct ssh_attach *ssh_config, ssh_cpy;
    ssh_config = &ssh_cpy;

    (*ssh_config).host = "192.168.0.55";
    (*ssh_config).port = 6783;
    (*ssh_config).timeout = 10;
    (*ssh_config).verbosity = SSH_LOG_PROTOCOL;
    (*ssh_config).ssh_directory = "/";

    ssh_session ssh_connect_new = ssh_new();

    if (ssh_connect_new == NULL)
    {
        fprintf(stderr, "Failed to init -> ssh_new():: Failed to create new session...");
        return EXIT_FAILURE;
    }

    puts("++ Setting SSH options ++");

    (*ssh_config).user = getpass("User: ");

    ssh_options_set(ssh_connect_new, SSH_OPTIONS_HOST, &ssh_config->host);
    ssh_options_set(ssh_connect_new, SSH_OPTIONS_LOG_VERBOSITY, &ssh_config->verbosity);
    ssh_options_set(ssh_connect_new, SSH_OPTIONS_PORT, &ssh_config->port);
    ssh_options_set(ssh_connect_new, SSH_OPTIONS_USER, &ssh_config->user);
    
    ssh_options_set(ssh_connect_new, SSH_OPTIONS_SSH_DIR, &ssh_config->ssh_directory);
    ssh_options_set(ssh_connect_new, SSH_OPTIONS_TIMEOUT, &ssh_config->timeout);

    puts("++ SSH options set ++");

    cb = ssh_connect(ssh_connect_new);

    if (cb != SSH_OK)
    {
        fprintf(stderr, "FATAL:: Failed to connect to host -> \"%s\"\n%s", ssh_config->host,
        ssh_get_error(ssh_connect_new));

        return EXIT_FAILURE;
    }

    // verify server
    if (verify_known_hosts(ssh_connect_new) < 0)
    {
        ssh_disconnect(ssh_connect_new);
        ssh_free(ssh_connect_new);

        return EXIT_FAILURE;
    }

    (*ssh_config).user = getpass("User: ");
    (*ssh_config).password = getpass("Credentials: ");

    rc = ssh_userauth_password(ssh_connect_new, ssh_config->user, ssh_config->password);
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "FATAL:: Failed to connect to server/device -> %s\n", ssh_get_error(ssh_connect_new));
        
        ssh_disconnect(ssh_connect_new);
        ssh_free(ssh_connect_new);
        
        return EXIT_FAILURE;
    }

    int proc;
    proc = show_remote_processes(ssh_connect_new);

    printf("%d\n", proc);

    // clean up ssh session; call free
    ssh_disconnect(ssh_connect_new);
    ssh_free(ssh_connect_new);

    return 0;
}

int verify_known_hosts(ssh_session session)
{
    enum ssh_known_hosts_e state;
    
    unsigned char *hash = NULL;
    ssh_key srv_pubkey = NULL;
    size_t hlen;

    char buffer[10];
    char *hexa, *p;
    int cmp, rc;

    rc = ssh_get_server_publickey(session, &srv_pubkey);
    if (rc < 0)
    {
        return EXIT_FAILURE;
    }

    rc = ssh_get_publickey_hash(srv_pubkey, SSH_PUBLICKEY_HASH_SHA1, &hash, &hlen);
    ssh_key_free(srv_pubkey);
    if (rc < 0)
    {
        return EXIT_FAILURE;
    }

    state = ssh_session_is_known_server(session);
    switch (state)
    {
        case SSH_KNOWN_HOSTS_OK:
            printf("Ok..");
            break;

        case SSH_KNOWN_HOSTS_CHANGED:
            fprintf(stderr, "Host key changed. Key for server:\n");
            ssh_print_hexa("Pubkey hash", hash, hlen);

            fprintf(stderr, "-- Closing connection for security reasons --\n");
            ssh_clean_pubkey_hash(&hash);

            return EXIT_FAILURE;

        case SSH_KNOWN_HOSTS_OTHER:
            fprintf(stderr, "Host key for server not found. Found other key that exits...\n");
            fprintf(stderr, "An attacker could possibly change the key to trick your client\n");

            ssh_clean_pubkey_hash(&hash);
            return EXIT_FAILURE;

        case SSH_KNOWN_HOSTS_NOT_FOUND:
            fprintf(stderr, "Known hosts file not found\n");
            fprintf(stderr, "If you accept the host key. The file will be created");
    
        case SSH_KNOWN_HOSTS_UNKNOWN:
            hexa = ssh_get_hexa(hash, hlen);
            fprintf(stderr, "The server is unknown. Do you trust the public key?\n");
            fprintf(stderr, "Public key hash: %s\n", hexa);

            ssh_string_free_char(hexa);
            ssh_clean_pubkey_hash(&hash);

            p = fgets(buffer, sizeof(buffer), stdin);
            if (p == NULL)
            {
                return EXIT_FAILURE;
            }

            cmp = strncasecmp(buffer, "yes", 3);
            if (cmp != 0)
            {
                // not accepting server public key
                return EXIT_FAILURE;
            }

            rc = ssh_session_update_known_hosts(session);
            if (rc < 0)
            {
                fprintf(stderr, "FATAL:: Error -> %s\n", strerror(errno));
                return EXIT_FAILURE;
            }

            break;
        
        case SSH_KNOWN_HOSTS_ERROR:
            fprintf(stderr, "FATAL:: Error -> %s\n", ssh_get_error(session));
            ssh_clean_pubkey_hash(&hash);

            return EXIT_FAILURE;
    }

    ssh_clean_pubkey_hash(&hash);
    return EXIT_SUCCESS;
}

int show_remote_processes(ssh_session session)
{
    ssh_channel channel;

    int rc, nbytes;
    char buffer[256];

    channel = ssh_channel_new(session);
    if (channel == NULL)
    {
        return SSH_ERROR;
    }

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK)
    {
        ssh_channel_free(channel);
        return rc;
    }

    rc = ssh_channel_request_exec(channel, "ps aux");
    if (rc != SSH_OK)
    {
        ssh_channel_close(channel);
        ssh_channel_free(channel);

        return rc;
    }

    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    while (nbytes > 0)
    {
        if (write(1, buffer, nbytes) != (unsigned int) nbytes)
        {
            ssh_channel_close(channel);
            ssh_channel_free(channel);

            return SSH_ERROR;
        }

        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }

    if (nbytes < 0)
    {
        ssh_channel_close(channel);
        ssh_channel_free(channel);

        return SSH_ERROR;
    }

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);

    return SSH_OK;
}