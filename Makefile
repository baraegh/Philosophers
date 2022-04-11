# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 23:11:23 by eel-ghan          #+#    #+#              #
#    Updated: 2022/04/06 01:06:12 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c check.c functions.c utils.c

OBJS = ${SRCS:.c=.o}

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

${NAME} : ${OBJS}
	${CC} -o ${NAME} ${OBJS} -l pthread
	@tput setaf 2; echo "PHILO IS READY"

all : ${NAME}

clean : 
	${RM} ${OBJS}
	@tput setaf 1; echo "OBJECTS REMOVED"

fclean : clean
	${RM} ${NAME}
	@tput setaf 1; echo "PHILO REMOVED"

re : fclean all

.PHONY : all clean fclean re