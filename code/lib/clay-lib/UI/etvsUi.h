#ifndef ETVUI_H
#define ETVUI_H

#include "clay.h"
#include <stdint.h>

#define ETVS_ON_COLOR {0, 255, 0, 255}
#define ETVS_OFF_COLOR {255, 0, 0, 255}

#define ETVS_BG_COLOR {0, 255, 0, 255}
#define ETVS_TEXT_COLOR {255, 255, 255, 255}
#define ETVS_TEXT_SIZE 30

void createEtvGroup();

void setEtvsTextId(uint16_t id);
uint16_t getEtvsTextId();

#endif//ETVUI_H
