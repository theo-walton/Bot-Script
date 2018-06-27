#include "ScreenRef.hpp"

int	Screen::_relativeX = 0;
int	Screen::_relativeY = 0;

//return vector is always of length 12: RGB RGB
//					RGB RGB
static std::vector<double>	getImageScore(std::vector<unsigned char> &data,
					      unsigned width,
					      unsigned height)
{
	std::vector<double> out(12);
	
	int total = 0;	
	for (size_t x = 0; x < width / 2; x++)
	{
		for (size_t y = 0; y < height / 2; y++)
		{
			out[0] += data[(x + x * y) * 4 + 0];
			out[1] += data[(x + x * y) * 4 + 1];
			out[2] += data[(x + x * y) * 4 + 2];
			total++;
		}
	}
	out[0] /= total;
	out[1] /= total;
	out[2] /= total;

	total = 0;
	for (size_t x = width / 2; x < width; x++)
	{
		for (size_t y = 0; y < height / 2; y++)
		{
			out[3] += data[(x + x * y) * 4 + 0];
			out[4] += data[(x + x * y) * 4 + 1];
			out[5] += data[(x + x * y) * 4 + 2];
			total++;
		}
	}
	out[3] /= total;
	out[4] /= total;
	out[5] /= total;

	total = 0;
	for (size_t x = 0; x < width / 2; x++)
	{
		for (size_t y = height / 2; y < height; y++)
		{
			out[6] += data[(x + x * y) * 4 + 0];
			out[7] += data[(x + x * y) * 4 + 1];
			out[8] += data[(x + x * y) * 4 + 2];
			total++;
		}
	}
	out[6] /= total;
	out[7] /= total;
	out[8] /= total;

	total = 0;
	for (size_t x = width / 2; x < width; x++)
	{
		for (size_t y = height / 2; y < height; y++)
		{
			out[9] += data[(x + x * y) * 4 + 0];
			out[10] += data[(x + x * y) * 4 + 1];
			out[11] += data[(x + x * y) * 4 + 2];
			total++;
		}
	}
	out[9] /= total;
	out[10] /= total;
	out[11] /= total;

	return out;
}


// 0 is no match, 1 is good match. returns all numbers in between
static double	compareImages(std::string png1, std::string png2)
{
	unsigned width1, width2;
	unsigned height1, height2;
	std::vector<unsigned char> imageData1, imageData2;

	lodepng::decode(imageData1, width1, height1, png1.c_str());
	lodepng::decode(imageData2, width2, height2, png2.c_str());

	std::vector<double> score1 = getImageScore(imageData1, width1, height1);
	std::vector<double> score2 = getImageScore(imageData2, width2, height2);

	std::vector<double> diff(12);

	for (size_t i = 0; i < 12; i++)
		diff[i] = fabs(score1[i] - score2[i]) / 255.0;

	std::sort(diff.begin(), diff.end());

	double out = 0;
	
	for (size_t i = 0; i < 12; i++)
		out += (1 - diff[i]) * ((11.5 - i) / 6.0);
	out /= 12.0;
	return out;
}

void	Screen::SetRelativePosition(void)
{
	MousePosition((unsigned int*)&_relativeX, (unsigned int*)&_relativeY);
}

void	Screen::MakeRef(std::string name)
{
	std::string imPath = "ScreenRefs/" + name + ".png";
	std::string refPath = "ScreenRefs/" + name + ".REF";

	int x, y;
	MousePosition((unsigned int*)&x, (unsigned int*)&y);

	ImageAt(x, y, imPath.c_str());

	x -= _relativeX;
	y -= _relativeY;
	
	std::ofstream refFile(refPath);
	refFile << x << " " << y;
	refFile.close();
}

bool	Screen::CheckRef(std::string name)
{
	std::string imPath = "ScreenRefs/" + name + ".png";
	std::string refPath = "ScreenRefs/" + name + ".REF";
	int refx;
	int refy;
	
	std::ifstream refFile(refPath);
	refFile >> refx >> refy;
	refFile.close();

	ImageAt(refx + _relativeX, refy + _relativeY, ".compare.png");

	bool ret;
	
	if (compareImages(".compare.png", imPath.c_str()) > 0.9)
		ret = true;
	else
		ret = false;

	remove(".compare.png");
	return ret;
}

void	Screen::MakeLoc(std::string name)
{
	std::string locPath = "ScreenRefs/" + name + ".LOC";

	int x, y;
	MousePosition((unsigned int*)&x, (unsigned int*)&y);

	x -= _relativeX;
	y -= _relativeY;

	std::ofstream locFile(locPath);
	locFile << x << " " << y;
	locFile.close();
}

void	Screen::GetLoc(unsigned *x, unsigned *y, std::string name)
{
	std::string locPath = "ScreenRefs/" + name + ".LOC";
	int locx, locy;
	
	std::ifstream locFile(locPath);
	locFile >> locx >> locy;
	locFile.close();

	locx += _relativeX;
	locy += _relativeY;
	*x = (unsigned)locx;
	*y = (unsigned)locy;
}
