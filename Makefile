NAME	=	philo

CC		=	gcc

FLAG	=	-Wall -Wextra #-Werror

LIB		=	-pthread

SRCS	=	srcs/philo.c \
			srcs/utils.c \
			srcs/init.c

HEADER	=	-I /includes

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${FLAG} ${HEADER} -c $< -o ${<:.c=.o}

all:		philo

philo:		${OBJS}
				${CC} ${FLAG} ${LIB} ${HEADER} ${OBJS} -o ${NAME}

clean:		
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean	all

.PHONY:		all clean fclean re philo