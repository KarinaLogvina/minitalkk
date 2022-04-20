# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karinalogvina <karinalogvina@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 21:58:02 by karinalogvi       #+#    #+#              #
#    Updated: 2022/04/19 22:27:17 by karinalogvi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME 	= server
CLIENT_NAME 	= client

NAME 			= minitalk

PRINTF 		 	= ./printf/libftprintf.a
HEADER			= minitalk.h

SERVER_SRC		= main_server.c
CLIENT_SRC		= main_client.c
SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

SERVER_SRC_BONUS		= ./bonus/server_bonus.c
CLIENT_SRC_BONUS		= ./bonus/client_bonus.c
SERVER_OBJ_BONUS		= $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS		= $(CLIENT_SRC_BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : print server client

all : $(NAME)

print:
	make -C printf
	
server: $(SERVER_OBJ) $(PRINTF)
		$(CC) $(CFLAGS) $(SERVER_OBJ) $(PRINTF) -o $(SERVER_NAME)
	
client: $(CLIENT_OBJ)  $(PRINTF)
		$(CC) $(CFLAGS) $(CLIENT_OBJ) $(PRINTF) -o $(CLIENT_NAME)
	
bonus :
	make "SERVER_OBJ=$(SERVER_OBJ_BONUS)" "CLIENT_OBJ=$(CLIENT_OBJ_BONUS)" all

clean :
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	make clean -C printf

fclean : clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	make fclean -C printf
	
%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@	

re : fclean all

.PHONY : all clean fclean re bonus