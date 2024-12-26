#include "fdf.h"

int	revstrncmp(char *compare, char *argv, int n)
{
	int	i;
	int	ii;

	if (n == 0)
		return (0);
	i = 0;
	ii = 0;
	while (argv[i])
		i++;
	while (compare[ii])
		ii++;
	while (n--)
		if (argv[i--] != compare[ii--])
			return (1);
	return (0);
}

void	fill_fdf(t_fdf *fdf)
{
	int	big;

	big = nmax(fdf->height, fdf->width);
	fdf->zoom = 15 - ((big / 10) * 2);
	if (fdf->zoom < 2)
		fdf->zoom = 2;
	fdf->xaxis = ((WIDTH - MENU_WIDTH) / 2);
	fdf->yaxis = (HEIGHT / 2) - (fdf->height * fdf->zoom / 2);
	fdf->z = 1;
	fdf->angle = 0.8;
	fdf->projection = 0;
	fdf->start = 10;
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->color = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	if (argc != 2)
		return (write(2, "Usage: ./fdf <filename>.\n", 25));
	if (revstrncmp(".fdf", argv[1], 3))
		return (write(2, "Error! Not '.fdf'.\n", 19));
	fdf.height = -1;
	fdf.width = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error! Invalid File.\n", 22));
	fdf.matrix = read_map(fd, argv[1], &fdf);
	if (!fdf.matrix)
		return (write(2, "Error! Invalid Map.\n", 21));
	fill_fdf(&fdf);
	make_fdf(&fdf);
	return (0);
}
