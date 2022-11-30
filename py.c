#include <Python.h> //-I/usr/local/Cellar/python@3.9/3.9.1_8/Frameworks/Python.framework/Versions/3.9/include/python3.9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>

#define PY_SSIZE_T_CLEAN

int main(void)
{
    printf("imported python header file\n");
    printf("%d\n", Py_MAX(10, 5));

    return 0;
}

static PyObject *weakref_ref(PyObject *self, PyObject *args)
{
    PyObject *object, *callback, *result;
    callback, result = NULL;

    if (PyArg_UnpackTuple(args, "ref", 1, 2, &object, &callback))
    {
        result = PyWeakref_NewRef(object, callback);
    }

    return result;
}