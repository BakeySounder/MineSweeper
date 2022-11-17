#pragma once
#include "Menu.h"
class GameMenu :public Menu
{
private:
	enum GameType
	{
		Basic, Midle, Expert, Custom
	};
	int SelectedMode = 0;
	wstring GameModes[3] = { L"�������",L"��������",L"�������" }; // L"����������������"
	pair<int,int> GameModeDesc[3]; // L"����������������"
	//String GameModes[3] = { "Beginner","Midle","Pro"};
	GameType GameMode;
	CircleShape Arrows[2];
	Text GameModeName,Desc,StartGame;
	RectangleShape SelectionRect;
	bool ToChange = true;
	float offset;
public:
	void Draw() override;
	void Init(RenderWindow& Window, State& state) override;
};

