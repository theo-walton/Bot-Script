
#include "input.h"
#include <iostream>
#include "ScreenRef.hpp"

int	main(void)
{
	std::string s;
	std::string n;
	
	std::cout << "Type anything to set relative cursor position based on cursor location" << std::endl;
	std::cin >> s;
	Screen::SetRelativePosition();

	while (!std::cin.eof())
	{
		s = "";
		n = "";
		std::cout << "Would you like to create a reference or location? type REF or LOC" << std::endl;
		std::cin >> s;
		std::cout << "NOTE: your reference / location will be created at your cursor location" << std::endl;
		std::cout << "      Enter a single word name to identify your reference / location" << std::endl;
		std::cin >> n;
		if (s == "REF")
		{
			Screen::MakeRef(n);
			std::cout << "reference created" << std::endl << std::endl;
		}
		else if (s == "LOC")
		{
			Screen::MakeLoc(n);
			std::cout << "location created" << std::endl << std::endl;
		}
		else
		{
			std::cout << "unable to create reference / location" << std::endl << std::endl;
		}
	}
}
