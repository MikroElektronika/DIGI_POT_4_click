/*
Example for DIGIPOT4 Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization -  Intializes SPI module and set CS pin as OUTPUT
- Application Initialization -  Driver intialization
- Application Task - (code snippet) - Set the wiper position.

*/

#include "Click_DIGIPOT4_types.h"
#include "Click_DIGIPOT4_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_DIGIPOT4_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    digipot4_spiDriverInit( (T_DIGIPOT4_P)&_MIKROBUS1_GPIO, (T_DIGIPOT4_P)&_MIKROBUS1_SPI );
}

void applicationTask()
{
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_1, 0);
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_2, 0);
    Delay_1sec();
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_1, 512);
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_2, 512);
    Delay_1sec();
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_1, 1023);
    digipot4_writeReg(_DIGIPOT4_WIPER_REG_2, 1023);
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
