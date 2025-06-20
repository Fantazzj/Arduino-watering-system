#include "ClayClockUi.hpp"

using namespace std::chrono;

ClayClockUi::ClayClockUi(const uint16_t id) {
	textId = id;
	const auto zonedTime = current_zone()->to_local(system_clock::now());
	dateTime = floor<seconds>(zonedTime);
	updateStrings();
}

uint16_t ClayClockUi::getTextId() const {
	return textId;
}

local_time<seconds> ClayClockUi::getDateTime() const {
	return dateTime;
}

void ClayClockUi::setDateTime(const local_time<seconds> dateTime) {
	this->dateTime = dateTime;
}

void ClayClockUi::createClock() {
	updateStrings();
	CLAY({
			.id = CLAY_ID("Clock"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {
							.left = 10,
							.right = 10,
							.top = 10,
							.bottom = 10,
					},
					.childGap = 10,
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		createSpacer();
		createDateEditor();
		createSpacer();
		createTimeEditor();
		createSpacer();
	}
}

void ClayClockUi::createDateEditor() {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {
							.left = 10,
							.right = 10,
					},
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = CHAR_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		createEditor(stringDateDay, increaseOneDay, decreaseOneDay);
		CLAY_TEXT(CLAY_STRING("/"), CLAY_TEXT_CONFIG(charText));
		createEditor(stringDateMonth, increaseOneMonth, decreaseOneMonth);
		CLAY_TEXT(CLAY_STRING("/"), CLAY_TEXT_CONFIG(charText));
		createEditor(stringDateYear, increaseOneYear, decreaseOneYear);
	}
}

void ClayClockUi::createTimeEditor() {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {
							.left = 10,
							.right = 10,
					},
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = CHAR_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		createEditor(stringTimeHours, increaseOneHour, decreaseOneHour);
		CLAY_TEXT(CLAY_STRING(":"), CLAY_TEXT_CONFIG(charText));
		createEditor(stringTimeMinutes, increaseOneMinute, decreaseOneMinute);
	}
}

void ClayClockUi::createEditor(const std::string& num, ClayHandler_t pressHandlerAdd, ClayHandler_t pressHandlerSub) {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String string = {
			.length = static_cast<int32_t>(num.length()),
			.chars = num.c_str(),
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
	}) {
		CLAY() {
			Clay_OnHover(pressHandlerAdd, reinterpret_cast<intptr_t>(&dateTime));
			CLAY_TEXT(CLAY_STRING("+"), CLAY_TEXT_CONFIG(charText));
		}
		CLAY_TEXT(string, CLAY_TEXT_CONFIG(charText));
		CLAY() {
			Clay_OnHover(pressHandlerSub, reinterpret_cast<intptr_t>(&dateTime));
			CLAY_TEXT(CLAY_STRING("-"), CLAY_TEXT_CONFIG(charText));
		}
	}
}

void ClayClockUi::updateStrings() {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	if(date.day() < 10d) stringDateDay = "0";
	else stringDateDay = "";
	stringDateDay += std::to_string(static_cast<unsigned>(date.day()));

	if(date.month() < October) stringDateMonth = "0";
	else stringDateMonth = "";
	stringDateMonth += std::to_string(static_cast<unsigned>(date.month()));

	stringDateYear = std::to_string(static_cast<int>(date.year()));

	if(time.hours() < 10h) stringTimeHours = "0";
	else stringTimeHours = "";
	stringTimeHours += std::to_string(time.hours().count());

	if(time.minutes() < 10min) stringTimeMinutes = "0";
	else stringTimeMinutes = "";
	stringTimeMinutes += std::to_string(time.minutes().count());
}

void ClayClockUi::createSpacer() {
	CLAY({.layout = {
				  .sizing = {
						  .width = CLAY_SIZING_GROW(),
						  .height = CLAY_SIZING_FIT(),
				  }}}) {}
}

void ClayClockUi::genericHandler(local_time<seconds>* dateTime, const duration<intmax_t> delta, const bool increase) {
	*dateTime = increase ? *dateTime + delta : *dateTime - delta;
}

void ClayClockUi::increaseOneHour(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), hours(1), true);
}

void ClayClockUi::decreaseOneHour(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), hours(1), false);
}

void ClayClockUi::increaseOneMinute(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), minutes(1), true);
}

void ClayClockUi::decreaseOneMinute(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), minutes(1), false);
}

void ClayClockUi::increaseOneDay(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), days(1), true);
}

void ClayClockUi::decreaseOneDay(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), days(1), false);
}

void ClayClockUi::increaseOneMonth(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), months(1), true);
}

void ClayClockUi::decreaseOneMonth(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), months(1), false);
}

void ClayClockUi::increaseOneYear(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), years(1), true);
}

void ClayClockUi::decreaseOneYear(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	genericHandler(reinterpret_cast<local_time<seconds>*>(args), years(1), false);
}
