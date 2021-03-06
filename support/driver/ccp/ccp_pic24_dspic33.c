/**
 * @file ccp_pic24_dspic33.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright UniSwarm 2019
 *
 * @date May 08, 2019, 09:40 AM
 *
 * @brief CCP capture/compare/PWM/Timer support driver for PIC24 and dsPIC33C 
 *
 * Implementation based on Microchip document DS30003035B:
 *  http://ww1.microchip.com/downloads/en/DeviceDoc/30003035b.pdf
 */

#include "ccp.h"

#include <driver/sysclock.h>
#include <archi.h>

#if !defined (CCP_COUNT) || CCP_COUNT==0
  #warning "No uart on the current device or unknow device"
#endif

#define CCP_FLAG_UNUSED  0x00
typedef struct {
    union {
        struct {
            unsigned used : 1;
            unsigned enabled : 1;
            unsigned bit32 : 1;
            unsigned : 5;
        };
        uint8_t val;
    };
} ccp_status;

struct ccp_dev
{
    uint32_t periodUs;
    ccp_status flags;
    void (*handler)(void);
};

struct ccp_dev ccps[] = {
#if CCP_COUNT>=1
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=2
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=3
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=4
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=5
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=6
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=7
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=8
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
#if CCP_COUNT>=9
    {
        .periodUs = 0,
        .flags = {{.val = CCP_FLAG_UNUSED}},
        .handler = NULL
    },
#endif
};

/**
 * @brief Gives a free ccp device number
 * @return ccp device number
 */
rt_dev_t ccp_getFreeDevice()
{
#if CCP_COUNT>=1
    uint8_t i;
    rt_dev_t device;

    for (i = 0; i < CCP_COUNT; i++)
        if (ccps[i].flags.used == 0)
            break;

    if (i == CCP_COUNT)
        return NULLDEV;
    device = MKDEV(DEV_CLASS_CCP, i);

    ccp_open(device);

    return device;
#else
    return NULLDEV;
#endif
}

/**
 * @brief Open a ccp
 * @param device ccp device number
 */
int ccp_open(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;
    if (ccps[ccp].flags.used == 1)
        return -1;

    ccps[ccp].flags.used = 1;
    ccps[ccp].handler = NULL;

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Close a ccp
 * @param device ccp device number
 */
int ccp_close(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccp_disable(device);

    ccps[ccp].flags.val = CCP_FLAG_UNUSED;

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Enable the specified ccp device
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
int ccp_enable(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccps[ccp].flags.enabled = 1;

    switch (ccp)
    {
    case 0:
        CCP1CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT1IF = 0;
        if (ccps[0].handler)
            _CCT1IE = 1;
        else
            _CCT1IE = 0;
        _CCT1IP = 4;
        break;
#if CCP_COUNT>=2
    case 1:
        CCP2CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT2IF = 0;
        if (ccps[1].handler)
            _CCT2IE = 1;
        else
            _CCT2IE = 0;
        _CCT2IP = 4;
        break;
#endif
#if CCP_COUNT>=3
    case 2:
        CCP3CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT3IF = 0;
        if (ccps[2].handler)
            _CCT3IE = 1;
        else
            _CCT3IE = 0;
        _CCT3IP = 4;
        break;
#endif
#if CCP_COUNT>=4
    case 3:
        CCP4CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT4IF = 0;
        if (ccps[3].handler)
            _CCT4IE = 1;
        else
            _CCT4IE = 0;
        _CCT4IP = 4;
        break;
#endif
#if CCP_COUNT>=5
    case 4:
        CCP5CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT5IF = 0;
        if (ccps[4].handler)
            _CCT5IE = 1;
        else
            _CCT5IE = 0;
        _CCT5IP = 4;
        break;
#endif
#if CCP_COUNT>=6
    case 5:
        CCP6CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT6IF = 0;
        if (ccps[5].handler)
            _CCT6IE = 1;
        else
            _CCT6IE = 0;
        _CCT6IP = 4;
        break;
#endif
#if CCP_COUNT>=7
    case 6:
        CCP7CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT7IF = 0;
        if (ccps[6].handler)
            _CCT7IE = 1;
        else
            _CCT7IE = 0;
        _CCT7IP = 4;
        break;
#endif
#if CCP_COUNT>=8
    case 7:
        CCP8CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT8IF = 0;
        if (ccps[7].handler)
            _CCT8IE = 1;
        else
            _CCT8IE = 0;
        _CCT8IP = 4;
        break;
#endif
#if CCP_COUNT>=9
    case 8:
        CCP9CON1Lbits.CCPON = 1;  // enable ccp module
        _CCT9IF = 0;
        if (ccps[8].handler)
            _CCT9IE = 1;
        else
            _CCT9IE = 0;
        _CCT9IP = 4;
        break;
#endif
    }

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Disable the specified ccp device
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
int ccp_disable(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccps[ccp].flags.enabled = 0;

    switch (ccp)
    {
    case 0:
        CCP1CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT1IE = 0;
        break;
#if CCP_COUNT>=2
    case 1:
        CCP2CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT2IE = 0;
        break;
#endif
#if CCP_COUNT>=3
    case 2:
        CCP3CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT3IE = 0;
        break;
#endif
#if CCP_COUNT>=4
    case 3:
        CCP4CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT4IE = 0;
        break;
#endif
#if CCP_COUNT>=5
    case 4:
        CCP5CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT5IE = 0;
        break;
#endif
#if CCP_COUNT>=6
    case 5:
        CCP6CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT6IE = 0;
        break;
#endif
#if CCP_COUNT>=7
    case 6:
        CCP7CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT7IE = 0;
        break;
#endif
#if CCP_COUNT>=8
    case 7:
        CCP8CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT8IE = 0;
        break;
#endif
#if CCP_COUNT>=9
    case 8:
        CCP9CON1Lbits.CCPON = 0;  // disable ccp module
        _CCT9IE = 0;
        break;
#endif
    }

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Sets the handler function that will be called on ccp interrupt
 * @param device ccp device number
 * @param handler void funtion pointer or null to remove the handler
 * @return 0 if ok, -1 in case of error
 */
int ccp_setHandler(rt_dev_t device, void (*handler)(void))
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccps[ccp].handler = handler;
    if (ccps[ccp].flags.enabled == 1)
        ccp_enable(device);

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Sets the internal period
 * @param device ccp device number
 * @param prvalue reset value of ccp, does not consider the time
 * @return 0 if ok, -1 in case of error
 */
int ccp_setPeriod(rt_dev_t device, uint32_t prvalue)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    switch (ccp)
    {
    case 0:
        CCP1PRH = prvalue >> 16;
        CCP1PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#if CCP_COUNT>=2
    case 1:
        CCP2PRH = prvalue >> 16;
        CCP2PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=3
    case 2:
        CCP3PRH = prvalue >> 16;
        CCP3PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=4
    case 3:
        CCP4PRH = prvalue >> 16;
        CCP4PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=5
    case 4:
        CCP5PRH = prvalue >> 16;
        CCP5PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=6
    case 5:
        CCP6PRH = prvalue >> 16;
        CCP6PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=7
    case 6:
        CCP7PRH = prvalue >> 16;
        CCP7PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=8
    case 7:
        CCP8PRH = prvalue >> 16;
        CCP8PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
#if CCP_COUNT>=9
    case 8:
        CCP9PRH = prvalue >> 16;
        CCP9PRL = (uint16_t)prvalue; // pr value, comparator value
        break;
#endif
    }

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Gets the internal period
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
uint32_t ccp_period(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    switch (ccp)
    {
    case 0:
        return ((uint32_t)CCP1PRH << 16) + CCP1PRL;
#if CCP_COUNT>=2
    case 1:
        return ((uint32_t)CCP2PRH << 16) + CCP2PRL;
#endif
#if CCP_COUNT>=3
    case 2:
        return ((uint32_t)CCP3PRH << 16) + CCP3PRL;
#endif
#if CCP_COUNT>=4
    case 3:
        return ((uint32_t)CCP4PRH << 16) + CCP4PRL;
#endif
#if CCP_COUNT>=5
    case 4:
        return ((uint32_t)CCP5PRH << 16) + CCP5PRL;
#endif
#if CCP_COUNT>=6
    case 5:
        return ((uint32_t)CCP6PRH << 16) + CCP6PRL;
#endif
#if CCP_COUNT>=7
    case 6:
        return ((uint32_t)CCP7PRH << 16) + CCP7PRL;
#endif
#if CCP_COUNT>=8
    case 7:
        return ((uint32_t)CCP8PRH << 16) + CCP8PRL;
#endif
#if CCP_COUNT>=9
    case 8:
        return ((uint32_t)CCP9PRH << 16) + CCP9PRL;
#endif
    }

    return 0;
#else
    return -1;
#endif
}

/**
 * @brief Sets the period in us of the ccp module to work in ccp mode
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
int ccp_setPeriodMs(rt_dev_t device, uint32_t periodMs)
{
#if CCP_COUNT>=1
    float prvalue;
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccps[ccp].periodUs = periodMs * 1000;

    prvalue = (float)sysclock_periphFreq(SYSCLOCK_CLOCK_CCP) / 1000.0 * (float)periodMs;

    return ccp_setPeriod(device, (uint32_t)prvalue);
#else
    return -1;
#endif
}

/**
 * @brief Returns the current period in us
 * @param device ccp device number
 * @return period in us if ok, 0 in case of error
 */
uint32_t ccp_periodMs(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return 0;

    return ccps[ccp].periodUs / 1000;
#else
    return 0;
#endif
}

/**
 * @brief Sets the period in us of the ccp module to work in ccp mode
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
int ccp_setPeriodUs(rt_dev_t device, uint32_t periodUs)
{
#if CCP_COUNT>=1
    float prvalue;
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    ccps[ccp].periodUs = periodUs;

    prvalue = (float)sysclock_periphFreq(SYSCLOCK_CLOCK_CCP);
    prvalue = prvalue / 1000000.0;
    prvalue = prvalue * (float)periodUs;

    return ccp_setPeriod(device, (uint32_t)prvalue);
#else
    return -1;
#endif
}

/**
 * @brief Returns the current period in us
 * @param device ccp device number
 * @return period in us if ok, 0 in case of error
 */
uint32_t ccp_periodUs(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return 0;

    return ccps[ccp].periodUs;
#else
    return 0;
#endif
}

/**
 * @brief Returns the current value of ccp
 * @param device ccp device number
 * @return value if ok, 0 in case of error
 */
uint32_t ccp_getValue(rt_dev_t device)
{
#if CCP_COUNT>=1
    uint32_t value;
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return 0;

    switch (ccp)
    {
    case 0:
        value = ((uint32_t)CCP1TMRH << 16) + CCP1TMRL;
        break;
#if CCP_COUNT>=2
    case 1:
        value = ((uint32_t)CCP2TMRH << 16) + CCP2TMRL;
        break;
#endif
#if CCP_COUNT>=3
    case 2:
        value = ((uint32_t)CCP3TMRH << 16) + CCP3TMRL;
        break;
#endif
#if CCP_COUNT>=4
    case 3:
        value = ((uint32_t)CCP4TMRH << 16) + CCP4TMRL;
        break;
#endif
#if CCP_COUNT>=5
    case 4:
        value = ((uint32_t)CCP5TMRH << 16) + CCP5TMRL;
        break;
#endif
#if CCP_COUNT>=6
    case 5:
        value = ((uint32_t)CCP6TMRH << 16) + CCP6TMRL;
        break;
#endif
#if CCP_COUNT>=7
    case 6:
        value = ((uint32_t)CCP7TMRH << 16) + CCP7TMRL;
        break;
#endif
#if CCP_COUNT>=8
    case 7:
        value = ((uint32_t)CCP8TMRH << 16) + CCP8TMRL;
        break;
#endif
#if CCP_COUNT>=9
    case 8:
        value = ((uint32_t)CCP9TMRH << 16) + CCP9TMRL;
        break;
#endif
    }

    return value;
#else
    return 0;
#endif
}

/**
 * @brief Sets the current value of ccp
 * @param device ccp device number
 * @return 0 if ok, -1 in case of error
 */
int ccp_setValue(rt_dev_t device, uint32_t value)
{
#if CCP_COUNT>=1
    uint8_t ccp = MINOR(device);
    if (ccp >= CCP_COUNT)
        return -1;

    switch (ccp)
    {
    case 0:
        CCP1TMRH = value >> 16;
        CCP1TMRL = (uint16_t)value;
        break;
#if CCP_COUNT>=2
    case 1:
        CCP2TMRH = value >> 16;
        CCP2TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=3
    case 2:
        CCP3TMRH = value >> 16;
        CCP3TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=4
    case 3:
        CCP4TMRH = value >> 16;
        CCP4TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=5
    case 4:
        CCP5TMRH = value >> 16;
        CCP5TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=6
    case 5:
        CCP6TMRH = value >> 16;
        CCP6TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=7
    case 6:
        CCP7TMRH = value >> 16;
        CCP7TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=8
    case 7:
        CCP8TMRH = value >> 16;
        CCP8TMRL = (uint16_t)value;
        break;
#endif
#if CCP_COUNT>=9
    case 8:
        CCP9TMRH = value >> 16;
        CCP9TMRL = (uint16_t)value;
        break;
#endif
    }

    return 0;
#else
    return -1;
#endif
}

#if CCP_COUNT>=1
void __attribute__ ((interrupt, no_auto_psv)) _CCT1Interrupt()
{
    if (ccps[0].handler)
        (*ccps[0].handler)();

    _CCT1IF = 0;
}
#endif

#if CCP_COUNT>=2
void __attribute__ ((interrupt, no_auto_psv)) _CCT2Interrupt()
{
    if (ccps[1].handler)
        (*ccps[1].handler)();

    _CCT2IF = 0;
}
#endif

#if CCP_COUNT>=3
void __attribute__ ((interrupt, no_auto_psv)) _CCT3Interrupt()
{
    if (ccps[2].handler)
        (*ccps[2].handler)();

    _CCT3IF = 0;
}
#endif

#if CCP_COUNT>=4
void __attribute__ ((interrupt, no_auto_psv)) _CCT4Interrupt()
{
    if (ccps[3].handler)
        (*ccps[3].handler)();

    _CCT4IF = 0;
}
#endif

#if CCP_COUNT>=5
void __attribute__ ((interrupt, no_auto_psv)) _CCT5Interrupt()
{
    if (ccps[4].handler)
        (*ccps[4].handler)();

    _CCT5IF = 0;
}
#endif

#if CCP_COUNT>=6
void __attribute__ ((interrupt, no_auto_psv)) _CCT6Interrupt()
{
    if (ccps[5].handler)
        (*ccps[5].handler)();

    _CCT6IF = 0;
}
#endif

#if CCP_COUNT>=7
void __attribute__ ((interrupt, no_auto_psv)) _CCT7Interrupt()
{
    if (ccps[6].handler)
        (*ccps[6].handler)();

    _CCT7IF = 0;
}
#endif

#if CCP_COUNT>=8
void __attribute__ ((interrupt, no_auto_psv)) _CCT8Interrupt()
{
    if (ccps[7].handler)
        (*ccps[7].handler)();

    _CCT8IF = 0;
}
#endif

#if CCP_COUNT>=9
void __attribute__ ((interrupt, no_auto_psv)) _CCT9Interrupt()
{
    if (ccps[8].handler)
        (*ccps[8].handler)();

    _CCT9IF = 0;
}
#endif
