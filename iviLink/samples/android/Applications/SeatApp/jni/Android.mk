
LOCAL_PATH := $(call my-dir)

LINUX_PATHS         := $(shell find $(LOCAL_PATH)/../../../../linux/ -type d)
ROOT_PATH           := $(LOCAL_PATH)/../../../../..
LINUX_DIR           := $(ROOT_PATH)/samples/linux
UTILS_INCL          := $(shell find $(ROOT_PATH)/framework/utils/ -type d)
APP_LIB             := $(shell find $(ROOT_PATH)/iviLink/include/ -type d)
INTERNAL_APP_LIB    := $(shell find $(ROOT_PATH)/framework/libraries/ApplicationLibrary/ -type d)
JSON_PATH           := $(shell find $(ROOT_PATH)/3rd_party/json/ -type d)


include $(CLEAR_VARS)
LOCAL_MODULE := seatclient
LOCAL_SHARED_LIBRARIES := iviLinkApplicationLibraryShared  SeatState
LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/src/*.cpp)
LOCAL_SRC_FILES += $(wildcard $(LINUX_DIR)/applications/Seat_App/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)
LOCAL_C_INCLUDES += $(LINUX_PATHS)
LOCAL_C_INCLUDES += $(UTILS_INCL)
LOCAL_C_INCLUDES += $(APP_LIB)
LOCAL_C_INCLUDES += $(INTERNAL_APP_LIB)
LOCAL_C_INCLUDES += $(JSON_PATH)
LOCAL_LDLIBS += -llog
LOCAL_CFLAGS := -DANDROID -Wno-psabi
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := SeatSenderProfile
LOCAL_SHARED_LIBRARIES := iviLinkApplicationLibraryShared  SeatState
LOCAL_SRC_FILES += $(wildcard $(LINUX_DIR)/profiles/SeatSenderProfile/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)
LOCAL_C_INCLUDES += $(LINUX_PATHS)
LOCAL_C_INCLUDES += $(UTILS_INCL)
LOCAL_C_INCLUDES += $(APP_LIB)
LOCAL_C_INCLUDES += $(JSON_PATH)
LOCAL_LDLIBS += -llog
LOCAL_CFLAGS := -DANDROID
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := SeatReceiverProfile
LOCAL_SHARED_LIBRARIES := iviLinkApplicationLibraryShared  SeatState
LOCAL_SRC_FILES += $(wildcard $(LINUX_DIR)/profiles/SeatReceiverProfile/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)
LOCAL_C_INCLUDES += $(LINUX_PATHS)
LOCAL_C_INCLUDES += $(UTILS_INCL)
LOCAL_C_INCLUDES += $(APP_LIB)
LOCAL_C_INCLUDES += $(JSON_PATH)
LOCAL_LDLIBS += -llog
LOCAL_CFLAGS := -DANDROID
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := SeatState
LOCAL_SHARED_LIBRARIES := iviLinkApplicationLibraryShared
LOCAL_SRC_FILES += $(wildcard $(LINUX_DIR)/profiles/States/Seat/*.cpp)
LOCAL_SRC_FILES += $(wildcard $(ROOT_PATH)/3rd_party/json/src/lib_json/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)
LOCAL_C_INCLUDES += $(LINUX_PATHS)
LOCAL_C_INCLUDES += $(UTILS_INCL)
LOCAL_C_INCLUDES += $(APP_LIB)
LOCAL_C_INCLUDES += $(JSON_PATH)
LOCAL_LDLIBS += -llog
LOCAL_CFLAGS := -DANDROID
include $(BUILD_SHARED_LIBRARY)

include $(LOCAL_PATH)/../../Android.mk
