/*
    __digipot4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__digipot4_driver.h"
#include "__digipot4_hal.c"

/* ------------------------------------------------------------------- MACROS */

// Write Wiper Register 1 and 2
const uint8_t _DIGIPOT4_WIPER_REG_1 = 0x01;
const uint8_t _DIGIPOT4_WIPER_REG_2 = 0x02;

// Write NV Register 1 and 2
const uint8_t _DIGIPOT4_NV_REG_1 = 0x11;
const uint8_t _DIGIPOT4_NV_REG_2 = 0x12;

// Copy Wiper Register 1 to NV Register 1(or 2 or both)
const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_1 = 0x21;
const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_2 = 0x22;
const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_1_2 = 0x23;

// Copy NV Register 1 to Wiper Register 1 (or 2 or both)
const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_1 = 0x31;
const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_2 = 0x32;
const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_1_2 = 0x33;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __DIGIPOT4_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DIGIPOT4_DRV_SPI__

void digipot4_spiDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
    Delay_100ms();
}

#endif
#ifdef   __DIGIPOT4_DRV_I2C__

void digipot4_i2cDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DIGIPOT4_DRV_UART__

void digipot4_uartDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

void digipot4_writeReg(uint8_t Reg, uint16_t value)
{
    uint8_t wReg[ 3 ];
    wReg[0] = Reg;
    wReg[1] = value >> 2;
    wReg[2] = value << 6;
    
    hal_gpio_csSet(0);
    hal_spiWrite(wReg,3);
    hal_gpio_csSet(1);
}

void digipot4_copyReg(uint8_t Reg)
{
    uint8_t wReg[ 1 ];
    wReg[0] = Reg;

    hal_gpio_csSet(0);
    hal_spiWrite(wReg,1);
    hal_gpio_csSet(1);
    Delay_100ms();
}






/* -------------------------------------------------------------------------- */
/*
  __digipot4_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */