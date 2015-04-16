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
    AddEventFunction("/add.html", GetOnAddPage());
    AddEventFunction("/search", GetOnSearch());
}

void PresentationPage::OnIndexPage(const http::server::request& req,
                                   http::server::reply& rep)
{
    axHtmlPage page;
    page.BeginPage();
    page.BeginHead();
    
    page.EndHead();

    page.BeginBody();


    axHtmlNavigationBar nav("Playlist");
    nav.Begin();

    nav.End();

    page.AddElement(&nav);
    
    // page.Add("<h1>Test</h1>");
    
    //--------------------------------------------------------------------------

    // int argc = 1;
    // char* argv[] = {"axPython"};
    // axPython python(argc, argv);
    
    // python.InsertFolder(GetDocRoot());
    // python.InsertFolder("/Library/Python/2.7/site-packages");
    // python.LoadModule("ttt");
    
    // std::vector<std::string> args;
    // args.push_back("Blink182");
    // std::string answer = python.CallFunction("StringTest", args);
    
    // page.Add(answer);

    page.EndBody();
    page.EndPage();
    
    rep.Setup(http::server::reply::ok, page.GetHtmlPage(), "html");
}

void PresentationPage::OnAddPage(const http::server::request& req,
                                 http::server::reply& rep)
{
    axHtmlPage page;
    page.BeginPage();
    page.BeginHead();
    
    page.EndHead();

    page.BeginBody();

    axHtmlNavigationBar nav("Playlist");
    nav.Begin();
    nav.Add("<li><a href=\"#\">Add</a></li>");
    nav.End();

    page.AddElement(&nav);
    
    page.Add("<form action=\"search\">");
    page.Add("<fieldset>");
    page.Add("<legend>Personal information:</legend>");
    page.Add("Search:<br>");
    page.Add("<input type=\"text\" name=\"search_video\" value=\"" + _searchString + "\"><br>");
    page.Add("<input type=\"submit\" value=\"Submit\"></fieldset></form>");

    //     html = '<form action="search">'
    // html += '<fieldset>'
    // html += '<legend>Personal information:</legend>'
    // html += 'First name:<br>'
    // html += '<input type="text" name="search_video" value="Mickey">'
    // html += '<br>'
    // # html += 'Last name:<br>'
    // # html += '<input type="text" name="lastname" value="Mouse">'
    // html += '<br><br>'
    // html += '<input type="submit" value="Submit"></fieldset>'
    // html += '</form>'

    // html +='<div class="list-group media">';

    if(_searchString != " ")
    {
        int argc = 1;
        char* argv[] = {"axPython"};
        axPython python(argc, argv);
    
        python.InsertFolder(GetDocRoot());
        python.InsertFolder("/Library/Python/2.7/site-packages");
        python.LoadModule("ttt");
    
        std::vector<std::string> args;
        args.push_back(_searchString);
        std::string answer = python.CallFunction("SearchPage", args);

        page.Add(answer);
    }
    
    
    

    page.EndBody();
    page.EndPage();
    
    rep.Setup(http::server::reply::ok, page.GetHtmlPage(), "html");
}

void PresentationPage::OnSearch(const http::server::request& req,
                                 http::server::reply& rep)
{


    std::cout << "search : " << req.uri << std::endl;

    axVectorPairString att = GetParameterListFromUrl(req.uri);

    for(auto& n : att)
    {
        if(n.first == "search_video")
        {
            _searchString = n.second;
        }
    }

    axHtmlPage page;
    page.BeginPage();
    page.BeginHead();
    page.Add("<meta http-equiv=\"refresh\" content=\"0; url=add.html\" />");
    page.EndHead();
    page.EndPage();

    std::cout << "Search Path : " << _searchString << std::endl;

    rep.Setup(http::server::reply::ok, page.GetHtmlPage(), "html");
}





