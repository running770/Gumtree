//
//  GTAdPage.h
//  GumtreeNet
//
//  Created by Justin Liu on 3/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef __GumtreeNet__GTAdPage__
#define __GumtreeNet__GTAdPage__

#include <stdio.h>
#include <iostream>

#include "Poco/JSON/Object.h"

namespace Gumtree {
    class GTAdPage {
    public:
        GTAdPage(){}
        ~GTAdPage(){}
        
#ifndef SWIG
        bool parseJson(Poco::JSON::Object::Ptr obj);
#endif
    public:
        
        int     numFound;
        
        std::string nextLink;
        std::string prevLink;
        std::string selfLink;
        std::string selfPublicLink;
        
    };
}


#endif /* defined(__GumtreeNet__GTAdPage__) */
