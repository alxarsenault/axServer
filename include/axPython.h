//
// connection.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AX_PYTHON
#define AX_PYTHON

#include <Python.h>
#include <iostream>
#include <unistd.h>
// https://docs.python.org/2/extending/embedding.html
#include <string>
#include <vector>
#include <stdio.h>

class axPython
{
public :
    axPython();
    
    ~axPython();

    void InsertFolder(const std::string& folder_path);
    
    void InsertCurrentAppDirectory();
    
    void LoadModule(const std::string& module_name);
    
    std::string CallFunction(const std::string& fct_name, const std::vector<std::string>& args);
    
private:
    PyObject* _module;
};



#endif // AX_PYTHON
