# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barae <barae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 23:11:23 by eel-ghan          #+#    #+#              #
#    Updated: 2022/04/19 03:11:18 by barae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c check_args.c utils00.c utils01.c

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