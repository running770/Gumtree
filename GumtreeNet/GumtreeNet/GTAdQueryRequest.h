//
//  GTAdQueryRequest.h
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef __GumtreeNet__GTAdQueryRequest__
#define __GumtreeNet__GTAdQueryRequest__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "Gumtree.h"
/*
 * Parameters from email.
 Accepted parameters:
 • q, the search keyword
 • size, number of ads return in each call
 • page, page number, start from 0
 • minPrice, minimum price
 • maxPrice, maximum price
 • sortType (DATE_DESCENDING | PRICE_ASCENDING | PRICE_DESCENDING |
 DISTANCE_ASCENDING)
 • pictureRequired (true | false), only return ads having pictures
 */

namespace Gumtree {
    class GTAdQueryRequest {
    public:
        GTAdQueryRequest(){
            setBaseUrl("http://profile.gumtree.sg/api/ads");
        }
        
        GTAdQueryRequest(std::string baseUrl){
            setBaseUrl(baseUrl);
        }
        
        ~GTAdQueryRequest(){}
        
    public:
        static std::string KeyQ;          // json: q
        static std::string KeySize;       // json: size default: 20
        static std::string KeyPage;       // json: page default: 0
        static std::string KeyPriceCurrency; // json:priceCurrency  default: SGD
        static std::string KeyMinPrice;   // json: minPrice
        static std::string KeyMaxPrice;   // json: maxPrice
        static std::string KeySortType;   // json: sortType
        static std::string KeyPictureRequired; // json: pictureRequired default: false
        static std::string KeyIncludeTopAds;   // json: includeTopAds default: false
        
    public:
        
        void setBaseUrl(std::string url) {
            _baseUrl = url;
        }
        std::string baseUrl() const {
            return _baseUrl;
        }
        
        
        void setQ(std::string keyword){
            _params[KeyQ] = keyword;
        }
        std::string q() const{
            auto it = _params.find(KeyQ);
            if (it != _params.end()){
                return it->second;
            }
            return "";
        }
        
        void setSize(int size) {
            _params[KeySize] = to_string(size);
        }
        int size() {
            auto it = _params.find(KeySize);
            if (it != _params.end()){
                auto s = it->second;
                return atoi(s.c_str());
            }
            return 0;
        }
        
        void setPage(int page) {
            _params[KeyPage] = to_string(page);
        }
        int page() {
            auto it = _params.find(KeyPage);
            if (it != _params.end()){
                auto s = it->second;
                return atoi(s.c_str());
            }
            return 0;
        }
        
        void setPriceCurrency(std::string currency) {
            _params[KeyPriceCurrency] = currency;
        }
        std::string priceCurrency() {
            auto it = _params.find(KeyPriceCurrency);
            if (it != _params.end()){
                return it->second;
            }
            return "";
        }
        
        void setMinPrice(int price) {
            _params[KeyMinPrice] = to_string(price);
        }
        int minPrice() {
            auto it = _params.find(KeyMinPrice);
            if (it != _params.end()){
                auto s = it->second;
                return atoi(s.c_str());
            }
            return 0;
        }
        void setMaxPrice(int price) {
            _params[KeyMaxPrice] = to_string(price);
        }
        int maxPrice() {
            auto it = _params.find(KeyMaxPrice);
            if (it != _params.end()){
                auto s = it->second;
                return atoi(s.c_str());
            }
            return 0;
        }
        
        void setSortType(std::string type) {
            _params[KeySortType] = type;
        }
        std::string sortType() {
            auto it = _params.find(KeySortType);
            if (it != _params.end()){
                return it->second;
            }
            return "";
        }
        
        
        void setPictureRequired(bool required) {
            _params[KeyPictureRequired] = to_string((int)required);
        }
        bool pictureRequired() {
            auto it = _params.find(KeyPictureRequired);
            
            if (it != _params.end()){
                std::string s = it->second;
                
                return (0 != atoi(s.c_str()));
            }
            
            return false;
        }
        
        void setIncludeTopAds(bool included) {
            _params[KeyIncludeTopAds] = to_string((int)included);
        }
        bool includeTopAds() {
            auto it = _params.find(KeyIncludeTopAds);
            
            if (it != _params.end()){
                std::string s = it->second;
                
                return (0 != atoi(s.c_str()));
            }
            
            return false;
        }
        
    public:
        std::shared_ptr<GTAdQueryRequest> requestForNextPage() const;
        std::shared_ptr<GTAdQueryRequest> requestForPrevPage() const;
        
    public:
        
        std::string toUrl() const;
        
        
        
    public:
        std::string _baseUrl;
        std::map<std::string,std::string> _params;
    };
}

#endif /* defined(__GumtreeNet__GTAdQueryRequest__) */
