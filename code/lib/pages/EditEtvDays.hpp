#ifndef EDIT_ETV_DAYS_CPP
#define EDIT_ETV_DAYS_CPP

#include "Page.hpp"

class EditEtvDays : public Page {
private:
	int8_t _etvEdit = 1;
	int8_t _daysEdit = _controller->etv[1]->days;

public:
	explicit EditEtvDays(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
