//#include <Python.h>
//#include <iostream>
//#include <unistd.h>
//// https://docs.python.org/2/extending/embedding.html
//#include <string>
//#include <vector>
//#include <stdio.h>

#include "axPython.h"

//class axPython
//{
//public :
axPython::axPython()
{
    std::cout << "axPython." << std::endl;
    Py_SetProgramName("axServer");  /* optional but recommended */

    //char pySearchPath[] = "/Library/Frameworks/Python.framework/Versions/2.7/";///site-packages";
    //Py_SetPythonHome(pySearchPath);

    Py_Initialize();
    InsertCurrentAppDirectory();

     std::cerr << "PATH" << Py_GetPath() << std::endl;
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
    PyObject* myModuleString = PyString_FromString((char*)module_name.c_str());
    _module = PyImport_Import(myModuleString);
}

std::string axPython::CallFunction(const std::string& fct_name, const std::vector<std::string>& args)
{

    
    PyObject* myFunction = PyObject_GetAttrString(_module, (char*)fct_name.c_str());
    
    //PyObject* args = PyTuple_Pack(2, PyFloat_FromDouble(6.0), PyFloat_FromDouble(2.0));
    PyObject* fct_args = NULL;
    PyObject* myResult = PyObject_CallObject(myFunction, fct_args);
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
