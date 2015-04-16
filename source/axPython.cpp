//#include <Python.h>
//#include <iostream>
//#include <unistd.h>
//// https://docs.python.org/2/extending/embedding.html
//#include <string>
//#include <vector>
//#include <stdio.h>

#include "axPython.h"

axPython::axPython(int argc, char* argv[])
{
    // std::cout << "axPython." << std::endl;
    Py_SetProgramName(argv[0]);  /* optional but recommended */

    Py_Initialize();
    PySys_SetArgv(argc, argv); // must call this to get sys.argv and relative imports


    // /usr/lib/libpython2.7.dylib

    // char pySearchPath[] = "/usr/bin/python2.7";
    //char pySearchPath[] = "/usr/lib/libpython2.7.dylib";
    // char pySearchPath[] = "/Library/Python/2.7/";///site-packages";
    // Py_SetPythonHome(pySearchPath);

    
    InsertCurrentAppDirectory();

     // std::cerr << "PATH" << Py_GetPath() << std::endl;
}

axPython::~axPython()
{
    Py_Finalize();
}

void axPython::InsertCurrentAppDirectory()
{
    char* buffer = new char[1024];
    getcwd(buffer, 1024);
    
    std::string app_path(buffer);
    delete buffer;
    app_path += "/";
    
    // std::cout << app_path << std::endl;
    std::string insert_path("import sys \nsys.path.insert(1,'"+ app_path + "')\n ");
    PyRun_SimpleString(insert_path.c_str());
}

void axPython::InsertFolder(const std::string& folder_path)
{
    std::string insert_path("import sys \nsys.path.insert(1,'"+ folder_path + "')\n ");
    PyRun_SimpleString(insert_path.c_str());
}

void axPython::LoadModule(const std::string& module_name)
{
    PyObject* moduleString = PyString_FromString((char*)module_name.c_str());
    _module = PyImport_Import(moduleString);
    Py_DECREF(moduleString);

    if(_module == nullptr)
    {
        std::cerr << "ERROR : " << std::endl;
        PyErr_Print();
        exit(1);
    }
}

std::string axPython::CallFunction(const std::string& fct_name, const std::vector<std::string>& args)
{
    PyObject* myFunction = PyObject_GetAttrString(_module, (char*)fct_name.c_str());
    
    //PyObject* fctArg = PyObject_GetAttrString(_module, (char*)fct_name.c_str());

    // PyObject* fct_args = NULL;

    // if(args.size())
    // {
    //     std::cout << "Add argument" << std::endl;
    //     fct_args = PyObject_GetAttrString(_module, (char*)args[0].c_str());
    // }

    // PyObject* tuple_args = PyTuple_Pack(1, fct_args);
    PyObject* pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, PyString_FromString(args[0].c_str()));
    
    PyObject* myResult = PyObject_CallObject(myFunction, pArgs);
    PyObject* objectsRepresentation = PyObject_Repr(myResult);
    const char* s = PyString_AsString(objectsRepresentation);
    
    std::string answer(s);
    answer = answer.substr(answer.find_first_of("'") + 1, answer.length());
    answer = answer.substr(0, answer.find_last_of("'"));
    

    return answer;
}
//
//private:
//    PyObject* _module;
//};

//int main(int argc, char *argv[])
//{
//    axPython python;
//    python.LoadModule("ttt");
//
//    std::vector<std::string> args;
//    std::string answer = python.CallFunction("StringTest", args);
//
//    std::cout << answer << std::endl;
//
//    return 0;
//}
