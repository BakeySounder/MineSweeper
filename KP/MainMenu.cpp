#include "MainMenu.h"

void MainMenu::Init(RenderWindow& Window, State& state)
{
	this->window = &Window;
	this->state = &state;
	//Шрифт
	font.loadFromFile(FMain);
	// Создание текста для кнопок
	for (int i = 0; i < 4; i++)
	{
		Buttons[i] = Text(btn_name[i], font, 35);
		Buttons[i].setOrigin(Buttons[i].getLocalBounds().top, Buttons[i].getLocalBounds().top);
		Buttons[i].setPosition(win_size.x / 2.0- Buttons[i].getGlobalBounds().width/2.0, win_size.y / 2.0 + win_size.y * 0.1 * i);
	}
	// Параметры для квадрата выбора
	SelectionRect.setFillColor(Color::Transparent);
	SelectionRect.setOutlineColor(Color::White);
	SelectionRect.setOutlineThickness(5);
	//SelectionRect.setSize(Vector2f(5, 20));
	InitLogo();
}

void MainMenu::OnClick(int btnId)
{
	switch (btnId)
	{
	case 0:
		*state = State::GameSelect;
		break;
	case 1:
		*state = State::Records;
		break;
	case 2:

		break;
	case 3: 
		*state = State::Exit;
		window->close();
		break;
	}
}

void MainMenu::Draw()
{
	mouse_pos = Vector2f( Mouse::getPosition(*window) );
	for (int i = 0; i < 4; i++)
	{
		Buttons[i].setFillColor(sf::Color::White);
		if (Buttons[i].getGlobalBounds().contains(mouse_pos)) {
			// Отрисовка квадрата выбора
			SelectionRect.setPosition(Vector2f(Buttons[i].getGlobalBounds().left - win_size.x*0.01, Buttons[i].getGlobalBounds().top - win_size.y * 0.009));
			SelectionRect.setSize(Vector2f(Buttons[i].getGlobalBounds().width + win_size.x * 0.01 * 2, Buttons[i].getGlobalBounds().height + win_size.y *0.009*2));
			window->draw(SelectionRect);

			// Проверка на нажатие кнопки
			if (Mouse::isButtonPressed(Mouse::Left)) OnClick(i);
		}

		window->draw(Buttons[i]);
	}
	LogoDraw();
}


