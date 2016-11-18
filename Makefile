# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/14 15:32:58 by akaragoz          #+#    #+#              #
#    Updated: 2016/11/18 16:57:17 by akaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPATH = obj
CPATH = srcs
HPATH = includes/

MLX = -L mlx/ -lmlx -framework OpenGL -framework AppKit
CC = /usr/bin/gcc -g
MKDIR = /bin/mkdir
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

HEADER = fdf.h

SRC =	main.c\
	 	read.c\
	 	draw.c\
	 	key_events.c\
		mouse_events.c\
		put_pixel_to_img.c\
		hud.c

OFILES = $(patsubst %.c,$(OPATH)/%.o, $(SRC))

all:$(OPATH) $(NAME)

$(NAME): $(OFILES)
	@make -j8 -C libft/
	@make -j8 -C mlx/
	@$(CC) $(CFLAGS) -o $(NAME) $(MLX) $^ -I$(HPATH) -Llibft -Ilibft -lft

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) $(CFLAGS) -I$(HPATH) -o $@ -c $< -Ilibft

clean:
	@make clean -C libft/
	@$(RM) -rf $(OPATH)

fclean: clean
	@make fclean -C libft/
	@$(RM) -f $(NAME)

re: fclean all

$(OPATH):
	@$(MKDIR) $(OPATH)

.PHONY: all clean fclean re
