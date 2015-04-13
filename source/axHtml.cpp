//
//  axHtml.cpp
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-08.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#include "axHtml.h"


axHtmlElement::axHtmlElement()
{
    
}

void axHtmlElement::Add(const std::string& item)
{
    _html_element += item;
}


void axHtmlElement::AddElement(axHtmlElement* element)
{
    _html_element += element->GetHtmlElement();
}

std::string axHtmlElement::GetHtmlElement() const
{
    return _html_element;
}

void axHtmlElement::Clear()
{
    _html_element.clear();
}




axHtmlList::axHtmlList(const std::vector<std::string>& strList)
{
    Add("<ul class=\"list-group\">");
    
    //<a href="#" class="list-group-item">Dapibus ac facilisis in</a>
    for(auto& n : strList)
    {
        Add("<a href=\"index.html\" class=\"list-group-item\">");
        //Add("<li class=\"list-group-item\">");
        //    item_str += std::string("<span class=\"badge\">") + std::to_string(badge) + "</span>";
        
        Add(n + "</a>");
//        Add(n + "</li>");
    }
    Add("</ul>");
}


axHtmlLinkList::axHtmlLinkList(const std::vector<axHtmlLinkListElement>& strList)
{
    Add("<ul class=\"list-group\">");
    
    for(auto& n : strList)
    {
        Add("<a href=\"" + n.link_address + "\" class=\"list-group-item\">");
        Add(n.name + "</a>");
    }
    Add("</ul>");
}

axHtmlPanel::axHtmlPanel(const std::string& panel_header):
_panel_header(panel_header)
{
    
}

void axHtmlPanel::Begin()
{
//    Add("<div class=\"panel panel-primary\" style=\"width:30%; height:50%; overflow-y:scroll;\">");
    Add("<div class=\"panel panel-primary\" style=\"overflow-y:scroll;\">");    
    if(!_panel_header.empty())
    {
        Add("<div class=\"panel-heading\">");
        Add("<h3 class=\"panel-title\">" + _panel_header + "</h3></div>");
        Add("<div class=\"panel-body\">");
    }
}

void axHtmlPanel::End()
{
    Add("</div></div>");
}


axHtmlNavigationBar::axHtmlNavigationBar(const std::string& panel_header):
_panel_header(panel_header)
{
    
}

void axHtmlNavigationBar::Begin()
{
    Add("<nav class=\"navbar navbar-default\"><div class=\"container-fluid\">");
    Add("<ul class=\"nav navbar-nav\">");
    
}

void axHtmlNavigationBar::End()
{
    Add("</ul></div></div>");
}


axHtmlTextInput::axHtmlTextInput()
{
    
}

void axHtmlTextInput::Begin()
{
    Add("<div class=\"input-group\">");
    Add("<span class=\"input-group-addon\" id=\"basic-addon1\">@</span>");
    Add("<input type=\"text\" class=\"form-control\" placeholder=\"Username\" aria-describedby=\"basic-addon1\">");
    
}



void axHtmlTextInput::End()
{
    Add("</div>");
}





axHtmlPage::axHtmlPage()
{
    
}
void axHtmlPage::BeginPage()
{
    Clear();
    _html_page = "<html>";
    
}

void axHtmlPage::EndPage()
{
    
}

void axHtmlPage::BeginHead()
{
    _html_page += "<head>                                                                   \
    <link rel=\"stylesheet\" type=\"text/css\" href=\"css/bootstrap.min.css\">              \
    <link rel=\"stylesheet\" type=\"text/css\" href=\"css/bootstrap-theme.min.css\">";
}

void axHtmlPage::EndHead()
{
    _html_page += "</head>";
}

void axHtmlPage::BeginBody()
{
    _html_page += "<body>";
}

void axHtmlPage::EndBody()
{
    _html_page += "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js\"></script>  \
    <script src=\"js/bootstrap.min.js\"></script></body>";
}

void axHtmlPage::Add(const std::string& item)
{
    _html_page += item;
}
//void axHtmlPage::Begin()
//{
//    Clear();
//    
//    _html_page =
//    "<html>                                                                                 \
//    <head>                                                                                  \
//    <link rel=\"stylesheet\" type=\"text/css\" href=\"css/bootstrap.min.css\">              \
//    <link rel=\"stylesheet\" type=\"text/css\" href=\"css/bootstrap-theme.min.css\">        \
//    <meta http-equiv=\"refresh\" content=\"0; url=http://example.com/\"/>                   \
//    </head>                                                                                 \
//    <body>";
//}
//
//void axHtmlPage::End()
//{
//    _html_page += "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js\"></script>  \
//    <script src=\"js/bootstrap.min.js\"></script> </body></html>";
//}

void axHtmlPage::Clear()
{
    _html_page.clear();
}

void axHtmlPage::AddElement(axHtmlElement* element)
{
    _html_page += element->GetHtmlElement();
}

std::string axHtmlPage::GetHtmlPage() const
{
    return _html_page;
}