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
//
            RequestCallback(request_path, req, rep);
//            std::cout << request_path << std::endl;
//            
//            std::string request_keyword =
//            request_path.substr(0, request_path.find_last_of("."));
//            
//            if(request_keyword == "/navigator")
//            {
//                //std::cout << "TEST" << std::endl;
//                
//                
//                std::vector<std::string> elems;
//                boost::filesystem::path someDir("/Users/alexarse/");
//                
//                if(is_directory(someDir))
//                {
//                    for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(someDir), {}))
//                    {
//                        elems.push_back(entry.path().leaf().string());
//                    }
//                }
//                
//                axHtmlPage page;
//                page.Begin();
//                
//                axHtmlPanel list_panel(someDir.string());
//    
//                list_panel.Begin();
//                
//                axHtmlList html_list(elems);
//                list_panel.AddElement(&html_list);
//                
//                list_panel.End();
//                
//                page.AddElement(&list_panel);
//                
//                
//                axHtmlPanel test_panel("Panel");
//                test_panel.Begin();
//                test_panel.Add("<form action=\"MyAction\" method=\"post\">");
//                test_panel.Add("<button type=\"submit\" name=\"my_button_test\"  class=\"btn btn-default\" value=\"my_button_value\">Left</button>");
//                test_panel.Add("</form>");
//                test_panel.End();
//                
//                page.AddElement(&test_panel);
//                
//                page.End();
//                
//                rep.Setup(reply::ok, page.GetHtmlPage(), "html");
//            }
//            else if(request_path == "/MyAction")
//            {
//                std::cout << "MyAction" << std::endl;
//            }
//            else
//            {
//                // Determine the file extension.
//                std::string extension = GetFileExtension(request_path);
//                
//                // Open the file to send back.
//                std::string full_path = doc_root_ + request_path;
//                
//                std::ifstream is(full_path.c_str(),
//                                 std::ios::in | std::ios::binary);
//                
//                if (!is)
//                {
//                    rep = reply::stock_reply(reply::not_found);
//                    return;
//                }
//                
//                // Fill out the reply to be sent to the client.
//                rep.status = reply::ok;
//                
//                char buf[512];
//                
//                while (is.read(buf, sizeof(buf)).gcount() > 0)
//                {
//                    rep.content.append(buf, is.gcount());
//                }
//                
//                rep.headers.resize(2);
//                rep.headers[0].name = "Content-Length";
//                rep.headers[0].value = std::to_string(rep.content.size());
//                rep.headers[1].name = "Content-Type";
//                rep.headers[1].value = mime_types::extension_to_type(extension);
//            }
            
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