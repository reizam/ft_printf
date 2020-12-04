SRC_DIR		= ./srcs/

SRC 		= ${SRC_DIR}ft_printf_puts.c ${SRC_DIR}ft_itoa.c ${SRC_DIR}ft_printf_flags.c ${SRC_DIR}ft_putnbr_base.c ${SRC_DIR}ft_printf_utils.c ${SRC_DIR}ft_printf.c ${SRC_DIR}ft_printf_type.c

OBJS 		= ${SRC:.c=.o}

NAME 		= libftprintf.a
TEST_NAME	= libftprintf

CC 			= gcc
AR 			= ar -rcs

CFLAGS 		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c -I./includes/ $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
		 	${AR} ${NAME} ${OBJS}

all: 		${NAME}

clean:
	   		rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean re bonus
