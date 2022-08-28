# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 13:37:19 by mealjnei          #+#    #+#              #
#    Updated: 2022/08/23 16:51:00 by mealjnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client
LIBFT = libft/libft.a

SRCS		= server.c client.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT) :
		@$(MAKE) -sC ./libft
$(NAME_SERVER) : $(LIBFT)
			$(CC) -o server server.c $(LIBFT)

$(NAME_CLIENT) : $(LIBFT)
			$(CC) -o client client.c $(LIBFT)

clean:
			rm -rf $(OBJS)
			@$(MAKE) -sC ./libft clean

fclean:		clean
			rm -rf $(NAME_SERVER) $(NAME_CLIENT)
			@$(MAKE) -sC ./libft fclean

re:			fclean all
			@$(MAKE) -sC ./libft re