#ifndef HOME_CPP
#define HOME_CPP

#include "Page.hpp"
#include "PageController.hpp"

class Home : public Page {
private:
	MyTime _newTime;
	MyTime _oldTime;

public:
	Home(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif