//
//  GTAdQuery.cpp
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#include "GTAdQuery.h"
#include "GTAdQueryRequest.h"
#include "GTAdQueryResponse.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include <Poco/Net/HTTPCredentials.h>
#include "Poco/StreamCopier.h"
#include "Poco/NullStream.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"

#include "Poco/JSON/Parser.h"
#include "Poco/JSON/ParseHandler.h"
#include "Poco/JSON/JSONException.h"
#include <iostream>
#include <iomanip>

#include <iostream>
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;

namespace Gumtree {
    
    
    int GTAdQuery::query(std::shared_ptr<GTAdQueryRequest> request, std::shared_ptr<GTAdQueryResponse> response){

        
        try
        {
            std::string urlRequest = request->toUrl();
            
            GTLog("url:%s\n", urlRequest.c_str());
            
            URI uri(urlRequest);
            std::string path(uri.getPathAndQuery());
            if (path.empty()) path = "/";
            
            HTTPClientSession session(uri.getHost(), uri.getPort());
            HTTPRequest httprequest(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
            HTTPResponse httpresponse;
            
            GTLog("GTAdQuery session created.");
            
            session.sendRequest(httprequest);
            std::istream& rs = session.receiveResponse(httpresponse);
            
            int status = httpresponse.getStatus();
            GTLog("response's status:%d", status);
            
            if (response){
                response->parseJson(rs);
            }
            
            
            
            
            
            
            
        }
        catch (Exception& exc)
        {
            GTLog("GTAdQuery Exception caught:%s\n", exc.displayText().c_str());
            return 1;
        }
        return 0;
        
    }
    

}

