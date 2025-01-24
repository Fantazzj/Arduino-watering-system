#ifndef MANUAL_ETV_CPP
#define MANUAL_ETV_CPP

#include "Page.hpp"
#include "PageController.hpp"

class ManualEtv : public Page {
private:
	uint8_t _num = 1;

public:
	explicit ManualEtv(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
