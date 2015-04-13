//
//  axHtml.h
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-08.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#ifndef __HttpServer__axHtml__
#define __HttpServer__axHtml__

#include <string>
#include <vector>


class axHtmlElement
{
public:
    axHtmlElement();
    
    void Add(const std::string& item);
    
    void AddElement(axHtmlElement* element);
    
    void Clear();

    std::string GetHtmlElement() const;
    
private:
    std::string _html_element;
};

class axHtmlList : public axHtmlElement
{
public:
    axHtmlList(const std::vector<std::string>& strList);
    
    
private:
    std::string _html_list;
};

class axHtmlLinkList : public axHtmlElement
{
public:
    
    struct axHtmlLinkListElement
    {
        std::string name;
        std::string link_address;
    };
    
    axHtmlLinkList(const std::vector<axHtmlLinkListElement>& infoList);
};

class axHtmlPanel : public axHtmlElement
{
public:
    axHtmlPanel(const std::string& panel_header = "");
    
    void Begin();
    void End();
    
private:
    std::string _panel_header;
};

class axHtmlNavigationBar : public axHtmlElement
{
public:
    axHtmlNavigationBar(const std::string& panel_header = "");
    
    void Begin();
    void End();
    
private:
    std::string _panel_header;
};


class axHtmlTextInput : public axHtmlElement
{
public:
    axHtmlTextInput();
    
    void Begin();
    void End();
};

class axHtmlPage
{
public:
    axHtmlPage();
    void BeginHead();
    void EndHead();
    
    
    void BeginBody();
    void EndBody();
    
    void BeginPage();
    void EndPage();
    
    void AddElement(axHtmlElement* element);
    void Clear();
    
    void Add(const std::string& item);
    
    std::string GetHtmlPage() const;
    
private:
    std::string _html_page;
    
};

#endif /* defined(__HttpServer__axHtml__) */
