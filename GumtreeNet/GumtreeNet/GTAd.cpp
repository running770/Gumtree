//
//  GTAd.cpp
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#include "GTAd.h"
#include "Poco/JSON/JSONException.h"
#include "Gumtree.h"
namespace Gumtree {
    
    /**
     "ad": {
     "ad-address": {
     "full-address": {
     "value": "190 Changi Road, B1-01 Singapore 419974"
     },
     "latitude": "",
     "longitude": ""
     },
     "ad-guid": "",
     "ad-status": {
     "value": {
     "value": "ACTIVE"
     }
     },
     "attributes": {
     "attribute": [
     {
     "localized-label": "Name",
     "name": "UserName",
     "search-value": {
     "value": "MS CHEW"
     },
     "type": "STRING",
     "value": {
     "value": "MS CHEW"
     }
     },
     {
     "localized-label": "Condition",
     "name": "ItemCondition",
     "search-value": {
     "value": "new"
     },
     "type": "ENUM",
     "value": {
     "_": {
     "value": "new"
     },
     "localized-label": "New"
     }
     }
     ]
     },
     "category": {
     "id": "111",
     "id-name": {
     "value": "Tables"
     },
     "localized-name": {
     "value": "Tables"
     }
     },
     "creation-date-time": {
     "value": "2015-08-03T03:39:32.000Z"
     },
     "description": {
     "value": "<p>DESIGNER COFFEE TABLE (1 PIECE)</p><p>PRICE: $180/- PER PIECE</p><p>SELF COLLECTION</p><p>COD</p><p><br /></p><p>EMAIL TO : patientcare@noocc.com</p><p>CALL : 93801991<br /></p>"
     },
     "email": {
     "value": "patientcare@noocc.com"
     },
     "end-date-time": {
     "value": "2015-11-01T03:40:04.057Z"
     },
     "id": "138276705",
     "imprint": "",
     "link": [
     {
     "href": "http://ecg-api.gumtree.sg/api/ads/138276705",
     "rel": "self"
     },
     {
     "href": "http://ecg-api.gumtree.sg/api/users/106776688/ads/138276705",
     "rel": "self-user"
     },
     {
     "href": "http://www.gumtree.sg/a-tables/d14-+-eunos-geylang-paya-lebar/designer-coffee-table/1001382767050910677668809",
     "rel": "self-public-website"
     }
     ],
     "locations": {
     "location": {
     "id": "2800020",
     "id-name": {
     "value": "Eunos Geylang Paya Lebar"
     },
     "latitude": {
     "value": "1.342269"
     },
     "localized-name": {
     "value": "D14 - Eunos / Geylang / Paya Lebar"
     },
     "longitude": {
     "value": "103.910065"
     }
     }
     },
     "miscategorized-flag-count": "",
     "modification-date-time": {
     "value": "2015-08-03T03:40:04.090Z"
     },
     "neighborhood": {
     "value": "D14 - Eunos / Geylang / Paya Lebar"
     },
     "phone": {
     "value": "64711771"
     },
     "phone-click-count": "",
     "pictures": {
     "picture": {
     "link": [
     {
     "href": "http://i.ebayimg.com/00/s/NTUwWDgwMA==/z/7ToAAOSwjVVVvuIn/$_14.JPG",
     "rel": "thumbnail"
     },
     {
     "href": "http://i.ebayimg.com/00/s/NTUwWDgwMA==/z/7ToAAOSwjVVVvuIn/$_20.JPG",
     "rel": "extraLarge"
     },
     {
     "href": "http://i.ebayimg.com/00/s/NTUwWDgwMA==/z/7ToAAOSwjVVVvuIn/$_19.JPG",
     "rel": "large"
     },
     {
     "href": "http://i.ebayimg.com/00/s/NTUwWDgwMA==/z/7ToAAOSwjVVVvuIn/$_18.JPG",
     "rel": "normal"
     },
     {
     "href": "http://i.ebayimg.com/00/s/NTUwWDgwMA==/z/7ToAAOSwjVVVvuIn/$_18.JPG",
     "rel": "teaser"
     }
     ]
     }
     },
     "poster-ip-address": {
     "value": "180.129.14.55"
     },
     "poster-machine-id": {
     "value": "9744664f-e053-49b7-b325-f5ea60578c95-14ef18866ee"
     },
     "price": {
     "amount": "",
     "currency-iso-code": "",
     "price-type": {
     "value": {
     "value": "PLEASE_CONTACT"
     }
     }
     },
     "prohibited-flag-count": "",
     "rank": {
     "value": "1"
     },
     "replyTemplate": {
     "value": "default"
     },
     "spam-flag-count": "",
     "start-date-time": {
     "value": "2015-08-03T03:40:04.057Z"
     },
     "title": {
     "value": "DESIGNER COFFEE TABLE"
     },
     "user-id": {
     "value": "106776688"
     },
     "view-ad-count": ""
     },
     */
    bool GTAd::parseJson(Poco::JSON::Object::Ptr obj) {
     
     
        try {
            
     
            this->id = obj->getValue<std::string>("id");
            
            if (obj->isObject("title")){
                this->title = obj->getObject("title")->optValue("value", std::string(""));
            }
            GTLog("title: %s\n", this->title.c_str());
            
            if (obj->isObject("description")){
                this->description = obj->getObject("description")->optValue("value", std::string(""));
            }
            
            /**
             price: {
             currency-iso-code: {
             value: {
             _: {
             value: "SGD"
             },
             localized-label: "SGD"
             }
             },
             amount: {
             value: "950"
             },
             price-type: {
             value: {
             value: "SPECIFIED_AMOUNT"
             }
             }
             },
             */
            auto priceObj = obj->getObject("price");
            if (priceObj){
                try {
                    auto currencyObj = priceObj->getObject("currency-iso-code");
                    if (currencyObj){
                        this->price.currency = currencyObj->getObject("value")->getObject("_")->getValue<std::string>("value");
                    }
                    auto amountObj = priceObj->getObject("amount");
                    if (amountObj){
                        this->price.amount = amountObj->getValue<double>("value");
                    }
                    
                    this->price.type = priceObj->getObject("price-type")->getObject("value")->getValue<std::string>("value");
                }catch(Poco::JSON::JSONException jsone){
                    
                }
                GTLog("Price: %s %f %s", price.currency.c_str(), price.amount, price.type.c_str());
            }
            
            
            
            auto addressObj = obj->getObject("ad-address");
            if (addressObj){
                //std::cout << "GTAd::parseJson() addressObj:";
                //addressObj->stringify(std::cout);
                //std::cout << std::endl;
                
                if (addressObj->isObject("full-address")){
                    this->full_address = addressObj->getObject("full-address")->getValue<std::string>("value");
                }
                else {
                    this->full_address = "";
                }
                
                if (addressObj->isObject("longitude")){
                    this->longitude = addressObj->getObject("longitude")->optValue("value", 0.0);
                }
                else {
                    this->longitude = 0.0;
                }
                
                
                if (addressObj->isObject("latitude")){
                    this->latitude = addressObj->getObject("latitude")->optValue("value", 0.0);
                }
                else {
                    this->latitude = 0.0;
                }
            }
            GTLog("ad-address parsed. full-address:%s longitude:%f latitude:%f\n",
                   this->full_address.c_str(), this->longitude, this->latitude);
            
            
            this->neighborhood = obj->getObject("neighborhood")->optValue("value", std::string(""));
            GTLog("neighborhood: %s\n", this->neighborhood.c_str());
            
            this->email = obj->getObject("email")->getValue<std::string>("value");
            GTLog("emal: %s\n", this->email.c_str());
            
            if (obj->isObject("phone")){
                this->phone = obj->getObject("phone")->getValue<std::string>("value");
            }
            GTLog("phone: %s\n", this->phone.c_str());
            
            if (obj->isObject("rank")){
                this->rank = obj->getObject("rank")->optValue("value", 0);
            }
            
            GTLog("rank: %d\n", this->rank);
            
            this->ad_status = obj->getObject("ad-status")->getObject("value")->getValue<std::string>("value");
            GTLog("ad-status: %s\n", this->ad_status.c_str());
            
            
            auto linkArr = obj->getArray("link");
            for (int i=0; i<linkArr->size(); ++i) {
                auto linkObj = linkArr->getObject(i);
                auto rel = linkObj->getValue<std::string>("rel");
                auto href = linkObj->getValue<std::string>("href");
                
                if (0 == rel.compare("self-public-website")){
                    this->self_public_website = href;
                    break;
                }
                
                
            }
            GTLog("self-public-website: %s", this->self_public_website.c_str());
            
            auto picturesObj = obj->getObject("pictures");
            if (picturesObj){
                
                auto searchNormalLink = [=](Poco::JSON::Array::Ptr linkArr){
                    for (int i=0; i<linkArr->size(); ++i) {
                        auto linkObj = linkArr->getObject(i);
                        auto rel = linkObj->getValue<std::string>("rel");
                        auto href = linkObj->getValue<std::string>("href");
                        
                        if (0 == rel.compare("normal")){
                            normalPicuteLinks.push_back(href);
                    
                            GTLog("picture: %s\n", href.c_str());
                            break;
                        }
                        
                    }
                };
                
                
                if (picturesObj->isObject("picture")){
                    auto picLinkArr = picturesObj->getObject("picture")->getArray("link");
                    searchNormalLink(picLinkArr);
                }
                else if (picturesObj->isArray("picture")){
                    auto pictureArr = picturesObj->getArray("picture");
                    for (int i=0; i<pictureArr->size(); ++i) {
                        
                        auto picLinkArr = pictureArr->getObject(i)->getArray("link");
                        searchNormalLink(picLinkArr);
                    }
                    
                }
            }
            GTLog("normalPictureLinks size:%d\n", (int)this->normalPicuteLinks.size());
            
            
            auto catObj = obj->getObject("category");
            if (catObj){
                this->category.id = catObj->getValue<int>("id");
                this->category.name = catObj->getObject("id-name")->optValue("value", std::string(""));
            }
            
            GTLog("category: %d %s", category.id, category.name.c_str());
            
            return true;
        }catch(Poco::JSON::JSONException jsone){
            GTLog("JSONException caught:%s\n", jsone.message().c_str());
        }catch (std::exception& e)
        {
            
            GTLog("exception caught: %s\n", e.what());
        }
        
        
        return false;
    }
}
