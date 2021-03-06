/**
 * @file sysclock_dspic.c
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2016
 *
 * @date June 17, 2016, 11:45 PM
 *
 * @brief System clock support for udevkit sim
 */

#include <stdint.h>

#include "sysclock.h"

uint32_t sysfreq;
uint32_t pllfreq;

int sysclock_setClock(uint32_t fosc)
{
    sysfreq = fosc;
    return 0;
}

uint32_t sysclock_getClock()
{
    return sysfreq;
}

uint32_t sysclock_getCPUSystemClock()
{
    return sysfreq >> 1;
}

uint32_t sysclock_periphFreq(SYSCLOCK_CLOCK busClock)
{
    // TODO
    return sysfreq / 2;
}

int sysclock_setClockDiv(SYSCLOCK_CLOCK busClock, uint16_t div)
{
    // TODO
    return 0;
}

SYSCLOCK_SOURCE sysclock_source()
{
    // TODO
    return 0;
}

int sysclock_setSourceFreq(SYSCLOCK_SOURCE source, uint32_t freq)
{
    return 0;
}

int32_t sysclock_sourceFreq(SYSCLOCK_SOURCE source)
{
    return 0;
}

int sysclock_switchSourceTo(SYSCLOCK_SOURCE source)
{
    // TODO
    return 0;
}

int sysclock_setPLLClock(uint32_t freq, uint8_t src)
{
    pllfreq = freq;
    return 0;
}

uint32_t sysclock_getPLLClock()
{
    return pllfreq;
}
