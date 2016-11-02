# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/22 09:05:22 by mdos-san          #+#    #+#              #
#    Updated: 2016/10/22 09:57:25 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

CC		=	gcc
F		=	
I		=	-I./includes
L		=	-L./libs -lftprintf

S_C		=	main.c\
			lm_get.c\
			lm_start.c

S_O		=	$(S_C:%.c=%.o)

all:	$(NAME)
	
$(NAME):	libs libs/libftprintf.a\
			includes includes/libft.h includes/libftprintf.h\
			$(S_O)
	$(CC) -o $(NAME) $(F) $(I) $(S_O) $(L)

libs:
	mkdir libs
libs/libftprintf.a:	
	make re -C ./libftprintf
	mv ./libftprintf/libftprintf.a ./libs
	make fclean -C ./libftprintf
	
includes:
	mkdir includes
includes/libft.h:
	cp ./libftprintf/libft/includes/libft.h includes
includes/libftprintf.h:
	cp ./libftprintf/includes/libftprintf.h includes

%.o:	srcs/%.c
	$(CC) -c $(F) $(I) $< 


clean:
	rm -rf $(S_O)

fclean: clean
	rm -rf libs
	rm -rf includes/libftprintf.h includes/libft.h	
	rm -rf $(NAME)

re:	fclean all
