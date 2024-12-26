#include "fdf.h"

static int	clean(char **temp_matrix, int **matrix, int count, int fd)
{
	int		i;
	char	*gnl;

	i = 0;
	while (temp_matrix[i])
	{
		free(temp_matrix[i]);
		i++;
	}
	free(temp_matrix);
	i = 0;
	while (i < count)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	while (1)
	{
		gnl = get_next_line(fd);
		free(gnl);
		if (!gnl)
			break ;
	}
	return (0);
}

int	testmap(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static int	fill_matrix(t_fdf *fdf, int **matrix, int fd)
{
	char	**temp_matrix;
	char	*mapping;
	int		i;
	int		temp_i;

	i = -1;
	while (++i < fdf->height)
	{
		mapping = get_next_line(fd);
		temp_matrix = my_split(mapping, ' ');
		free(mapping);
		if (testmap(temp_matrix) != fdf->width)
			return (clean(temp_matrix, matrix, i, fd));
		temp_i = -1;
		matrix[i] = (int *)malloc(sizeof(int) * fdf->width);
		while (++temp_i < fdf->width)
		{
			matrix[i][temp_i] = my_atoi(temp_matrix[temp_i]);
			free(temp_matrix[temp_i]);
		}
		free(temp_matrix);
	}
	mapping = get_next_line(fd);
	return (free(mapping), 1);
}

int	**create_matrix(int fd, char *argv1, t_fdf *fdf)
{
	int	**matrix;

	fd = open(argv1, O_RDONLY);
	matrix = (int **)malloc(sizeof(int *) * fdf->height);
	if (!fill_matrix(fdf, matrix, fd))
		return (NULL);
	close(fd);
	return (matrix);
}

int	**read_map(int fd, char *argv1, t_fdf *fdf)
{
	char	*line;
	char	**matrix;
	int		i;

	i = -1;
	line = get_next_line(fd);
	if (line)
	{
		fdf->height += 1;
		matrix = my_split(line, ' ');
		while (matrix[++i])
		{
			fdf->width += 1;
			free(matrix[i]);
		}
		free(line);
		free(matrix);
	}
	while (line && fdf->height >= 0)
	{
		fdf->height += 1;
		line = get_next_line(fd);
		free(line);
	}
	return (close(fd), create_matrix(fd, argv1, fdf));
}
