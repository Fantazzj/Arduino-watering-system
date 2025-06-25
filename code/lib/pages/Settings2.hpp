#ifndef SETTINGS2_CPP
#define SETTINGS2_CPP

#include "Page.hpp"

class Settings2 final : public Page {
private:
	static constexpr const char* DISPLAY_TEXT = "Cambia tempo elettrovalvole";

public:
	explicit Settings2(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
