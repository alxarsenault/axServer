//
//  axWebApp.h
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-08.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#ifndef __HttpServer__axWebApp__
#define __HttpServer__axWebApp__

#include "request_handler.h"
#include "axWebUtils.h"
#include <map>

#define axEVENT_ACCESSOR(FUNC) axWebEvtFunction Get ## FUNC() \
{ return [=](const http::server::request& req, http::server::reply& rep){ return this->FUNC(req, rep); }; }

typedef std::pair<std::string, std::string> axPairString;
typedef std::vector<axPairString> axVectorPairString;

class axWebApp : public http::server::request_handler
{
public:
    axWebApp(const std::string& doc_root);
    
    typedef std::function<void(const http::server::request& req,
                               http::server::reply& rep)> axWebEvtFunction;
//    virtual void handle_request(const http::server::request& req,
//                                http::server::reply& rep);
    
    void AddEventFunction(const std::string& name, const axWebEvtFunction& fct);
    
    axVectorPairString GetParameterListFromUrl(const std::string& url) const;
    
protected:
    
    typedef std::map<std::string, axWebEvtFunction> axWevEvtMap;
    axWevEvtMap _eventMap;
    
    virtual void RequestCallback(const std::string& url,
                                 const http::server::request& req,
                                 http::server::reply& rep);
    
    
};

#endif /* defined(__HttpServer__axWebApp__) */
