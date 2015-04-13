//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
// #include <boost/asio.hpp>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "axPython.h"

int main(int argc, char* argv[])
{
    
    axPython python;
    
    // python.InsertFolder(".");
    // python.InsertFolder("/Library/Python/2.7/site-packages/googleapiclient/");
    // python.InsertFolder("/Library/Python/2.7/site-packages/oauth2client/");
    python.InsertFolder("/Library/Frameworks/Python.framework/Versions/2.7/site-packages");
    python.LoadModule("ttt");
    
    std::vector<std::string> args;
    std::string answer = python.CallFunction("StringTest", args);

    return 0;
}
