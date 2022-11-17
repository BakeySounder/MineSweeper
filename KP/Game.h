#pragma once
#include "Menu.h"
class Game : public Menu
{
private:

public:
	void Draw() override;
	void Init(RenderWindow& Window, State& state) override;
};

