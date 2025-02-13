#ifndef SETTINGS6_CPP
#define SETTINGS6_CPP

#include "Page.hpp"

class Settings6 : public Page {
private:
	static constexpr const char* displayText = "Cambia giorni elettrovalvole";

public:
	explicit Settings6(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
