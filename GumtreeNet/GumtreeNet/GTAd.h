//
//  GTAd.h
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef __GumtreeNet__GTAd__
#define __GumtreeNet__GTAd__

#include <stdio.h>
#include <iostream>
#include "Poco/JSON/Object.h"

namespace Gumtree {
    
    struct Price {
        std::string currency;
        double      amount;
        std::string type;
    };
    
    struct Category {
        int id;
        std::string name;
    };
    
    class GTAd {
        
    public:
        GTAd() : id(""),
                 title(""),
                 description(""),
                 full_address(""),
                 longitude(0),
                 latitude(0),
                 neighborhood(""),
                 email(""),
                 phone(""),
                 rank(0),
                 ad_status(""),
                 self_public_website("")
        {
            this->price.currency = "";
            this->price.amount = 0;
            this->price.type = "N.A.";
            this->category.id = 0;
            this->category.name = "";
        }
        
        ~GTAd(){}
#ifndef SWIG
        bool parseJson(Poco::JSON::Object::Ptr obj);
#endif
    public:
        struct Price price;
        struct Category category;
        
        std::string id;
        std::string title;
        std::string description;
        
        std::string full_address;
        double longitude;
        double latitude;
        
        std::string neighborhood;
        
        std::string email;
        std::string phone;
        
        int rank;
        
        std::string ad_status;
        
        std::string self_public_website;
        
        std::vector<std::string> normalPicuteLinks;
        
    };
    
    
}
#endif /* defined(__GumtreeNet__GTAd__) */
