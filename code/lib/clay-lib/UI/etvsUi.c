#include "etvsUi.h"

#define ETV_NUM 9

const Clay_Color etvsOnColor = ETVS_ON_COLOR;
const Clay_Color etvsOffColor = ETVS_OFF_COLOR;

const Clay_String etvsNames[ETV_NUM] = {
		{
				.chars = "Etv1",
				.length = 4,
		},
		{
				.chars = "Etv2",
				.length = 4,
		},
		{
				.chars = "Etv3",
				.length = 4,
		},
		{
				.chars = "Etv4",
				.length = 4,
		},
		{
				.chars = "Etv5",
				.length = 4,
		},
		{
				.chars = "Etv6",
				.length = 4,
		},
		{
				.chars = "Etv7",
				.length = 4,
		},
		{
				.chars = "Etv8",
				.length = 4,
		},
		{
				.chars = "Etv9",
				.length = 4,
		},
};

uint16_t etvsTextId;

void setEtvsTextId(uint16_t id) {
	etvsTextId = id;
}

uint16_t getEtvsTextId() {
	return etvsTextId;
}

void createEtv(int8_t i) {
	Clay_TextElementConfig etvsText = {
			.fontId = etvsTextId,
			.fontSize = ETVS_TEXT_SIZE,
			.textColor = ETVS_TEXT_COLOR,
	};

	CLAY(CLAY_RECTANGLE({
				 .color = false ? etvsOnColor : etvsOffColor,
				 .cornerRadius = {10, 10, 10, 10},
		 }),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		 })) {
		CLAY_TEXT(etvsNames[i], CLAY_TEXT_CONFIG(etvsText));
	}
}

void createEtvRow(int8_t from, int8_t to) {
	CLAY(CLAY_LAYOUT({
			.layoutDirection = CLAY_LEFT_TO_RIGHT,
			.childGap = 10,
			.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			.sizing = {
					.width = CLAY_SIZING_GROW(),
					.height = CLAY_SIZING_GROW(),
			},
	})) {
		for(int8_t i = from; i <= to; i++)
			createEtv(i);
	}
}

void createEtvGroup() {
	CLAY(CLAY_ID("Etvs"),
		 CLAY_RECTANGLE({
				 .color = ETVS_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .padding = {10, 10, 10, 10},
				 .childGap = 10,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
		 })) {
		for(int8_t i = 0; i < ETV_NUM / 3; i++)
			createEtvRow(i * 3, i * 3 + 2);
	}
}
