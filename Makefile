# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:17:18 by dduarte-          #+#    #+#              #
#    Updated: 2023/05/08 09:36:12 by dduarte-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	get.a

SRC =	get_next_line.c	get_next_line_utils.c

OBJS = ${SRC:.c=.o}

HEADER = get_next_line.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
BS = 42
CFLAGSB = -Wall -Wextra -Werror	-D BUFFER_SIZE=${BS}
INCLUDE = -I .
GREEN	= \033[0;92m

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS} ${HEADER}
		echo "${GREEN}COMPILING : ${OBJS}, ${HEADER} to ${NAME}"

all:	${NAME}

clean:
		${RM} ${OBJS}
		echo "${GREEN}FILES DELETED: ${OBJS}"

fclean: clean
		${RM} ${NAME}
		echo "${GREEN}${NAME}"

re: fclean all
		echo "${GREEN}Rebuilding..."

.PHONY: all clean fclean re

.SILENT: