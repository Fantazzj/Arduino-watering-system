#ifndef SETTINGS2_CPP
#define SETTINGS2_CPP

#include "Page.hpp"

class Settings2 : public Page {
private:
public:
	explicit Settings2(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
