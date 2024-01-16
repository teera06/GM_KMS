#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();



	switch (Select)
	{
	case 'A':
	case 'a':
		dir = Left;
		if (nextdir != dir) {
			AddPos(dir);
			nextdir = Right;
		}
		break;
	case 'S':
	case 's':
		dir = Down;
		if (nextdir != dir) {
			AddPos(dir);
			nextdir = Up;
		}
		break;
	case 'W':
	case 'w':
		dir = Up;
		if (nextdir != dir) {
			AddPos(dir);
			nextdir = Down;
		}
		break;
	case 'D':
	case 'd':
		dir = Right;
		if (nextdir != dir) {
			AddPos(dir);
			nextdir = Left;
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}
}