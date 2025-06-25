#ifndef EDIT_CLOCK_PAGE_CPP
#define EDIT_CLOCK_PAGE_CPP

#include "Page.hpp"
#include "PageController.hpp"

class EditClock final : public Page {
private:
	MyDateTime newTime;
	uint8_t editPhase;

public:
	explicit EditClock(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif//EDIT_CLOCK_PAGE_CPP
