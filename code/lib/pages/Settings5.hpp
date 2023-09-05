#ifndef SETTINGS5_CPP
#define SETTINGS5_CPP

#include "Page.hpp"

class Settings5 : public Page {
private:
public:
	explicit Settings5(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
