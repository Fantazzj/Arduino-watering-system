#include "Page.hpp"

Page::Page(PageController& controller) :
	controller(controller) {}

PageNum Page::exec() { return Stay; }

void Page::show() {
	controller.display.printSimpleText("PAGINA GENERALE");
}
