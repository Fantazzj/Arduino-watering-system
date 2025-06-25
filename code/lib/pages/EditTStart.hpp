#ifndef EDIT_T_START_CPP
#define EDIT_T_START_CPP

#include "Page.hpp"

class EditTStart final : public Page {
private:
	MyTime newTime;
	uint8_t editPhase;

public:
	explicit EditTStart(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
