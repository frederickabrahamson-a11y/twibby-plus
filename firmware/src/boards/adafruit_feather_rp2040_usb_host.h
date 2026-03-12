// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// Board definition for Adafruit Feather RP2040 with USB Type-A Host
// https://learn.adafruit.com/adafruit-feather-rp2040-with-usb-type-a-host/pinouts
//
// USB Host pins (not available as general GPIO):
//   GPIO 16 - USB Host D+  (PIN_USB_HOST_DP)
//   GPIO 17 - USB Host D-  (PIN_USB_HOST_DM)
//   GPIO 18 - USB Host 5V Power Enable, Active High (PIN_5V_EN)
//
// Internal pins (intentionally excluded from valid GPIO mask):
//   GPIO 7  - BOOT button
//   GPIO 13 - Red LED (D13)
//   GPIO 20 - NeoPixel Power
//   GPIO 21 - NeoPixel data
//
// Default UART on this board:
//   GPIO 0  - UART0 TX
//   GPIO 1  - UART0 RX

#ifndef _BOARDS_ADAFRUIT_FEATHER_RP2040_USB_HOST_H
#define _BOARDS_ADAFRUIT_FEATHER_RP2040_USB_HOST_H

// PIO-USB host data+ pin (D- is automatically DP+1 = GPIO17)
#define PICO_DEFAULT_PIO_USB_DP_PIN 16

// GPIO18 enables the onboard 5V boost converter powering the USB-A port
#define PICO_USB_HOST_POWER_PIN 18

// Default UART pins for this board
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// Valid user-accessible GPIO pins on this Feather.
// Broken-out pins: 0,1,2,3,4,5,6,8,9,10,11,12,13,14,15,24,25,26,27,28,29
// Excluded: 7 (BOOT button), 13 (LED), 16,17 (USB Host D+/D-), 18 (5V_EN),
//           20 (NeoPixel power), 21 (NeoPixel data)
// Remaining: 0,1,2,3,4,5,6,8,9,10,11,12,14,15,24,25,26,27,28,29
// Bitmask:   pins 0-31
#define GPIO_VALID_PINS_BASE ( \
    (1u << 0)  | (1u << 1)  | (1u << 2)  | (1u << 3)  | \
    (1u << 4)  | (1u << 5)  | (1u << 6)  |               \
    (1u << 8)  | (1u << 9)  | (1u << 10) | (1u << 11) | \
    (1u << 12) |              (1u << 14) | (1u << 15) | \
    (1u << 24) | (1u << 25) | (1u << 26) | (1u << 27) | \
    (1u << 28) | (1u << 29))

// --- FLASH ---
// Adafruit Feather RP2040 with USB Host has 8MB QSPI flash (W25Q064)
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
