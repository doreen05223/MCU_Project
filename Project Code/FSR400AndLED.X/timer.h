#ifndef _TIMER_H
#define	_TIMER_H

#include <pic18f4520.h>
#include <xc.h> 
#include "setting.h"
#include "DrawLight.h"

int count;
int in;
int shine;

void init_interrupt(void);

#endif

