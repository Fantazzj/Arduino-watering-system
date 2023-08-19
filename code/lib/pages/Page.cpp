#include "Page.hpp"

Page::Page(PageController* controller) {
	_controller = controller;
}

Page::~Page() {
	
}

PageNum Page::exec() { return Stay; }

void Page::show() {
	_controller->displayPrint((char*) "PAGINA GENERALE");
}
