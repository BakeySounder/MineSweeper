#pragma once
#include "Menu.h"
class MainMenu : public Menu
{
private:
	Text Buttons[4];
	wstring btn_name[4] = { L"Играть",L"Рекорды",L"Настройки",L"Выйти" };
	RectangleShape SelectionRect;
	void OnClick(int btnId);
public:
	void Draw() override;
	void Init(RenderWindow& Window, State& state) override;

};

