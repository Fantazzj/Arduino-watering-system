#ifndef EDIT_ETV_DAYS_CPP
#define EDIT_ETV_DAYS_CPP

#include "Page.hpp"

class EditEtvDays : public Page {
private:
	int8_t _etvEdit;
	uint8_t _daysEdit;

public:
	explicit EditEtvDays(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
