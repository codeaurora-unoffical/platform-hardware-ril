
RIL_DIR := $(call my-dir)
include $(CLEAR_VARS)

#
# Make the decision based on target build
# Select the source files for ril
#
ifeq ($(BUILD_FUSION), true)
     include $(RIL_DIR)/ril_fusion/libril/Android.mk
     include $(RIL_DIR)/ril_fusion/reference-cdma-sms/Android.mk
     include $(RIL_DIR)/ril_fusion/reference-ril/Android.mk
     include $(RIL_DIR)/ril_fusion/rild/Android.mk
else
    include $(RIL_DIR)/ril_original/libril/Android.mk
    include $(RIL_DIR)/ril_original/reference-cdma-sms/Android.mk
    include $(RIL_DIR)/ril_original/reference-ril/Android.mk
    include $(RIL_DIR)/ril_original/rild/Android.mk
endif


