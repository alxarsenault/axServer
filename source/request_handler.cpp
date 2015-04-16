//
// request_handler.cpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "request_handler.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
//#include "mime_types.h"
//#include "reply.h"
//#include "request.h"

#include "axWebUtils.h"

#include <functional>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "axHtml.h"

void $()
{
    std::cout << std::endl;
}

namespace http
{
    namespace server
    {
        request_handler::request_handler(const std::string& doc_root) :
        doc_root_(doc_root)
        {
            
        }
        
        
        void request_handler::handle_request(const request& req, reply& rep)
        {
            std::cout << "request_handler::handle_request" << std::endl;
            // Decode url to path.
            std::string request_path;
            
            if(req.method == "POST")
            {
                $(req.method, "Header size =", req.headers.size());
                $("Uri :", req.uri);
                
                for (std::size_t i = 0; i < req.headers.size(); ++i)
                {
                    $(req.headers[i].name, req.headers[i].value);
                }
            }

            if (!url_decode(req.uri, request_path))
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }
//
            // Request path must be absolute and not contain "..".
            if (request_path.empty() || request_path[0] != '/'
                || request_path.find("..") != std::string::npos)
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }
//
            // If path ends in slash (i.e. is a directory) then add "index.html".
            if (request_path[request_path.size() - 1] == '/')
            {
                request_path += "index.html";
            }

            RequestCallback(request_path, req, rep);
        }
        
        void request_handler::RequestCallback(const std::string& url,
                                              const request& req,
                                              reply& rep)
        {
            
        }
        
        bool request_handler::url_decode(const std::string& in, std::string& out)
        {
            out.clear();
            out.reserve(in.size());
            for (std::size_t i = 0; i < in.size(); ++i)
            {
                if (in[i] == '%')
                {
                    if (i + 3 <= in.size())
                    {
                        int value = 0;
                        std::istringstream is(in.substr(i + 1, 2));
                        if (is >> std::hex >> value)
                        {
                            out += static_cast<char>(value);
                            i += 2;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (in[i] == '+')
                {
                    out += ' ';
                }
                else
                {
                    out += in[i];
                }
            }
            return true;
        }
        
        std::string request_handler::GetFileExtension(const std::string& path)
        {
            std::string file_path = path;
            
            // Determine the file extension.
            std::size_t last_slash_pos = file_path.find_last_of("/");
            std::size_t last_dot_pos = file_path.find_last_of(".");
            std::string extension;
            
            if (last_dot_pos != std::string::npos &&
                last_dot_pos > last_slash_pos)
            {
                extension = file_path.substr(last_dot_pos + 1);
            }
            
            return extension;
        }
        
    } // namespace server
} // namespace http