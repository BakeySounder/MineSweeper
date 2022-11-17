#include "RecordsMenu.h"

void RecordsMenu::Init(RenderWindow& Window, State& state)
{
	this->window = &Window;
	this->state = &state;
	//Шрифт
	font.loadFromFile(FMain);
	// Создание текста для кнопок
	RecordCaption.setFont(font);
	RecordCaption.setCharacterSize(35);
	RecordCaption.setString(L"Таблица рекордов");
	RecordCaption.setOrigin(RecordCaption.getLocalBounds().width / 2.0, RecordCaption.getLocalBounds().height / 2.0);
	RecordCaption.setPosition(win_size.x / 2.0, win_size.y * 0.05);
	//for (int i = 0; i < 4; i++)
	//{
	//	Buttons[i] = Text();
	//	Buttons[i].setFont(font);
	//	Buttons[i].setCharacterSize(35);
	//	Buttons[i].setString(btn_name[i]);
	//	Buttons[i].setOrigin(Buttons[i].getLocalBounds().width / 2, Buttons[i].getLocalBounds().height / 2);
	//	Buttons[i].setPosition(win_size.x / 2.0, win_size.y / 2.0 + 50 * i);
	//}
}

void RecordsMenu::Draw()
{
	mouse_pos = Vector2f(Mouse::getPosition(*window));

	//for (int i = R; i < 4; i++)
	//{
	//	Buttons[i].setFillColor(sf::Color::White);

	//	window->draw(Buttons[i]);

	//}
	// При нажатии ESC Вернуться назад по меню
	EscReturn();

	window->draw(RecordCaption);
}


