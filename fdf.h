/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:36:20 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/12 16:48:09 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH		1920
# define HEIGHT		1080
# define MENU_WIDTH	150
# define BUFFER_SIZE	501

# include "./minilibx-linux/mlx.h" //| MiniLibX
# include <unistd.h>               //| WRITE, READ
# include <stdlib.h>               //| MALLOC, FREE, NULL
# include <fcntl.h>                //| OPEN, CLOSE
# include <math.h>                 //| SIN, COS, TAN...
# include <limits.h>               //| INT_MAX, INT_MIN...

//----------| DEFINES |----------//
# define ESC                65307
# define LEFT               65361
# define UP                 65362
# define RIGHT              65363
# define DOWN               65364
# define SPACE              32
# define A_KEY              97
# define D_KEY              100
# define W_KEY              119
# define S_KEY              115
# define E_KEY              101
# define Q_KEY              113
# define Z_KEY              122
# define X_KEY              120
# define M_KEY              109
# define N_KEY              110
# define ENTER_KEY          65293
# define PLUS_KEY           65451
# define MINUS_KEY          65453
# define KEY_PRESS_EVENT	02
# define MOUSE_PRESS_EVENT	04
# define DESTROY_EVENT		17
# define ENTER_EVENT		07

//----------| BRESENHAM STRUCT |----------//
typedef struct s_bresenham
{
	float	dx;
	float	dy;
	float	x[3];
	float	y[3];
	int		z[3];
}			t_bresenham;

//----------| MAIN STRUCT |----------//
typedef struct s_fdf
{
	int				projection;
	int				**matrix;
	int				xaxis;
	int				yaxis;
	double			angle;
	double			z;
	int				bpp;
	int				line_size;
	int				width;
	int				height;
	int				endian;
	int				start;
	int				zoom;
	char			*addr;
	void			*menu;
	void			*mlx;
	void			*win;
	void			*img;
	double			gamma;
	double			alpha;
	double			beta;
	unsigned int	color;
}					t_fdf;

//----------| FDF |----------//
int				**read_map(int fd, char *argv1, t_fdf *fdf);
void			fill_fdf(t_fdf *fdf);
int				make_fdf(t_fdf *fdf);
int				end_program(t_fdf *mlx);
int				rerender(t_fdf *fdf);

//----------| DRAW |----------//
void			my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void			put_points(t_fdf *fdf);
void			add_3d(t_bresenham *bres, t_fdf *fdf);
int				paint(int z, int zmin, int zmax);

//----------| HOOKS |----------//
int				key_hook(int keycode, t_fdf *mlx);
int				mouse_hook(int keycode, int x, int y, t_fdf *mlx);

//----------| BONUS |----------//
void			rotate(t_bresenham *bres, t_fdf *fdf);
void			add_steps(t_bresenham *bres);
void			add_position(t_bresenham *bres, t_fdf *fdf);
void			add_zoom(t_bresenham *bres, int zoom);

//----------| UTILS |----------//
int				nmax(int x, int y);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *nptr);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);

#endif //| FDF.
