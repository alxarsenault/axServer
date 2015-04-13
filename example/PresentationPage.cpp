//
//  PresentationPage.cpp
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-09.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#include "PresentationPage.h"
#include "axHtml.h"
#include <fstream>
#include "axPython.h"

PresentationPage::PresentationPage(const std::string& root_path) :
axWebApp(root_path)
{
    AddEventFunction("/index.html", GetOnIndexPage());

}

void PresentationPage::OnIndexPage(const http::server::request& req,
                                   http::server::reply& rep)
{
    // axHtmlPage page;
    // page.BeginPage();
    // page.BeginHead();
    
    // page.EndHead();
    // page.BeginBody();
    
    // page.Add("<h1>Test</h1>");
    
    //--------------------------------------------------------------------------
    axPython python;
    
    python.InsertFolder(GetDocRoot());
    // python.InsertFolder("/Library/Python/2.7/site-packages/googleapiclient/");
    // python.InsertFolder("/Library/Python/2.7/site-packages/oauth2client/");
    python.InsertFolder("/Library/Python/2.7/site-packages");
    python.LoadModule("ttt");
    
    std::vector<std::string> args;
    std::string answer = python.CallFunction("StringTest", args);
    
    // std::cout << answer << std::endl;
    // //--------------------------------------------------------------------------

    // page.EndBody();
    // page.EndPage();
    
    rep.Setup(http::server::reply::ok, answer, "html");
}
