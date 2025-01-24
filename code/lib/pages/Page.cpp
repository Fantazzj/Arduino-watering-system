#include "Page.hpp"

Page::Page(PageController& controller) :
	_controller(controller) {}

PageNum Page::exec() { return Stay; }

void Page::show() {
	_controller.display.printSimpleText((char*) "PAGINA GENERALE");
}
