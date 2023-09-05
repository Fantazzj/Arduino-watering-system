#ifndef SETTINGS6_CPP
#define SETTINGS6_CPP

#include "Page.hpp"

class Settings6 : public Page {
private:
public:
	explicit Settings6(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
