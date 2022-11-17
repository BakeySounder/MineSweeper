#include "GameMenu.h"

void GameMenu::Init(RenderWindow& Window, State& state)
{
	this->window = &Window;
	this->state = &state;
	offset = win_size.y * 0.08;
	InitLogo();

	//Шрифт
	font.loadFromFile(FMain);

	Arrows[0] = CircleShape(15, 3);
	Arrows[0].setPosition(win_size.x/2-win_size.x*0.15, 
		win_size.y/2 + offset + Arrows[0].getRadius());
	Arrows[0].setFillColor(Color::White);
	Arrows[0].rotate(-90);

	Arrows[1] = CircleShape(15, 3);
	Arrows[1].setPosition(win_size.x / 2 + win_size.x * 0.15, 
		win_size.y / 2 + offset -Arrows[1].getRadius());
	Arrows[1].setFillColor(Color::White);
	Arrows[1].rotate(90);

	GameModeName.setCharacterSize(30);
	GameModeName.setFont(font);

	GameModeDesc[0] = {10,10};
	GameModeDesc[1] = { 40,40};
	GameModeDesc[2] = { 99,99 };

	Desc.setCharacterSize(18);
	Desc.setFont(font);
	Desc.setPosition(win_size.x / 2 - win_size.x * 0.25, 
		win_size.y / 2.0 + win_size.y * 0.07 + offset);
	
	StartGame.setCharacterSize(35);
	StartGame.setFont(font);
	StartGame.setString(L"Начать игру");
	StartGame.setOrigin(StartGame.getLocalBounds().top, StartGame.getLocalBounds().top);

	StartGame.setPosition(win_size.x / 2- StartGame.getGlobalBounds().width / 2.0,
		win_size.y / 2 + win_size.y * 0.15 + offset);

	SelectionRect.setFillColor(Color::Transparent);
	SelectionRect.setOutlineColor(Color::White);
	SelectionRect.setOutlineThickness(5);


}

void GameMenu::Draw()
{
	LogoDraw();
	EscReturn();

	mouse_pos = Vector2f(Mouse::getPosition(*window));

	Arrows[0].setFillColor(sf::Color::White);
	Arrows[1].setFillColor(sf::Color::White);

	if (Arrows[0].getGlobalBounds().contains(mouse_pos)) {
		// Проверка на нажатие кнопки
		if (Mouse::isButtonPressed(Mouse::Left) ) {
			if (ToChange) {
				if (SelectedMode == 0) SelectedMode = 2;
				else SelectedMode -= 1;
				ToChange = false;
			}
		}else ToChange = true;
		Arrows[0].setFillColor(Color::Cyan);
	}
	if (Arrows[1].getGlobalBounds().contains(mouse_pos)) {
		// Проверка на нажатие кнопки
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (ToChange) {
				if (SelectedMode == 2) SelectedMode = 0;
				else SelectedMode += 1;
				ToChange = false;
			}
		}else ToChange = true;
		Arrows[1].setFillColor(Color::Cyan);
	}
	if (StartGame.getGlobalBounds().contains(mouse_pos)) {
		// Отрисовка квадрата выбора
		SelectionRect.setPosition(Vector2f(StartGame.getGlobalBounds().left - win_size.x * 0.01, StartGame.getGlobalBounds().top - win_size.y * 0.009));
		SelectionRect.setSize(Vector2f(StartGame.getGlobalBounds().width + win_size.x * 0.01 * 2, StartGame.getGlobalBounds().height + win_size.y * 0.009 * 2));
		window->draw(SelectionRect);

		// Проверка на нажатие кнопки
		if (Mouse::isButtonPressed(Mouse::Left)) {
			*state = State::PlayGame;
		};
	}

	window->draw(Arrows[0]);
	window->draw(Arrows[1]);
	window->draw(Arrows[0]);
	GameModeName.setString(GameModes[SelectedMode]);
	GameModeName.setOrigin(GameModeName.getLocalBounds().top, GameModeName.getLocalBounds().top);
	GameModeName.setPosition(win_size.x / 2.0 - GameModeName.getGlobalBounds().width / 2.0 + win_size.x*0.01, win_size.y / 2.0 - GameModeName.getGlobalBounds().height/2.0 + offset);
	window->draw(GameModeName);

	Desc.setString(L"Кол-во мин: " + to_string(GameModeDesc[SelectedMode].first) + "    " + L"Время игры: " + to_string(GameModeDesc[SelectedMode].second) + L" мин.");
	window->draw(Desc);
	window->draw(StartGame);
}

