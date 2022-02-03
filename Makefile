SRCS	= so_long.c

NAME	= so_long

MLX_PATH	= ./mlx

RM		= rm -f

CC		= gcc

all:		${NAME}

${NAME}:	makemlx
			${CC} -I ${MLX_PATH} ${SRCS} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

makemlx:
			${MAKE} -C ${MLX_PATH}

clean:
			${MAKE} clean -C ${LIBFT_PATH}
			${RM} ${NAME}

fclean:		clean
			${MAKE} fclean -C ${LIBFT_PATH}
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re makemlx
