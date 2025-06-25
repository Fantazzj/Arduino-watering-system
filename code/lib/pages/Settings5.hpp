#ifndef SETTINGS5_CPP
#define SETTINGS5_CPP

#include "Page.hpp"

class Settings5 final : public Page {
private:
	static constexpr const char* DISPLAY_TEXT = "Imposta memoria innaffiamento";

public:
	explicit Settings5(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
