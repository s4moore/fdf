# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samoore <samoore@student.42london.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 12:40:32 by samoore           #+#    #+#              #
#    Updated: 2024/03/19 16:30:13 by samoore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = fdf.c colour_scheme_1.c colour_scheme_2.c colour_utils.c gfx_lines.c \
gfx_rotate.c main_functions.c utils_momentum.c main.c init_banner.c \
init_edges.c init.c init_points_and_sphere.c \
init_projections.c init_read_file.c utils_split.c utils_keysym.c \
utils_kill.c utils_misc.c utils_mouse.c init_check_files.c init_check_utils.c
OBJ_DIR = ./obj/
SRC_DIR = ./src/
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))
MLX_FLAGS = -Llibraries -lmlx -L/usr/include -lXext -lX11 -lm -lft -I.
C_FLAGS = -g3 -gdwarf-3 -w -Wall -Werror -Wextra
INCLUDES = -I/usr/include -Ilibraries 
REQUIRED_PKGS = libx11-dev libxext-dev

NAME = fdf
CC = cc

all: check_deps $(NAME) 

check_deps:
	@for pkg in $(REQUIRED_PKGS); do \
		if ! dpkg -s $$pkg >/dev/null 2>&1; then \
			echo "Installing missing package: $$pkg"; \
			sudo apt-get update && sudo apt-get install -y $$pkg; \
		else \
			echo "$$pkg is already installed"; \
		fi \
	done

$(NAME): $(OBJ_FILES)
	$(CC) $(C_FLAGS) -o $@ $^ $(MLX_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(C_FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

