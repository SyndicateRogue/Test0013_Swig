# File: Android.mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := swigtest
LOCAL_SRC_FILES := swigtest.cpp swigtest_jni.cpp
LOCAL_CFLAGS    := -frtti

include $(BUILD_SHARED_LIBRARY)
