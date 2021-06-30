# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 16:15:27 by marcrodr          #+#    #+#              #
#    Updated: 2021/06/30 16:57:22 by marcrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
B_SIZE	=	32
FLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=B_SIZE
RM		=	rm -rf
LIB		=	ar -rcs
NAME	=	get_next_line.a

FILES	=	get_next_line.c\
			get_next_line_utils.c

all:	$(NAME)

clean:	$(RM) $(OBJS)

fclean:	$(RM) $(NAME)

re:		fclean all
