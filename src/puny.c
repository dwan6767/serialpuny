#include "puny.h"

uint16_t Baud = 104;
static uint16_t baud_delay = 0;
void setupTimer0() {
    TCCR0A = 0; 
    TCCR0B = (1 << CS00); 
}

void puny_show_speed(uint32_t rate) {
    setupTimer0();
    Baud = (F_CPU / 16 / rate) - 1;
    baud_delay = (Baud);
}

void puny_wakeup() {
    Tx_DDR |= (1 << Tx_BIT);
    Rx_DDR &= ~(1 << Rx_BIT);
    Tx_PORT |= (1 << Tx_BIT) | (1 << Rx_BIT);
}

void puny_throw(uint8_t data) {
    Tx_PORT &= ~(1 << Tx_BIT);  // Start bit
    delay_us(baud_delay);
    
    for (uint8_t b = 0; b < 8; b++) {
        if (data & (1 << b))
            Tx_PORT |= (1 << Tx_BIT);
        else
            Tx_PORT &= ~(1 << Tx_BIT);
        
        delay_us(baud_delay);
    }

    Tx_PORT |= (1 << Tx_BIT);  // Stop bit
    delay_us(baud_delay);
}

uint8_t puny_got() {
    uint8_t data = 0;
    while (Rx_STATE & (1 << Rx_BIT));  // Wait for start bit
    delay_us(3 * baud_delay / 2);  // Center of first data bit
    
    for (uint8_t b = 0; b < 8; b++) {
        if (Rx_STATE & (1 << Rx_BIT))
            data |= (1 << b);
        delay_us(baud_delay);
    }
    
    delay_us(baud_delay);  // Stop bit
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
void delay_us(uint16_t us) {
    uint16_t count = 0;
    while (count < us) {
        while (!(TIFR0 & (1 << TOV0)));  
        TIFR0 |= (1 << TOV0);  
        count++;
    }
}
