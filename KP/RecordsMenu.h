#pragma once
#include "Menu.h"
class RecordsMenu : public Menu
{
private:
	vector<Text> Records;
	Text RecordCaption;
public:
	void Draw() override;
	void Init(RenderWindow& Window, State& state) override;
};

