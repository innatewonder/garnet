LOCAL_PATH := $(call my-dir)


#traverse all the directory and subdirectory
define walk
  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef

#find all the file recursively under jni/
ALLFILES = $(call walk, $(LOCAL_PATH))
FILE_LIST := $(filter %.cpp, $(ALLFILES))
FILE_LIST += $(filter %.hpp, $(ALLFILES))

# include $(CLEAR_VARS)
LOCAL_C_INCLUDES := ${shell find -L $(LOCAL_PATH)/include -type d}
LOCAL_MODULE := mythril
TARGET_PLATFORM := android-16

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_LDLIBS := -lGLESv2 -latomic -llog

include $(BUILD_SHARED_LIBRARY)
