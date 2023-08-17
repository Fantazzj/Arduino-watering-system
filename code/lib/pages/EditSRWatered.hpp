#ifndef EDIT_SR_WATERED_CPP
#define EDIT_SR_WATERED_CPP

#include "Page.hpp"

class EditSRWatered : public Page {
private:
	bool _watered = false;

public:
	EditSRWatered(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif
