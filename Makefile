# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 13:18:32 by qcraghas          #+#    #+#              #
#    Updated: 2020/10/04 14:57:33 by qcraghas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEAD = cub3d.h
LIBHEAD = ./sources/libft.h
LIB = ./sources/libft.a
LIBMLX = ./libmlx.dylib

SRCS = cub3d.c map_main.c configuration_resolution.c map_valid.c \
		image_main.c data_init.c raycasting.c image_keys.c image_map.c \
		textures_init.c image_sprites.c configuration.c errors.c utils_1.c \
		configuration_color.c configuration_textures.c map_compose.c \
		image_draw.c screenshot.c textures_color.c \
		data_init_2.c utils_2.c

SRCO = cub3d.o map_main.o configuration_resolution.o map_valid.o \
		image_main.o data_init.o raycasting.o image_keys.o image_map.o \
		textures_init.o image_sprites.o configuration.o errors.o utils_1.o \
		configuration_color.o configuration_textures.o map_compose.o \
		image_draw.o screenshot.o textures_color.o \
		data_init_2.o utils_2.o

all: $(NAME)

$(SRCO): %.o:%.c $(HEAD)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRCO) $(HEAD)
	cd ./sources && make && cd ..
	cd ./mlx && make && cp libmlx.dylib ../ && cd ..
	gcc $(SRCO) -o $(NAME) -L. $(LIBMLX) $(LIB) -framework OpenGL -framework AppKit

clean:
	cd ./sources && make clean && cd ..
	cd ./mlx && make clean && cd ..
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME) $(LIB) $(LIBMLX)

bonus: all

re: fclean all

.PHONY: all clean fclean bonus re
