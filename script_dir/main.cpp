
#include "input.h"
#include <iostream>
#include "ScreenRef.hpp"
#include <unistd.h>

#define VISIT 0
#define ENTER_ID 1
#define FOUNTAIN 2
#define ATTACK_TURN 3
#define UNKNOWN_STATE 4
#define CLAIM_REWARD 5

int	getState(void)
{
	int state;

	if (Screen::CheckRef("MyHouse"))
	{
		if (Screen::CheckRef("Visit"))
			state = ENTER_ID;
		else
			state = VISIT;
	}
	else if (Screen::CheckRef("Fountain"))
		state = FOUNTAIN;
	else if	(Screen::CheckRef("Win"))
		state =	CLAIM_REWARD;
	else if (Screen::CheckRef("Attack"))
		state = ATTACK_TURN;
	else
		state = UNKNOWN_STATE;
	return state;
}

void	click(std::string loc)
{
	unsigned x, y;
	Screen::GetLoc(&x, &y, loc);
	MouseEvent(LEFT_MOUSE_DOWN, x, y);
	usleep(100000);
	MouseEvent(LEFT_MOUSE_UP, x, y);

	usleep(100000); // litterally clicking again because sometimes it doesnt register
        MouseEvent(LEFT_MOUSE_DOWN, x, y);
        usleep(100000);
        MouseEvent(LEFT_MOUSE_UP, x, y);
	
	usleep(1000000); // take a small pause
}

void	type(std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		Type(text[i]);
		usleep(200000);
	}
}

void	myScript(void) //enter your script here:
{

	//identify which state we are in
	int state;

	while (1)
	{
	
	while (1)
	{
		int states[3];
		states[0] = getState();
		usleep(300000);
		states[1] = getState();
		usleep(300000);
		states[2] = getState();
		
		if (states[0] == states[1] && states[0] == states[2])
		{
			state = states[0];
			break;
		}
	}


	if (state == VISIT)
	{
		click("VisitNeighbor");
	}
	else if (state == ENTER_ID)
	{
		click("TextInput");
		type("45387657");
		click("Specific");
	}
	else if (state == FOUNTAIN)
	{
		click("FullHeal");
		click("ToHouse");
	}
	else if (state == ATTACK_TURN)
	{
		click("Spells");
		click("BiggestFan");
	}
	else if (state == CLAIM_REWARD)
	{
		click("GetReward");
		usleep(1000000);
		click("LevelUp");
		usleep(1000000);
		click("ZToken");
		usleep(4000000);
		click("Town");
	}
	else if (state == UNKNOWN_STATE)
	{
		usleep(2000000);
	}
	}
}

int	main(void)
{
	std::string s;

	std::cout << "Type anything to set relative cursor position based on cursor location" << std::endl;
	std::cin >> s;
	Screen::SetRelativePosition();
	std::cout << "Type anything to begin your script" << std::endl;
	std::cin >> s;
	
	myScript();
}
