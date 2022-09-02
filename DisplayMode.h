#pragma once
#include "Screen.h"

class DisplayMode : public Screen
{
public:
	DisplayMode();
	void TopUi() override;
	void View() override;
	void BottomUi() override;
	void DisplayLevel();
};

