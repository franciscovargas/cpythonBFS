#include <Python.h>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

// #include "boost/unordered_map.hpp"

using namespace std;

static PyObject * SpamError;

static PyObject *
spam_system(PyObject *self, PyObject * args)
{

	unordered_map<string, unordered_set<string>> Graph;

	PyObject *large_dict = NULL;
	PyObject *lol = NULL;

	if (! PyArg_ParseTuple( args, "O!", &PyDict_Type, &large_dict)) return NULL;
	
	if (large_dict != NULL)
	{	
	   printf("\nprior\n" );
	   lol = PyDict_GetItemString(large_dict, "A");
	   PyObject* objectsRepresentation = PyObject_Repr(lol);
	   PyObject *pKeys = PyDict_Keys(large_dict); // new reference

	   for(int i = 0; i < PyList_Size(pKeys); ++i) 
    	{
	        PyObject *pKey = PyList_GetItem(pKeys, i); // borrowed reference
	        PyObject *pValue = PyDict_GetItem(large_dict, pKey); // borrowed reference
	        Graph[PyString_AsString(pKey)] = {};
	        for(int j = 0; j < PyList_Size(pValue); ++j){
	        	cout << j << "  KEK  " << "\n";
	        	cout << "   " << PyString_AsString(PyList_GetItem(pValue, j)) << "\n";
	        	Graph[PyString_AsString(pKey)].insert(PyString_AsString(PyList_GetItem(pValue, j)));
	        }
	        // cout << "KEY "<< PyString_AsString(pKey) << std::endl;
	        //assert(pValue);
    	}
	   
	   Py_DECREF(pKeys);
	   const char* s = PyString_AsString(objectsRepresentation);

	   printf("%s\n", s );
	   printf("Large Dictionary Not Null\n");
	   cout << "\n" << *(Graph["A"].begin()) << "  KEK" << "\n";
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

