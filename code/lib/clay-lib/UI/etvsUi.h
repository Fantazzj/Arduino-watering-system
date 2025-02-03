#ifndef ETVUI_H
#define ETVUI_H

#include "clay.h"
#include <stdint.h>

#define ETVS_ON_COLOR {149, 182, 120, 255}
#define ETVS_OFF_COLOR {101, 157, 213, 255}

#define ETVS_BG_COLOR {100, 120, 150, 255}
#define ETVS_TEXT_COLOR {50, 50, 50, 255}
#define ETVS_TEXT_SIZE 30

void createEtvGroup();

void setEtvsTextId(uint16_t id);
uint16_t getEtvsTextId();

#endif//ETVUI_H
