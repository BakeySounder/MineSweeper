#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include <map>
using namespace std;
using namespace sf;
#define win_size window->getSize()

#define FMain "resources/JetBrainsMono-SemiBold.ttf"

enum State
{
	Main,GameSelect,PlayGame,Records,Settings,Exit
};



