#include "SmartLedService.h"
#include <android-base/logging.h>
#include <fstream>

namespace aidl::smartnfc::hardware::led {

ndk::ScopedAStatus SmartLedService::setLedState(const std::string& ledName, int state) {
    std::string path = "/sys/class/leds/" + ledName + "/brightness";
    std::ofstream file(path);
    if (!file.is_open()) {
        return ndk::ScopedAStatus::fromServiceSpecificError(-1);
    }
    file << (state ? "1" : "0");
    file.close();
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus SmartLedService::getLedState(const std::string& ledName, int* _aidl_return) {
    std::string path = "/sys/class/leds/" + ledName + "/brightness";
    std::ifstream file(path);
    if (!file.is_open()) {
        *_aidl_return = -1;
        return ndk::ScopedAStatus::fromServiceSpecificError(-1);
    }
    file >> *_aidl_return;
    return ndk::ScopedAStatus::ok();
}

}  // namespace aidl::android::hardware::smartnfc
