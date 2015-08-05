%module(directors="1") GumtreeNet
%{
#ifndef ANDROID
#define ANDROID 1
#endif
#include "Gumtree.h"
#include "GumtreeClient.h"
#include "GTAd.h"
#include "GTAdPage.h"
#include "GTAdQuery.h"
#include "GTAdQueryRequest.h"
#include "GTAdQueryResponse.h"
%}

%define
ANDROID
%enddef



%include "std_string.i"
%include "std_map.i"
%include "std_shared_ptr.i"
%include "std_vector.i"

%template(StringMap) std::map<std::string,std::string>;
%template(StringList) std::vector<std::string>;

%shared_ptr(Gumtree::GTAd)
%shared_ptr(Gumtree::GTAdQuery)
%shared_ptr(Gumtree::GTAdQueryRequest)
%shared_ptr(Gumtree::GTAdQueryResponse)
%shared_ptr(Gumtree::GTAdPage)
%shared_ptr(Gumtree::GumtreeClient)

%nodefaultctor;
%include "GTAd.h"
%clearnodefaultctor;
%template(GTAdList) std::vector<std::shared_ptr<Gumtree::GTAd>>;


%nodefaultctor;
%include "Gumtree.h"
%include "GumtreeClient.h"
%include "GTAd.h"
%include "GTAdPage.h"
%include "GTAdQuery.h"
%include "GTAdQueryRequest.h"
%include "GTAdQueryResponse.h"
%clearnodefaultctor;

