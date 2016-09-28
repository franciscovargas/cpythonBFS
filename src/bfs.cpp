#include <Python.h>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <iostream>

// #include "boost/unordered_map.hpp"

using namespace std;

static PyObject * SpamError;

void BFS(unordered_map<string,unordered_set<string>> &graph, string node){

    deque<string> que = {node};
    unordered_set<string> cache = {node};

    while( !(que.empty()) ){

        string cur_node = que.front();
        que.pop_front();

        unordered_set<string> children = graph[cur_node];
        for(unordered_set<string>::iterator a = children.begin(); a != children.end(); ++a) {
            string child = *a;

            const bool b = !(cache.find(child) != cache.end());
            if(b ) {
                cout << child << endl;
                que.push_back(child);
                cache.insert(child);
            }
        }

    }
}

static PyObject *
transfer_adj_bfs(PyObject *self, PyObject * args)
{

	unordered_map<string, unordered_set<string>> Graph;

	PyObject *large_dict = NULL;
	PyObject *lol = NULL;

	const char *root;



	if (! PyArg_ParseTuple( args, "O!s", &PyDict_Type, &large_dict, &root)) return NULL;
	
	if (large_dict != NULL)
	{	

	   lol = PyDict_GetItemString(large_dict, "A");
	   PyObject* objectsRepresentation = PyObject_Repr(lol);
	   PyObject *pKeys = PyDict_Keys(large_dict); // new reference

	   for(int i = 0; i < PyList_Size(pKeys); ++i) 
    	{
	        PyObject *pKey = PyList_GetItem(pKeys, i); // borrowed reference
	        PyObject *pValue = PyDict_GetItem(large_dict, pKey); // borrowed reference
	        Graph[PyString_AsString(pKey)] = {};
	        for(int j = 0; j < PyList_Size(pValue); ++j){
	        	Graph[PyString_AsString(pKey)].insert(PyString_AsString(PyList_GetItem(pValue, j)));
	        }
    	}
	   
	   Py_DECREF(pKeys);

	   BFS(Graph, root);
	   return Py_BuildValue("i", 0);
	}

}

PyMODINIT_FUNC
initbfs_c(void)
{
	PyObject *m;
	static PyMethodDef SpamMethods[] = {
		{"bfs", transfer_adj_bfs, METH_VARARGS, "FAST C++ BFS"},
		{NULL, NULL, 0, NULL}
	};

	m = Py_InitModule("bfs_c", SpamMethods);

	if ( m == NULL )
		return;

	SpamError = PyErr_NewException("bfs_c.error", NULL, NULL);
	Py_INCREF(SpamError);

	PyModule_AddObject(m, "error", SpamError);
}

int
main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	initbfs_c();
}

