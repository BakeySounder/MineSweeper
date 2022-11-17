#include "inc.h"
#include "Menu.h"
#include "MainMenu.h"
#include "RecordsMenu.h"
#include "GameMenu.h"
#include "Game.h"


//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // отрубить консоль
//TODO
// Поменять лого(текст с ошибкой)

int main() {
	Event event;
	map <State, Menu*> menus;
	Color BackGround_clr(34, 34, 34);
	State MenuState = State::Main;
	
	// Создание объектов менюшек
	menus[State::Main] = new MainMenu();
	menus[State::Records] = new RecordsMenu();
	menus[State::GameSelect] = new GameMenu();
	menus[State::PlayGame] = new Game();

	RenderWindow window(VideoMode(800, 600), "MineSweeper", Style::Titlebar | Style::Close);
	window.setFramerateLimit(15);

	//Инициализация менюшек
	for (auto i = menus.begin() ; i != menus.end(); i++)
		(i->second)->Init(window, MenuState);

	while (window.isOpen()) {
		while (window.pollEvent(event)) 
			if (event.type == Event::Closed) window.close();
			
		window.clear(BackGround_clr);

		// отрисовка нужной менюшки
		menus[MenuState]->Draw();
		//cout << "CurrentState:" << MenuState << endl;

		window.display();
	}
}