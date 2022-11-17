#include "Game.h"

void Game::Init(RenderWindow& Window, State& state)
{
	this->window = &Window;
	this->state = &state;
	//״נטפע
	font.loadFromFile(FMain);
}

void Game::Draw()
{
	mouse_pos = Vector2f(Mouse::getPosition(*window));
	EscReturn();
}


