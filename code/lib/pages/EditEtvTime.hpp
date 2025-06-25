#ifndef EDIT_ETV_TIME_CPP
#define EDIT_ETV_TIME_CPP

#include "Page.hpp"

class EditEtvTime final : public Page {
private:
	int8_t etvEdit;
	uint8_t timeEdit;

public:
	explicit EditEtvTime(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
