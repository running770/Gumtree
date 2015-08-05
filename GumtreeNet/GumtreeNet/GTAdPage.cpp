//
//  GTAdPage.cpp
//  GumtreeNet
//
//  Created by Justin Liu on 3/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#include "GTAdPage.h"
#include "Poco/JSON/JSONException.h"
#include "Gumtree.h"
namespace Gumtree {
    /**
     paging: {
     numFound: {
     value: "409630"
     },
     link: [
     {
     rel: "self",
     href: "http://ecg-api.gumtree.sg/api/ads?pictureRequired=false&includeTopAds=false&priceCurrency=SGD&page=0&size=1&_ver=1.19"
     },
     {
     rel: "self-public-website",
     href: "http://www.gumtree.sg/s-all-the-ads/v1b0p1"
     },
     {
     rel: "next",
     href: "http://ecg-api.gumtree.sg/api/ads?pictureRequired=false&includeTopAds=false&priceCurrency=SGD&page=1&size=1&_ver=1.19"
     }
     ]
     },
     */
    bool GTAdPage::parseJson(Poco::JSON::Object::Ptr obj) {
        
        try {
            
            auto numObj = obj->getObject("numFound");
            this->numFound = numObj->getValue<int>("value");
            
            
            auto linkArr = obj->getArray("link");
            
            for (int i=0; i<linkArr->size(); ++i) {
                auto linkObj = linkArr->getObject(i);
                auto rel = linkObj->getValue<std::string>("rel");
                auto href = linkObj->getValue<std::string>("href");
                
                if (0 == rel.compare("self")){
                    this->selfLink = href;
                }
                else if (0 == rel.compare("self-public-website")){
                    this->selfPublicLink = href;
                }
                else if (0 == rel.compare("next")){
                    this->nextLink = href;
                }
                else if (0 == rel.compare("prev")){
                    this->prevLink = href;
                }
                
            }
            
            return true;
        }catch(Poco::JSON::JSONException jsone){
        
            GTLog("JSONException caught: %s\n", jsone.message().c_str());
        }catch (std::exception& e)
        {
            GTLog("exception caught: %s\n", e.what());
        }
        
        
        
        return false;
    }
}
