//
//  GTAdQuery.h
//  GumtreeNet
//
//  Created by Justin Liu on 2/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef __GumtreeNet__GTAdQuery__
#define __GumtreeNet__GTAdQuery__

#include <stdio.h>
#include <map>
#include <vector>
#include <memory>


namespace Gumtree {
    
    class GTAdQueryRequest;
    class GTAdQueryResponse;
    
    class GTAdQuery {
    public:
        GTAdQuery(){}
        ~GTAdQuery(){}
        
        
    public:
        
        int query(std::shared_ptr<GTAdQueryRequest> request, std::shared_ptr<GTAdQueryResponse> response);
        
    private:
       
        
    private:
        
        std::shared_ptr<GTAdQueryRequest> _currRequest;
        std::shared_ptr<GTAdQueryResponse> _currResponse;
        
        std::vector<std::shared_ptr<GTAdQueryRequest>> _requests;
        std::map<std::shared_ptr<GTAdQueryRequest>, std::shared_ptr<GTAdQueryResponse>> _responses;
        
        
    };
}

#endif /* defined(__GumtreeNet__GTAdQuery__) */
