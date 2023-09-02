#include "Keypad.hpp"

bool Keypad::cancel() { return cancelState; }
bool Keypad::down() { return downState; }
bool Keypad::up() { return upState; }
bool Keypad::confirm() { return confirmState; }
bool Keypad::generalPressed() { return cancelState || downState || upState || confirmState; }
