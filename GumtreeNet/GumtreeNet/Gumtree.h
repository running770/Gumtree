//
//  Gumtree.h
//  GumtreeNet
//
//  Created by Justin Liu on 3/8/15.
//  Copyright (c) 2015 Justin Liu. All rights reserved.
//

#ifndef GumtreeNet_Gumtree_h
#define GumtreeNet_Gumtree_h


#include <iostream>
#include <memory>
#include <sstream>


#ifdef ANDROID
#include <android/log.h>
#define GTLog(frmt,...) __android_log_print(ANDROID_LOG_DEBUG, "Gumtree", "[Gumtree]%s() " frmt, __FUNCTION__, ##__VA_ARGS__)
#else
#define GTLog(frmt,...) printf("[Gumtree]%s() " frmt, __FUNCTION__, ##__VA_ARGS__)
#endif


namespace Gumtree {
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os ;
        os << value ;
        return os.str() ;
    }
}


#endif
