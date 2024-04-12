NAME	=	fdf

SRCS	=	main.c            \
		parse_map.c       \
		screen.c          \
		color.c           \
		bresenham.c       \
		bresenham_utils.c \
		hooks.c           \
		exit.c            \
		get_next_line.c   \
		rotate.c          \
		utils.c           \
		utils2.c          \

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-g -Wall -Werror -Wextra

RM	=	rm -rf

MLX	=	minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(SRCS) $(MLX) -o $(NAME) -Imlx_linux -lXext -lX11 -lm

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
