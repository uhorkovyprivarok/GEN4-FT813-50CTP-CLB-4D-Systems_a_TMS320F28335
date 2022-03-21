/*
 * spi_func.h
 *
 *  Created on: 14. 12. 2021
 *      Author: david
 */

#ifndef SPI_FUNC_H_
#define SPI_FUNC_H_

#include <DSP2833x_Device.h>
//#include <EVE_commands.h>

    void spi_sendChar(char cData);
    void spi_sendData(char acData[], unsigned int lenght);

/*
    void EVE_cs_clear(char cData);
    void EVE_cs_set(char cData);
    void EVE_pdn_clear(char cData);
    void EVE_pdn_set(char cData);
    void fetch_flash_byte(char cData);
    void spi_receive(char cData);
    void spi_transmit(char cData);
    void spi_transmit_32(char cData);
    void spi_transmit_burst(char cData);
*/

/*

    static inline void DELAY_MS(uint16_t val)
                {
                    uint16_t counter;

                    while(val > 0)
                    {
                        for(counter=0; counter < 2000;counter++) // maybe ~1ms at 16MHz clock
                        {
                            __asm__ volatile ("nop");
                        }
                        val--;
                    }
                }
*/
/*
    #if !defined (EVE_CS)
    #define EVE_CS_PORT PORTB
    #define EVE_CS      (1<<PB5)
    #define EVE_PDN_PORT    PORTB
    #define EVE_PDN     (1<<PB4)
    #endif

    static inline void EVE_pdn_set(void)
    {
        EVE_PDN_PORT &= ~EVE_PDN;   // Power-Down low
    }

    static inline void EVE_pdn_clear(void)
    {
        EVE_PDN_PORT |= EVE_PDN;    // Power-Down high
    }

    static inline void EVE_cs_set(void)
    {
        EVE_CS_PORT &= ~EVE_CS; // cs low
    }

                static inline void EVE_cs_clear(void)
                {
                    EVE_CS_PORT |= EVE_CS;  // cs high
                }

                static inline void spi_transmit(uint8_t data)
                {
                    SPDR = data; // start transmission
                    while(!(SPSR & (1<<SPIF))) {}; // wait for transmission to complete - 1us @ 8MHz SPI-Clock
                }

                static inline void spi_transmit_32(uint32_t data)
                {
                    spi_transmit((uint8_t)(data & 0x000000ff));
                    spi_transmit((uint8_t)(data >> 8));
                    spi_transmit((uint8_t)(data >> 16));
                    spi_transmit((uint8_t)(data >> 24));
                }

                // spi_transmit_burst() is only used for cmd-FIFO commands so it *always* has to transfer 4 bytes
                static inline void spi_transmit_burst(uint32_t data)
                {
                    spi_transmit_32(data);
                }

                static inline uint8_t spi_receive(uint8_t data)
                {
                    SPDR = data; // start transmission
                    while(!(SPSR & (1<<SPIF))) {}; // wait for transmission to complete - 1us @ 8MHz SPI-CLock
                    return SPDR;
                }

                static inline uint8_t fetch_flash_byte(const uint8_t *data)
                {
                    return *data;
                }
*/
#endif /* SPI_FUNC_H_ */
