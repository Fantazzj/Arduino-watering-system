#ifndef EDIT_SR_WATERED_CPP
#define EDIT_SR_WATERED_CPP

#include "Page.hpp"

class EditSRWatered final : public Page {
private:
	bool watered;

public:
	explicit EditSRWatered(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
