CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

NAME = libft.a

SRC = ~/PJT/Libft/ft_isalpha.c \
	  ~/PJT/Libft/ft_isdigit.c \
	  ~/PJT/Libft/ft_isalnum.c \
	  ~/PJT/Libft/ft_isascii.c \
	  ~/PJT/Libft/ft_isprint.c \
	  ~/PJT/Libft/ft_strlen.c \
	  ~/PJT/Libft/ft_memset.c \
	  ~/PJT/Libft/ft_bzero.c \
	  ~/PJT/Libft/ft_memcpy.c \
	  ~/PJT/Libft/ft_memmove.c \
	  ~/PJT/Libft/ft_strlcpy.c \
	  ~/PJT/Libft/ft_strlcat.c \
	  ~/PJT/Libft/ft_toupper.c \
	  ~/PJT/Libft/ft_tolower.c \
	  ~/PJT/Libft/ft_strchr.c \
	  ~/PJT/Libft/ft_strrchr.c \
	  ~/PJT/Libft/ft_strncmp.c \
	  ~/PJT/Libft/ft_memchr.c \
	  ~/PJT/Libft/ft_memcmp.c \
	  ~/PJT/Libft/ft_strnstr.c \
	  ~/PJT/Libft/ft_atoi.c \
	  ~/PJT/Libft/ft_calloc.c \
	  ~/PJT/Libft/ft_strdup.c \
	  ~/PJT/Libft/ft_substr.c \
	  ~/PJT/Libft/ft_strjoin.c \
	  ~/PJT/Libft/ft_strtrim.c \
	  ~/PJT/Libft/ft_split.c \
	  ~/PJT/Libft/ft_itoa.c \
	  ~/PJT/Libft/ft_strmapi.c \
	  ~/PJT/Libft/ft_striteri.c \
	  ~/PJT/Libft/ft_putchar_fd.c \
	  ~/PJT/Libft/ft_putstr_fd.c \
	  ~/PJT/Libft/ft_putendl_fd.c \
	  ~/PJT/Libft/ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	rm $(OBJ)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME) $(OBJ)

re:
	fclean all
