
APP_ABI := armeabi-v7a


APP_PLATFORM := android-14

NDK_TOOLCHAIN_VERSION		:= 4.8
# Enable C++11.
APP_CPPFLAGS				+= -std=c++11 -fexceptions -frtti
APP_CPPFLAGS				+= -pthread
APP_STL 					:= gnustl_static
#APP_STL						:= c++_static

#LOCAL_C_INCLUDES 			+= ${ANDROID_NDK}/sources/cxx-stl/gnu-libstdc++/4.8/include

# Predefinition
# Print all warning messages
APP_CPPFLAGS				+= -Wformat
# Print command information
#APP_CPPFLAGS				+= -v

#LDFLAGS
APP_LDFLAGS					+= -latomic -llog