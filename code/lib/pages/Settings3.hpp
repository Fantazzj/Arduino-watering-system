#ifndef SETTINGS3_CPP
#define SETTINGS3_CPP

#include "Page.hpp"

class Settings3 : public Page {
private:
public:
	Settings3(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif