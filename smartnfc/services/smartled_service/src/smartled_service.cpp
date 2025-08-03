#include "SmartLedService.h"
#include <android/binder_manager.h>
#include <android/binder_process.h>

using aidl::smartnfc::hardware::led::SmartLedService;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<SmartLedService> service = ndk::SharedRefBase::make<SmartLedService>();

    const std::string instance = std::string() + SmartLedService::descriptor + "/default";
    binder_status_t status = AServiceManager_addService(service->asBinder().get(), instance.c_str());
    if (status != STATUS_OK) {
        return EXIT_FAILURE;
    }

    ABinderProcess_joinThreadPool();
    return EXIT_SUCCESS;
}
