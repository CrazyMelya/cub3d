SRC			= 	sources/main.c \
				sources/utils.c \
				sources/moves.c \
				sources/moves_2.c \
				sources/dda.c \
				sources/init.c \
				sources/parser/ft_error.c \
				sources/parser/map_filing.c\
				sources/parser/file_checking.c \
				sources/parser/player_pos_check.c \
				sources/parser/walls_checking.c \
				sources/parser/params_dealing.c \
				sources/parser/map_reading.c \
				sources/parser/parser.c \
				sources/parser/utils.c

BONUS_SRC	=	bonus_sources/main.c \
				bonus_sources/doors.c \
				bonus_sources/dda.c \
				bonus_sources/draw_utils.c \
				bonus_sources/draw_mini_map.c \
				bonus_sources/utils.c \
				bonus_sources/utils2.c \
				bonus_sources/moves.c \
				bonus_sources/moves2.c \
				bonus_sources/init.c \
				bonus_sources/init_cube.c \
				bonus_sources/parser/ft_error.c \
				bonus_sources/parser/map_filing.c\
				bonus_sources/parser/file_checking.c \
				bonus_sources/parser/player_pos_check.c \
				bonus_sources/parser/walls_checking.c \
				bonus_sources/parser/params_dealing.c \
				bonus_sources/parser/map_reading.c \
				bonus_sources/parser/parser.c \
				bonus_sources/parser/utils.c

NAME		=	cub3d

FRAMEWORKS	=	-lmlx -framework OpenGL -framework AppKit
MLX			=	minilibx_opengl/libmlx.a
LIB			= 	libft/libft.a
FLAGS		=	-Wall -Wextra -Werror

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