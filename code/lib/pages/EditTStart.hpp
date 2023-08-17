#ifndef EDIT_T_START_CPP
#define EDIT_T_START_CPP

#include "Page.hpp"

class EditTStart : public Page {
private:
	MyTime _newTime;
	int8_t _editPhase = 1;

public:
	EditTStart(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif
