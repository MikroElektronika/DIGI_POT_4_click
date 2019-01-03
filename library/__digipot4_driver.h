/*
    __digipot4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __digipot4_driver.h
@brief    DIGIPOT4 Driver
@mainpage DIGIPOT4 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DIGIPOT4
@brief      DIGIPOT4 Click Driver
@{

| Global Library Prefix | **DIGIPOT4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DIGIPOT4_H_
#define _DIGIPOT4_H_

/** 
 * @macro T_DIGIPOT4_P
 * @brief Driver Abstract type 
 */
#define T_DIGIPOT4_P    const uint8_t*

/** @defgroup DIGIPOT4_COMPILE Compilation Config */              /** @{ */

   #define   __DIGIPOT4_DRV_SPI__                            /**<     @macro __DIGIPOT4_DRV_SPI__  @brief SPI driver selector */
//  #define   __DIGIPOT4_DRV_I2C__                            /**<     @macro __DIGIPOT4_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DIGIPOT4_DRV_UART__                           /**<     @macro __DIGIPOT4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DIGIPOT4_VAR Variables */                           /** @{ */

// Write Wiper Register 1 and 2
extern const uint8_t _DIGIPOT4_WIPER_REG_1;
extern const uint8_t _DIGIPOT4_WIPER_REG_2;

// Write NV Register 1 and 2
extern const uint8_t _DIGIPOT4_NV_REG_1;
extern const uint8_t _DIGIPOT4_NV_REG_2;

// Copy Wiper Register 1 to NV Register 1(or 2 or both)
extern const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_1;
extern const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_2;
extern const uint8_t _DIGIPOT4_COPY_WIPER_TO_NV_1_2;

// Copy NV Register 1 to Wiper Register 1 (or 2 or both)
extern const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_1;
extern const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_2;
extern const uint8_t _DIGIPOT4_COPY_NV_TO_WIPER_1_2;

                                                                       /** @} */
/** @defgroup DIGIPOT4_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DIGIPOT4_INIT Driver Initialization */              /** @{ */

#ifdef   __DIGIPOT4_DRV_SPI__
void digipot4_spiDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P spiObj);
#endif
#ifdef   __DIGIPOT4_DRV_I2C__
void digipot4_i2cDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P i2cObj, uint8_t slave);
#endif
#ifdef   __DIGIPOT4_DRV_UART__
void digipot4_uartDriverInit(T_DIGIPOT4_P gpioObj, T_DIGIPOT4_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void digipot4_gpioDriverInit(T_DIGIPOT4_P gpioObj);
                                                                       /** @} */
/** @defgroup DIGIPOT4_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Writes data in register
 *
 * This function writes data in wiper register and NV register
 */
void digipot4_writeReg(uint8_t Reg, uint16_t value);

/**
 * @brief Copy data
 *
 * This function is used to copy the data from the wipers to the NV memory
   and from the NV memory it wipers.
 */
void digipot4_copyReg(uint8_t Reg);





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DIGIPOT4_STM.c
    @example Click_DIGIPOT4_TIVA.c
    @example Click_DIGIPOT4_CEC.c
    @example Click_DIGIPOT4_KINETIS.c
    @example Click_DIGIPOT4_MSP.c
    @example Click_DIGIPOT4_PIC.c
    @example Click_DIGIPOT4_PIC32.c
    @example Click_DIGIPOT4_DSPIC.c
    @example Click_DIGIPOT4_AVR.c
    @example Click_DIGIPOT4_FT90x.c
    @example Click_DIGIPOT4_STM.mbas
    @example Click_DIGIPOT4_TIVA.mbas
    @example Click_DIGIPOT4_CEC.mbas
    @example Click_DIGIPOT4_KINETIS.mbas
    @example Click_DIGIPOT4_MSP.mbas
    @example Click_DIGIPOT4_PIC.mbas
    @example Click_DIGIPOT4_PIC32.mbas
    @example Click_DIGIPOT4_DSPIC.mbas
    @example Click_DIGIPOT4_AVR.mbas
    @example Click_DIGIPOT4_FT90x.mbas
    @example Click_DIGIPOT4_STM.mpas
    @example Click_DIGIPOT4_TIVA.mpas
    @example Click_DIGIPOT4_CEC.mpas
    @example Click_DIGIPOT4_KINETIS.mpas
    @example Click_DIGIPOT4_MSP.mpas
    @example Click_DIGIPOT4_PIC.mpas
    @example Click_DIGIPOT4_PIC32.mpas
    @example Click_DIGIPOT4_DSPIC.mpas
    @example Click_DIGIPOT4_AVR.mpas
    @example Click_DIGIPOT4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __digipot4_driver.h

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