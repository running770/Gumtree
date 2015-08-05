//
//  GTAdQueryRequest.cpp
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#include "GTAdQueryRequest.h"

#include <sstream>

namespace Gumtree {
    /*
     ads-search-options: {
     q: {
     value: "hello"
     },
     priceCurrency: {
     value: "SGD"
     },
     minPrice: {
     value: "10"
     },
     maxPrice: {
     value: "100"
     },
     page: {
     value: "1"
     },
     size: {
     value: "1"
     },
     pictureRequired: {
     _: {
     value: "false"
     },
     default: ""
     },
     includeTopAds: {
     _: {
     value: "false"
     },
     default: ""
     }
     },
     */
    std::string GTAdQueryRequest::KeyQ = "q";
    std::string GTAdQueryRequest::KeySize = "size";
    std::string GTAdQueryRequest::KeyPage = "page";
    std::string GTAdQueryRequest::KeyPriceCurrency = "priceCurrency";
    std::string GTAdQueryRequest::KeyMinPrice = "minPrice";
    std::string GTAdQueryRequest::KeyMaxPrice = "maxPrice";
    std::string GTAdQueryRequest::KeySortType = "sortType";
    std::string GTAdQueryRequest::KeyPictureRequired = "pictureRequired";
    std::string GTAdQueryRequest::KeyIncludeTopAds = "includeTopAds";
    
    
    std::string GTAdQueryRequest::toUrl() const {
        
        std::stringstream ss;
        
        ss << baseUrl();
        
        if (_params.size() > 0){
            auto it = _params.begin();
            ss << "?" << it->first << "=" << it->second;
        }
        
        for (auto it=_params.begin(); it != _params.end(); ++it) {
            
            if (it == _params.begin()){
                continue;
            }
            
            ss << "&" << it->first << "=" << it->second;
        }
        
        return ss.str();
        
    }
    
    std::shared_ptr<GTAdQueryRequest> GTAdQueryRequest::requestForNextPage() const {
        
        auto req = std::make_shared<GTAdQueryRequest>(_baseUrl);
        
        req->_params = _params;
        
        req->setPage(req->page() + 1);
        
        return req;
    }
    
    std::shared_ptr<GTAdQueryRequest> GTAdQueryRequest::requestForPrevPage() const {
        auto req = std::make_shared<GTAdQueryRequest>(_baseUrl);
        
        req->_params = _params;
        
        req->setPage(req->page() - 1);
        
        return req;
    }
    
}

