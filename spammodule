#include <Python.h>

static PyObject * SpamError;

static PyObject *
spam_system(PyObject *self, PyObject * args)
{
	const char *command;
	int sts;

	// if(!PyArg_ParseTuple(args, "s", &command))
	// 	return NULL;
	//char *key;
	//*key = 'a';

	PyObject *large_dict = NULL;
	PyObject *lol = NULL;
	if (! PyArg_ParseTuple( args, "O!", &PyDict_Type, &large_dict)) return NULL;
	if (large_dict != NULL)
	{	
	   printf("\nprior\n" );
	   lol = PyDict_GetItemString(large_dict, "a");
	   PyObject* objectsRepresentation = PyObject_Repr(lol);
		const char* s = PyString_AsString(objectsRepresentation);

	   printf("%s\n", s );
	   printf("Large Dictionary Not Null\n");
	   //printf("%s\n", large_dict);
	   return Py_BuildValue("i", 0);
	}

}

PyMODINIT_FUNC
initspam(void)
{
	PyObject *m;
	static PyMethodDef SpamMethods[] = {
		{"system", spam_system, METH_VARARGS, "Execute a shell command."},
		{NULL, NULL, 0, NULL}
	};
	printf("HAS\n" );
	m = Py_InitModule("spam", SpamMethods);
	printf("\nHos\n" );
	if ( m == NULL )
		return;
	printf("\nHos\n" );
	SpamError = PyErr_NewException("spam.error", NULL, NULL);
	Py_INCREF(SpamError);
	printf("\nHSs\n" );
	PyModule_AddObject(m, "error", SpamError);
}

int
main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	initspam();
}

