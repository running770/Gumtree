//
//  GTAdQueryResponse.cpp
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#include "GTAdQueryResponse.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/ParseHandler.h"
#include "Poco/JSON/JSONException.h"
#include <iostream>
#include <iomanip>
#include "GTAd.h"
#include "GTAdPage.h"
#include "Poco/StreamCopier.h"
#include "Gumtree.h"
namespace Gumtree {
    bool GTAdQueryResponse::parseJson(std::istream& is) {
        
        try {
            
            Poco::JSON::Parser parser;
            
            
            parser.parse(is);
            
            Poco::DynamicAny result = parser.result();
            
            Poco::JSON::Object::Ptr obj;
            
            if (result.type() == typeid(Poco::JSON::Object::Ptr)){
                obj = result.extract<Poco::JSON::Object::Ptr>();
                
                obj = obj->getObject("ads");
                
                if (!obj){
                    return false;
                }
                
                std::ostringstream os;
                obj->stringify(os);
                GTLog("payload %s\n\n\n", os.str().c_str());
                
                
                // Paging
                paging = std::make_shared<GTAdPage>();
                paging->parseJson(obj->getObject("paging"));
                GTLog("GTAdQueryResponse::parseJson() paging:{numFound:%d\nselfLink:%s\nselfPublicLink:%s\nnexLink:%s}\nprevLink:%s",
                       paging->numFound, paging->selfLink.c_str(), paging->selfPublicLink.c_str(),
                       paging->nextLink.c_str(), paging->prevLink.c_str());
                
                // Ads: key "ad", it maybe an Object or Array
                GTLog("\n\n");
                std::string key("ad");
                ads.clear();
                if (obj->has(key)){
                    if (obj->isObject(key)){
                        auto ad = std::make_shared<GTAd>();
                        ad->parseJson(obj->getObject(key));
                        ads.push_back(ad);
                        
                        GTLog("ad parsed: %s\n", ad->id.c_str());
                    }
                    else if (obj->isArray(key)){
                        auto adsArray = obj->getArray(key);
                        for (int i=0; i<adsArray->size(); ++i) {
                            auto ad = std::make_shared<GTAd>();
                            ad->parseJson(adsArray->getObject(i));
                            ads.push_back(ad);
                            GTLog("ad parsed: %s\n\n", ad->id.c_str());
                        }
                    }
                }
                
 
            }
            
            
            return true;
        }catch(Poco::JSON::JSONException jsone){

            GTLog("JSONException caught: %s\n", jsone.message().c_str());
        }catch (std::exception& e)
        {
            GTLog("std::exception caught: %s\n", e.what());
        }
        return false;
    }
}
