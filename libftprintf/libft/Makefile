# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:59:09 by mdos-san          #+#    #+#              #
#    Updated: 2016/10/17 15:13:28 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

COMPILER=	gcc
FLAGS=		-Wall -Wextra -Werror -c
INCLUDES=	-I ./includes

SRC_C=		ft_memset.c		ft_bzero.c		ft_memcpy.c\
			ft_memccpy.c	ft_memmove.c	ft_memchr.c\
			ft_memcmp.c		ft_strlen.c		ft_strcpy.c\
			ft_strncpy.c	ft_strcat.c		ft_strncat.c\
			ft_strlcat.c	ft_strchr.c		ft_strrchr.c\
			ft_strstr.c		ft_strnstr.c	ft_strcmp.c\
			ft_strncmp.c	ft_isalpha.c	ft_isdigit.c\
			ft_isalnum.c	ft_isascii.c	ft_isprint.c\
			ft_toupper.c	ft_tolower.c	ft_atoi.c\
			ft_memalloc.c	ft_memdel.c		ft_strnew.c\
			ft_strdel.c		ft_strclr.c		ft_striter.c\
			ft_striteri.c	ft_strmap.c		ft_strmapi.c\
			ft_strequ.c		ft_strnequ.c	ft_strdup.c\
			ft_strsub.c		ft_strjoin.c	ft_strtrim.c\
			ft_putchar.c	ft_putchar_fd.c	ft_putstr.c\
			ft_putstr_fd.c	ft_putendl.c	ft_putendl_fd.c\
			ft_strsplit.c	ft_putnbr.c		ft_putnbr_fd.c\
			ft_itoa.c		ft_lstnew.c		ft_lstdelone.c\
			ft_lstdel.c		ft_lstadd.c		ft_lstiter.c\
			ft_lstmap.c		ft_lstnew_cpy.c	get_next_line.c\
			ft_lstpushb.c\
			str_array_new.c\
			str_array_count.c\
			str_array_dup.c\
			str_array_cpy.c\
			str_array_del.c\
			str_array_add.c\
			str_array_sub.c\
			str_array_find.c\
			ft_putnbrl.c

SRC_O=$(SRC_C:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "Creating libft.a..."
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)
	@echo "Done !"

%.o: %.c
	@echo "Compiling $<"
	@$(COMPILER) $(FLAGS) $(INCLUDES) $<

clean: 
	@echo "Removing *.o"
	@rm -rf $(SRC_O)
	@echo "Done"

fclean: clean
	@echo "Removing libft.a"
	@rm -rf $(NAME)
	@echo "Done"

re: fclean all

norm	:
	@norminette *.c includes
