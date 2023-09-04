#ifndef EDIT_ETV_TIME_CPP
#define EDIT_ETV_TIME_CPP

#include "Page.hpp"

class EditEtvTime : public Page {
private:
	int8_t _etvEdit = 1;
	int8_t _timeEdit = _controller->getEtvMinOn(1);

public:
	EditEtvTime(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
