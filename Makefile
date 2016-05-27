# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/24 13:25:36 by apellicc          #+#    #+#              #
#    Updated: 2016/05/27 08:27:15 by apellicc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra -Ofast -I includes

SRC = main.c \
	  mandelbrot.c \
	  julia.c \
	  burningship.c \
	  key.c \
	  zoom.c \
	  julia2.c \
	  mandelbrot2.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ)  -I libft/libft.h -I minilibx_macos/mlx.h -lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
