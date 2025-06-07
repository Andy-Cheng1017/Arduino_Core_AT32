#pragma once
#define ARDUINO_ARCH_AT32 1

#include "ArduinoAPI.h"    // 來自 submodule
// #include "pins_arduino.h"      // 由 variant 供應

#ifdef __cplusplus
extern "C" {
#endif
void init(void);               // 若需要 core 初始化 (at32-time.c 可實作)
#ifdef __cplusplus
}
#endif
