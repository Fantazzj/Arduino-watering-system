#pragma once

#include "clay.h"

struct DebuggerInfo {
	const char* text{nullptr};
	int32_t len{0};
};

class ClayDebuggerUi {
public:
	explicit ClayDebuggerUi(uint16_t textId);
	void draw(const DebuggerInfo& info) const;

	static constexpr uint16_t TEXT_SIZE = 30;

private:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};

	Clay_TextElementConfig textConfig;
};
