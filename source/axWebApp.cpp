//
//  axWebApp.cpp
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-08.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#include "axWebApp.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
//#include "mime_types.h"
//#include "reply.h"
//#include "request.h"
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "axHtml.h"

axWebApp::axWebApp(const std::string& doc_root) :
http::server::request_handler(doc_root)
{
    
}

void axWebApp::RequestCallback(const std::string& url,
                               const http::server::request& req,
                               http::server::reply& rep)
{
    std::string r_keyword = url;
    
    //$(url);
    
    size_t pos = r_keyword.find_first_of("?");
    
    if(pos != std::string::npos)
    {
        r_keyword = r_keyword.substr(0, pos);
    }
    
    axWevEvtMap::iterator it = _eventMap.find(r_keyword);
    
    if(it != _eventMap.end())
    {
        it->second(req, rep);
    }
    else
    {
        std::string request_path = req.uri;
        
        std::cout << "res : " << request_path << std::endl;
        
        // Determine the file extension.
        std::string extension = GetFileExtension(request_path);
        
        // Open the file to send back.
        std::string full_path = doc_root_ + request_path;
        
        std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
        
        if (!is)
        {
            rep = http::server::reply::stock_reply(http::server::reply::not_found);
            return;
        }
        
        // Fill out the reply to be sent to the client.
        rep.status = http::server::reply::ok;
        
        char buf[512];
        
        while (is.read(buf, sizeof(buf)).gcount() > 0)
        {
            rep.content.append(buf, is.gcount());
        }
        
        rep.headers.resize(2);
        rep.headers[0].name = "Content-Length";
        rep.headers[0].value = std::to_string(rep.content.size());
        rep.headers[1].name = "Content-Type";
        rep.headers[1].value = http::server::mime_types::extension_to_type(extension);
    }
}

void axWebApp::AddEventFunction(const std::string& name,
                                const axWebEvtFunction& fct)
{
    std::cout << "Add : " << name << " to event map." << std::endl;
    _eventMap.insert(std::pair<std::string, axWebEvtFunction>(name, fct));
}

axVectorPairString axWebApp::GetParameterListFromUrl(const std::string& url) const
{
    axVectorPairString vec;
    std::string tmp = url, name, value;
    vec.clear();
    
    // Decode form parameter.
    size_t pos = url.find_first_of("?");
    
    if(pos != std::string::npos)
    {
        tmp = url.substr(pos + 1, tmp.length());
    }
    
    std::string param;
    while((pos = tmp.find_first_of("&")) != std::string::npos)
    {
        param = tmp.substr(0, pos);
        size_t pos_left = param.find_first_of("=");
        name = param.substr(0, pos_left);
        value = param.substr(pos_left+1, pos);
        vec.push_back(std::pair<std::string, std::string>(name, value));
        tmp = tmp.substr(pos + 1, tmp.length());
    }
    
    if((pos = tmp.find_first_of("=")) != std::string::npos)
    {
        name = tmp.substr(0, pos);
        value = tmp.substr(pos + 1, tmp.length());
        vec.push_back(axPairString(name, value));
    }
    
    return vec;
}