#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  PyObject ;
typedef  int /*<<< orphan*/  PyArrayObject ;

/* Variables and functions */
 scalar_t__ PyArray_FROM_O (int /*<<< orphan*/ *) ; 
 scalar_t__ PyArray_ISCOMPLEX (int /*<<< orphan*/ *) ; 
 int PyArray_MoveInto (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PyErr_SetString (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  PyExc_AttributeError ; 
 int /*<<< orphan*/  Py_DECREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_INCREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * _get_part (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
array_real_set(PyArrayObject *self, PyObject *val)
{
    PyArrayObject *ret;
    PyArrayObject *new;
    int retcode;

    if (val == NULL) {
        PyErr_SetString(PyExc_AttributeError,
                "Cannot delete array real part");
        return -1;
    }
    if (PyArray_ISCOMPLEX(self)) {
        ret = _get_part(self, 0);
        if (ret == NULL) {
            return -1;
        }
    }
    else {
        Py_INCREF(self);
        ret = self;
    }
    new = (PyArrayObject *)PyArray_FROM_O(val);
    if (new == NULL) {
        Py_DECREF(ret);
        return -1;
    }
    retcode = PyArray_MoveInto(ret, new);
    Py_DECREF(ret);
    Py_DECREF(new);
    return retcode;
}