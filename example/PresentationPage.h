//
//  PresentationPage.h
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-09.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#ifndef __HttpServer__PresentationPage__
#define __HttpServer__PresentationPage__

#include "axWebApp.h"

class PresentationPage : public axWebApp
{
public:
    PresentationPage(const std::string& root_path);
    
private:
    axEVENT_ACCESSOR(OnIndexPage);
    void OnIndexPage(const http::server::request& req,
                     http::server::reply& rep);


    axEVENT_ACCESSOR(OnAddPage);
    void OnAddPage(const http::server::request& req,
                    http::server::reply& rep);

    axEVENT_ACCESSOR(OnSearch);
    void OnSearch(const http::server::request& req,
                  http::server::reply& rep);


    std::string _searchString;
};

#endif /* defined(__HttpServer__PresentationPage__) */
