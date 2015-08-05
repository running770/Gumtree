//
//  GTAdQueryResponse.h
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef __GumtreeNet__GTAdQueryResponse__
#define __GumtreeNet__GTAdQueryResponse__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>

namespace Gumtree {
    
    class GTAd;
    class GTAdPage;
    
    class GTAdQueryResponse {
        
    public:
        GTAdQueryResponse(){}
        ~GTAdQueryResponse(){}
    
    public:
        
#ifndef SWIG
        bool parseJson(std::istream& is);
#endif
    
    public:
        
        std::vector<std::shared_ptr<GTAd>> ads;
        
        std::shared_ptr<GTAdPage> paging;
        
        std::string jsonPayload;
    private:
        
        
        
    };
}

#endif /* defined(__GumtreeNet__GTAdQueryResponse__) */
