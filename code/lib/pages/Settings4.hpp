#ifndef SETTINGS4_CPP
#define SETTINGS4_CPP

#include "Page.hpp"

class Settings4 : public Page {
private:
public:
	explicit Settings4(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
