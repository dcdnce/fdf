SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strlcpy.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_atoi.c ft_calloc.c\
ft_strncmp.c ft_tolower.c ft_toupper.c ft_striteri.c \
ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
\
get_next_line.c  \
ft_printf.c ft_printf_utils.c ft_printf_utils2.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $@ $^
	@echo ">> $(NAME_GREEN) make all $(OK_STRING)"

all: $(NAME)

clean:
	rm -f $(OBJS)
	@echo ">> $(NAME_GREEN) make clean $(OK_STRING)"

fclean: clean
	rm -f $(NAME)
	@echo ">> $(NAME_GREEN) make fclean $(OK_STRING)"

re: fclean all

.PHONY: all clean fclean bonus re

#COLORS
NAME_GREEN=$(OK_COLOR)[$(NAME)]$(NO_COLOR)
NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)
