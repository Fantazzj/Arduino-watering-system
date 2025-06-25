#ifndef MANUAL_ETV_CPP
#define MANUAL_ETV_CPP

#include "Page.hpp"
#include "PageController.hpp"

class ManualEtv final : public Page {
private:
	int8_t num;

public:
	explicit ManualEtv(PageController& controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif
