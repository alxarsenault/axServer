//
// request_handler.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>
#include <iostream>

void $();

template <typename T, typename ...P>
void $(T t, P ...p)
{
    std::cout << t << ' ';
    {
        $(p...);
    }
}

namespace http
{
    namespace server
    {
        
        struct reply;
        struct request;
        
        /// The common handler for all incoming requests.
        class request_handler
        {
        public:
            request_handler(const request_handler&) = delete;
            request_handler& operator=(const request_handler&) = delete;
            
            /// Construct with a directory containing files to be served.
            explicit request_handler(const std::string& doc_root);
            
            /// Handle a request and produce a reply.
            virtual void handle_request(const request& req, reply& rep);
            
            virtual void RequestCallback(const std::string& url,
                                         const request& req,
                                         reply& rep);
            
            void SetRequestHandlerCallback(const std::function<void(request_handler& handler, const request& req, reply& rep)>& callback);
            
            std::string GetFileExtension(const std::string& path);
            
            
            inline std::string GetDocRoot() const
            {
                return doc_root_;
            }
            
        protected:
            /// Perform URL-decoding on a string. Returns false if the encoding was
            /// invalid.
            static bool url_decode(const std::string& in, std::string& out);
            
            
        
            /// The directory containing the files to be served.
            std::string doc_root_;
        };
        
    } // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP