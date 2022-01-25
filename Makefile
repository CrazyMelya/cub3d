SRC		= 	sources/main.c \
			sources/utils.c \
			sources/moves.c \
			sources/moves_2.c \
			sources/dda.c

BONUS_SRC =	bonus_sources/main.c \
			bonus_sources/doors.c \
			bonus_sources/utils.c \
			bonus_sources/moves.c 

NAME = cub3d

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
MLX =	minilibx_opengl/libmlx.a
LIB =  libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(SRC) lib mlx
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)
	@ echo $(NAME) compilation is OK!

bonus: $(BONUS_SRC) lib mlx
	@ gcc $(FLAGS) -o $(NAME) $(BONUS_SRC) $(LIB) $(MLX) $(FRAMEWORKS)
	@ echo $(NAME) compilation is OK!

lib:
	@ make -C libft/

mlx:
	@ make -C minilibx_opengl/

clean:
	@make -C minilibx_opengl/ clean
	@make -C libft/ clean

fclean: clean
	@ rm -rf $(NAME)
	@ make -C minilibx_opengl/ fclean
	@ make -C libft/ fclean

re: fclean all


norme:
	norminette *.c */*.c *.h */*.h

.PHONY: all clean fclean re