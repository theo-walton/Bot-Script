#pragma once

#include "input.h"
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "lodepng.h"
#include <cmath>

class Screen
{
	static int _relativeX;
	static int _relativeY;
	
public:
	// sets relative position based on cursor location
	static void	SetRelativePosition(void);
	
	// makes screen reference based on cursor location and relative position
	// and stores it in name.REF and name.png
	static void	MakeRef(std::string name);
	
	// checks a stored reference to see if it matches current screen display
	static bool	CheckRef(std::string name);

	// makes a screen location based on cursor location and relative position
	// and stores it in name.LOC
	static void	MakeLoc(std::string name);

	// sets x and y to the absolute cursor location stored in name.LOC + relative pos
	static void	GetLoc(unsigned *x, unsigned *y, std::string name);
	
};
