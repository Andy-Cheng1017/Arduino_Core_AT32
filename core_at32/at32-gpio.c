#include "Arduino.h"
#include "at32_device.h"

void pinMode(pin_size_t pin, PinMode mode)
{
    GPIO_Type* port = digitalPinToPort(pin);
    uint16_t   bit  = 1U << digitalPinToBit(pin);

    gpio_init_type cfg = {
        .gpio_pins  = bit,
        .gpio_mode  = (mode == INPUT) ? GPIO_MODE_INPUT : GPIO_MODE_OUTPUT,
        .gpio_out_type = GPIO_OUTPUT_PUSH_PULL,
        .gpio_pull = GPIO_PULL_NONE,
        .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONG
    };
    gpio_init(port, &cfg);
}

void digitalWrite(pin_size_t pin, PinStatus val)
{
    GPIO_Type* port = digitalPinToPort(pin);
    uint16_t   bit  = 1U << digitalPinToBit(pin);

    if (val)
        gpio_bits_set(port, bit);    
    else
        gpio_bits_reset(port, bit);    
}

PinStatus digitalRead(pin_size_t pin)
{
    GPIO_Type* port = digitalPinToPort(pin);
    uint16_t   bit  = 1U << digitalPinToBit(pin);
    return (port->idt & bit) ? HIGH : LOW;
}
