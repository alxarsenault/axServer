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
#include <boost/asio.hpp>
#include "server.h"

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "axHtml.h"

#include "PresentationPage.h"


// Usage : <address> <port> <root_folder>
int main(int argc, char* argv[])
{
    try
    {
        // Check command line arguments.
        if (argc != 4)
        {
            std::cerr << "Usage: http_server <address> <port> <root_folder>\n";
            return 1;
        }
        
        PresentationPage app(argv[3]);
        
        // Initialise the server.
        http::server::server s(argv[1], argv[2], &app);
        
        // Run the server until stopped.
        s.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }
    
    return 0;
}
