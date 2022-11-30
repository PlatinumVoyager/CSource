#include <stdio.h>
#include <regex.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   
    int ret;
    char buff[100];

    // create regex variable
    regex_t regex;

    /* compile the regular expression */
    ret = regcomp(&regex, "^a[[:alnum:]]", REG_EXTENDED);
    if (ret)
    {
        fprintf(stderr, "failed to compile regular expression\n");

        return -1;
    }

    /* execute the regular expression */
    ret = regexec(&regex, argv[1], 0, NULL, 0);
    if (!ret)
    {
        puts("match found");

    } else if (ret == REG_NOMATCH)
    {
        fprintf(stderr, "failed to find appropriate match\n");
    
    } else 
    {
        regerror(ret, &regex, buff, sizeof(buff));
        fprintf(stderr, "regex match failed: %s\n", buff);

        return -1;
    }

    regfree(&regex);

    return 0;
}