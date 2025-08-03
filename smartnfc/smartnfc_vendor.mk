# smartnfc_vendor.mk
# Included from device/qcom/bengal/bengal.mk

LOCAL_PATH := $(call my-dir)
include $(call all-subdir-makefiles)

# Include package removal definitions
#include vendor/empa/smartnfc/smartnfc_remove_packages.mk

PRODUCT_SOONG_NAMESPACES += \
    vendor/empa/smartnfc \
    vendor/empa/smartnfc/interfaces/smartnfc/hardware/led

# Add SELinux policy directory
BOARD_SEPOLICY_DIRS += vendor/empa/smartnfc/sepolicy

# Copy init scripts
PRODUCT_COPY_FILES += \
    vendor/empa/smartnfc/init.smartnfc.rc:vendor/etc/init/init.smartnfc.rc \
    vendor/empa/smartnfc/services/smartled_service/smartled_service.rc:vendor/etc/init/smartled_service.rc

# Add our custom binary to the build
PRODUCT_PACKAGES += \
    smartnfc.hardware.led \
    smartled_service 
