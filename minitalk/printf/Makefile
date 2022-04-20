# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urosby <urosby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 17:47:14 by urosby            #+#    #+#              #
#    Updated: 2021/12/24 20:30:04 by urosby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c	ft_print.c ft_put.c ft_utils.c ft_u.c

OBJS = $(LIST:.c=.o)

HEADER = ft_printf.h

MAKEFILE = Makefile

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

%.o : %.c	$(HEADER) $(MAKEFILE)
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
