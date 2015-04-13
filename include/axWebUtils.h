//
//  axWebUtils.h
//  HttpServer
//
//  Created by Alexandre Arsenault on 2015-04-08.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#ifndef HttpServer_axWebUtils_h
#define HttpServer_axWebUtils_h

#include <string>
#include <vector>

#include <boost/asio.hpp>

namespace http
{
    namespace server
    {
        
        struct header
        {
            std::string name;
            std::string value;
        };
        
        
        namespace mime_types
        {
            
            /// Convert a file extension into a MIME type.
            std::string extension_to_type(const std::string& extension);
            
        } // namespace mime_types
        
        
        /// A request received from a client.
        struct request
        {
            std::string method;
            std::string uri;
            int http_version_major;
            int http_version_minor;
            std::vector<header> headers;
        };
        
        /// A reply to be sent to a client.
        struct reply
        {
            /// The status of the reply.
            enum status_type
            {
                ok = 200,
                created = 201,
                accepted = 202,
                no_content = 204,
                multiple_choices = 300,
                moved_permanently = 301,
                moved_temporarily = 302,
                not_modified = 304,
                bad_request = 400,
                unauthorized = 401,
                forbidden = 403,
                not_found = 404,
                internal_server_error = 500,
                not_implemented = 501,
                bad_gateway = 502,
                service_unavailable = 503
            } status;
            
            /// The headers to be included in the reply.
            std::vector<header> headers;
            
            /// The content to be sent in the reply.
            std::string content;
            
            /// Convert the reply into a vector of buffers. The buffers do not own the
            /// underlying memory blocks, therefore the reply object must remain valid and
            /// not be changed until the write operation has completed.
            std::vector<boost::asio::const_buffer> to_buffers();
            
            /// Get a stock reply.
            static reply stock_reply(status_type status);
            
            void Setup(const status_type& status,
                       const std::string& page_content,
                       const std::string& type);
        };
        
    } // namespace server
} // namespace http

#endif
