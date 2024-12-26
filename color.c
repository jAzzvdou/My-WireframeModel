#include "fdf.h"

int	paint(int z, int zmin, int zmax)
{
	int		red;
	int		green;
	int		blue;
	float	calc;

	if (z == 0)
		return (0x00FF00);
	else if (z > 0 && z <= zmax)
	{
		calc = (float)z / zmax;
		red = 255 * calc;
		green = 255 - red;
		blue = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else if (z < 0 && z >= zmin)
	{
		calc = (float)z / zmin;
		blue = 255 * calc;
		green = 255 - blue;
		red = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else
		return (0x000000);
}
