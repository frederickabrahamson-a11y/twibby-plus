// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// Board definition for Adafruit Feather RP2040 with USB Type-A Host
// https://learn.adafruit.com/adafruit-feather-rp2040-with-usb-type-a-host/pinouts

#ifndef _BOARDS_ADAFRUIT_FEATHER_RP2040_USB_HOST_H
#define _BOARDS_ADAFRUIT_FEATHER_RP2040_USB_HOST_H

// --- LED ---
// The red LED (D13) is on GPIO 13
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN 13
#endif

// --- UART ---
// Defaults to UART0 on GPIO 0 (TX) and GPIO 1 (RX)
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// --- PIO-USB HOST ---
// USB Host D+ = GPIO16, D- = GPIO17
#define PICO_DEFAULT_PIO_USB_DP_PIN 16
// 5V power enabling pin for USB-A port
#define PICO_USB_HOST_POWER_PIN 18

// --- INTERNAL PINS ---
// NeoPixel data = 21, NeoPixel power = 20
#define PICO_DEFAULT_WS2812_PIN 21
#define PICO_DEFAULT_WS2812_POWER_PIN 20

// BOOT button = 7
#define PICO_DEFAULT_BOOT_BUTTON_PIN 7

// --- GPIO MASK ---
// Exclude internal/special pins from the remapper's general GPIO pool
// Pins excluded: 7 (BOOT), 13 (LED), 16,17 (USB), 18 (5V_EN), 20,21 (NeoPixel)
// In addition to UART 0,1 (managed in remapper_single.cc)
#define GPIO_VALID_PINS_BASE ( \
    (1u << 0)  | (1u << 1)  | (1u << 2)  | (1u << 3)  | \
    (1u << 4)  | (1u << 5)  | (1u << 6)  |               \
    (1u << 8)  | (1u << 9)  | (1u << 10) | (1u << 11) | \
    (1u << 12) |              (1u << 14) | (1u << 15) | \
    (1u << 24) | (1u << 25) | (1u << 26) | (1u << 27) | \
    (1u << 28) | (1u << 29))

// --- FLASH ---
// Uses 8MB Flash. Standard W25Q080 stage2 is compatible with GD25LQ64/etc used by Adafruit.
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (8 * 1024 * 1024)
#endif

#ifndef PICO_RP2040_B0_SUPPORTED
#define PICO_RP2040_B0_SUPPORTED 1
#endif

#endif
