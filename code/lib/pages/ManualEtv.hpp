#ifndef MANUAL_ETV_CPP
#define MANUAL_ETV_CPP

#include "Page.hpp"
#include "PageController.hpp"

class ManualEtv : public Page {
private:
	int8_t _num = 1;

public:
	ManualEtv(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif
