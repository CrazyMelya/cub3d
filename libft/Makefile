SRCS =	ft_bzero.c		ft_atoi.c		ft_isalnum.c	ft_strlcat.c\
		ft_tolower.c	ft_isascii.c	ft_toupper.c	ft_isprint.c\
		ft_bzero.c		ft_isalpha.c	ft_isdigit.c	ft_memccpy.c\
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memmove.c\
		ft_memset.c		ft_strlcpy.c	ft_strlen.c		ft_strchr.c\
		ft_strrchr.c	ft_strncmp.c	ft_strnstr.c	ft_strdup.c\
		ft_calloc.c		ft_putchar_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c\
		ft_substr.c		ft_strjoin.c	ft_itoa.c		ft_split.c \
		ft_strmapi.c	ft_putendl_fd.c	get_next_line.c get_next_line_utils.c\
		ft_strchr2.c	libft.h

OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ ar rcs $(NAME) $(OBJS)

%.o: %.c %libft.h
	@ gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@ rm -rf *.o

fclean:
	rm -rf *.o $(NAME) 

re: fclean all
