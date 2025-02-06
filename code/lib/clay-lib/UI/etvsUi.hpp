#ifndef ETVUI_H
#define ETVUI_H

#include "clay.h"
#include <cstdint>

#define ETVS_ON_COLOR {149, 182, 120, 255}
#define ETVS_OFF_COLOR {101, 157, 213, 255}

#define ETVS_BG_COLOR {100, 120, 150, 255}
#define ETVS_TEXT_COLOR {50, 50, 50, 255}
#define ETVS_TEXT_SIZE 30

class EtvsUi {
public:
	static void createEtvGroup();
	static void setEtvsTextId(uint16_t id);
	static uint16_t getEtvsTextId();
	static void setEtvState(int8_t n, bool state);
	static void createEtv(int8_t i);
	static void createEtvRow(int8_t from, int8_t to);
	static void activateEtv(int8_t n);
	static void deactivateEtv(int8_t n);
};

#endif//ETVUI_H
