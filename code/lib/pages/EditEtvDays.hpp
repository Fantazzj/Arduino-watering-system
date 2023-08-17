#ifndef EDIT_ETV_DAYS_CPP
#define EDIT_ETV_DAYS_CPP

#include "Page.hpp"

class EditEtvDays : public Page {
private:
	int8_t _etvEdit = 1;
	int8_t _daysEdit = _controller->getEtvDays(1);

public:
	EditEtvDays(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif
