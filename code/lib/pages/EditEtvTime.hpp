#ifndef EDIT_ETV_TIME_CPP
#define EDIT_ETV_TIME_CPP

#include "Page.hpp"

class EditEtvTime : public Page {
private:
	int8_t _etvEdit = 1;
	int8_t _timeEdit = _controller->etv[1]->minOn;

public:
	explicit EditEtvTime(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
