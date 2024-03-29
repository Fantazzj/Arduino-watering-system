#ifndef HOME_CPP
#define HOME_CPP

#include "Page.hpp"
#include "PageController.hpp"

class Home : public Page {
private:
	MyDateTime _newTime;
	MyDateTime _oldTime;
	uint8_t oldEtvOn = 0;

public:
	explicit Home(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
