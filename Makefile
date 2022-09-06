# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: difool 				                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 10:01:18 by difool            #+#    #+#              #
#    Updated: 2022/09/06 14:34:37 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = srcs/main.c srcs/ft_bresenham.c srcs/matrices.c srcs/mlx.c srcs/parse.c srcs/draw.c srcs/event.c srcs/color.c
OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
INCLUDES = -I/usr/include -Iminilibx-linux/


OS := $(shell uname)
ifeq ($(OS), Darwin)
	LFLAGS = -lmlx -framework OpenGL -framework AppKit
else
	LFLAGS = -Lminilibx-linux -lmlx -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lbsd
endif

NAME = fdf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

####################################################################
####################################################################

$(NAME) : $(OBJS)
	$(MAKE) -s -C ./libft
	$(CC) -o $@ $(OBJS) $(LFLAGS) -Llibft/ -lft

all : $(NAME)

clean :
	$(MAKE) clean -s -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -s -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all linux
