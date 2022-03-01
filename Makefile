SRCS			= so_long.c store_img.c init_map.c check_map.c keyhook.c manage_move.c error.c error_init.c end.c 

INCLUDE 		= include/get_next_line.c include/get_next_line_utils.c 

FOLDER_SRCS 	= sources/

NAME			= so_long

MLX_PATH		= ./mlx

MLX				= ./mlx/libmlx.a

LIBFT 			= include/libftprintf.a

LIBFT_PATH		= ./include

RM				= rm -f

CC				= gcc

CFLAGS  		= -Wall -Wextra -Werror

SRC				= $(addprefix ${FOLDER_SRCS},${SRCS})

OBJS			= ${SRC:.c=.o}
OBJS_INCLUDE	= ${INCLUDE:.c=.o}

OBJ				= ${OBJS_INCLUDE} ${OBJS}

${NAME}:	${OBJ} ${MLX} ${LIBFT}
			${CC} -g -fsanitize=address ${CFLAGS} -I ${MLX_PATH} ${OBJ} ${LIBFT} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${MLX}:
			${MAKE} -C ${MLX_PATH}

${LIBFT}:
			${MAKE} -C ${LIBFT_PATH}

clean:
			${MAKE} clean -C ${LIBFT_PATH}
			${RM} ${OBJ}

fclean:		clean
			${MAKE} fclean -C ${LIBFT_PATH}
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re makemlx
