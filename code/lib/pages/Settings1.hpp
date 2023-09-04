#ifndef SETTINGS1_CPP
#define SETTINGS1_CPP

#include "Page.hpp"

class Settings1 : public Page {
private:
public:
	Settings1(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
