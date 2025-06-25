#ifndef SETTINGS3_CPP
#define SETTINGS3_CPP

#include "Page.hpp"

class Settings3 final : public Page {
private:
	static constexpr const char* DISPLAY_TEXT = "Cambia orario di avvio";

public:
	explicit Settings3(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
