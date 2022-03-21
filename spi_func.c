/*
 * spi_func.c
 *
 *  Created on: 14. 12. 2021
 *      Author: david
 */


    #include "spi_func.h"

    void spi_sendChar(char cData)
    {
        while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
        if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
    }

    void spi_sendData(char acData[], unsigned int lenght)
    {
        int i;
        for(i=0; i<lenght; i++)
        {
            spi_sendChar(*(acData+i));
        }
    }



/*

    void EVE_cs_clear(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void EVE_cs_set(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void EVE_pdn_clear(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void EVE_pdn_set(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void fetch_flash_byte(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void spi_receive(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void spi_transmit(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void spi_transmit_32(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }

    void spi_transmit_burst(char cData)
        {
            while(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 1);       // wait for ready state
            if(SpiaRegs.SPISTS.bit.BUFFULL_FLAG == 0) SpiaRegs.SPITXBUF = (cData & 0xFF) << 8;      // send data with left justifaction
        }
*/
