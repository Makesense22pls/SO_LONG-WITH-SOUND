# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/06/18 15:43:02 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f
# SRC = EXEMPLE.c
SRC = exec/image_player.c exec/text_and_resume.c utils/free.c utils/innit.c parsing/flood_fill.c exec/sound_and_change_image.c.c exec/direction_key.c exec/key_press.c parsing/check_arg.c parsing/check_fd/full_map.c exec/main.c parsing/check_fd/check_place.c exec/image.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = exec/image_player.c exec/text_and_resume.c utils/free.c utils/innit.c parsing/flood_fill.c exec/sound_and_change_image.c.c exec/direction_key.c exec/key_press.c parsing/check_arg.c parsing/check_fd/full_map.c exec/main.c parsing/check_fd/check_place.c exec/image.c
OBJ_BONUS = $(SRC:.c=.o)

#LIB
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

#HEADERS
HEADERS_MLX42 = $(MLX42_DIR)/include/MLX42
HEADERS_GLFW = /Users/mafourni/homebrew/opt/glfw/lib
HEADERS_LIB = $(LIBFT_DIR)


# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 to compil

# bonus : all $(LIBFT_LIB) $(MLX42_LIB) $(NAME_BONUS)

all : $(LIBFT_LIB) $(MLX42_LIB) $(NAME)


$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o: %.c
	gcc $(CFLAGS) -I. -I$(HEADERS_MLX42) -I$(HEADERS_GLFW) -I$(HEADERS_LIB) -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -I$(HEADERS_MLX42) -L$(HEADERS_GLFW) -I$(HEADERS_LIB) -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -o $@

$(NAME_BONUS): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -I$(HEADERS_MLX42) -L$(HEADERS_GLFW) -I$(HEADERS_LIB) -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean 

re: fclean all