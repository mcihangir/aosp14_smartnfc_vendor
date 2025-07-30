// File: SmartLedService.h
// Description: AIDL-based service implementation header for controlling LEDs.

#pragma once

#include <aidl/android/hardware/smartnfc/BnSmartLed.h>

namespace aidl::android::hardware::smartnfc {

class SmartLedService : public BnSmartLed {
public:
    SmartLedService() = default;
    ~SmartLedService() override = default;

    // Implements AIDL interface methods
    ndk::ScopedAStatus setLedState(const std::string& ledName, int state) override;
    ndk::ScopedAStatus getLedState(const std::string& ledName, int* _aidl_return) override;
};

}  // namespace aidl::android::hardware::smartnfc
