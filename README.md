![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DIGIPOT4 Click

- **CIC Prefix**  : DIGIPOT4
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : Jan 2018.

---

### Software Support

We provide a library for the DIGIPOT4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2287/digipot-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries two functions which are enough to have complete control ove DIGIPOT4 click board.

Key functions :

- ``` void digipot4_writeReg(uint8_t Reg, uint16_t value) ``` - Write data to wiper register
- ``` void digipot4_copyReg(uint8_t Reg) ``` - Copy data to NV memory

**Examples Description**

The application is composed of three sections :

- System Initialization -  Intializes SPI module and set CS pin as OUTPUT
- Application Initialization -  DIGIPOT 4 Driver intialization
- Application Task - (code snippet) - Set the wiper position sequentialy each one second.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2287/digipot-4-click) page.

mikroE Libraries used in the example:

- SPI

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
