#pragma once
#include "inc.h"
class Menu abstract 
{
protected:
	Event event;
	Font font;
	RenderWindow* window;
	State* state;
	Vector2f mouse_pos;
	Texture LogoTexture;
	Sprite LogoSprite;
	void EscReturn() {
		// При нажатии ESC Вернуться назад по меню
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			//cout << "Key esc pressed\n";
			*state = State::Main;
		}
	}
	void InitLogo() {
		LogoTexture.loadFromFile("resources/Logo.png");
		LogoSprite.setTexture(LogoTexture);
		const int LOGO_SIZE = 256;
		LogoSprite.setPosition(win_size.x/2 - LOGO_SIZE/2, win_size.y*0.02);
	}
	void LogoDraw() {
		window->draw(LogoSprite);
	}
public:
	virtual void Init(RenderWindow& Window, State& state) =0;
	virtual void Draw() = 0;
};

