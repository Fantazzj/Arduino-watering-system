#ifndef SETTINGS1_CPP
#define SETTINGS1_CPP

#include "Page.hpp"

class Settings1 : public Page {
private:
	static constexpr const char* displayText = "Cambia data e ora";

public:
	explicit Settings1(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
