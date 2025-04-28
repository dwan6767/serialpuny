#include "puny.h"

uint16_t Baud = 104;
static uint16_t baud_delay = 0;

void puny_show_speed(uint32_t rate) {
    Baud = (1000000/rate);
    baud_delay = (Baud);
}

void puny_wakeup() {
    Tx_DDR |= (1 << Tx_BIT);
    Rx_DDR &= ~(1 << Rx_BIT);
    Tx_PORT |= (1 << Tx_BIT) | (1 << Rx_BIT);
}

void puny_throw(uint8_t data) {
    Tx_PORT &= ~(1 << Tx_BIT);  // Start bit
    delayMicroseconds(baud_delay);  // Change _delay_us to delayMicroseconds
    for (uint8_t b = 0; b < 8; b++) {
        if (data & (1 << b))
            Tx_PORT |= (1 << Tx_BIT);
        else
            Tx_PORT &= ~(1 << Tx_BIT);
        
        delayMicroseconds(baud_delay);  // Change _delay_us to delayMicroseconds
    }
    Tx_PORT |= (1 << Tx_BIT);  // Stop bit
    delayMicroseconds(baud_delay);  // Change _delay_us to delayMicroseconds
}

uint8_t puny_got() {
    uint8_t data = 0;
    while (Rx_STATE & (1 << Rx_BIT));  // Wait for start bit
    delayMicroseconds(3 * baud_delay / 2);  // Center of first data bit
    for (uint8_t b = 0; b < 8; b++) {
        if (Rx_STATE & (1 << Rx_BIT))
            data |= (1 << b);
        delayMicroseconds(baud_delay);  // Change _delay_us to delayMicroseconds
    }
    delayMicroseconds(baud_delay);  // Stop bit
    return data;
}

void puny_sentence(const char *str) {
    while (*str) {
        puny_throw(*str);
        str++;
    }
}

void puny_numbers(int number) {
    char buffer[10];
    itoa(number, buffer, 10);
    puny_sentence(buffer);
}
