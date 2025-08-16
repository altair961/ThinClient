#include <android_native_app_glue.h>
#include <android/log.h>

#define LOG_TAG "NativeApp"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

void handle_cmd(android_app* app, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            LOGI("App initialized, window ready");
            // Initialize rendering here
            break;
        case APP_CMD_TERM_WINDOW:
            LOGI("Window terminated");
            // Cleanup rendering here
            break;
    }
}

void android_main(android_app* state) {
    state->onAppCmd = handle_cmd;

    android_poll_source* source;
    while (true) {
        // Process events with -1 (blocking) timeout
        while (ALooper_pollAll(0, nullptr, nullptr, (void**)&source) >= 0) {
            if (source) source->process(state, source);
            if (state->destroyRequested) return;
        }

        // Main render loop here
    }
}