NAME = so_long

CC = cc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g3


SRCS += main.c
SRCS += data_set.c
SRCS += map_check.c
SRCS += error_management.c

SRCS_PATH = srcs/

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a
MLX_PATH = minilibx-linux/
MINILIBX += ${MLX_PATH}/libmlx_Linux.a
MINILIBX += ${MLX_PATH}/libmlx.a
MINILIBX_TAR += minilibx-linux.tgz
MINILIBX_LINK += https://cdn.intra.42.fr/document/document/15086/${MINILIBX_TAR}

INCLUDE = includes/
LIB_INCUDE = -I ${LIBFT_PATH}/includes
LIB_INCUDE += -I ${MLX_PATH}
LIB_INCUDE += -I /usr/include/X11/

LINKS += -Lminilibx-linux -lmlx_Linux
LINKS += -L/usr/lib -lXext -lX11 -lm -lz

HEADERS = so_long.h

vpath %.h ${INCLUDE}

vpath %.c ${SRCS_PATH}

OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}

all: ${MINILIBX} ${NAME}

${NAME}:  ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ${INCLUDE} ${LIB_INCUDE} ${LIBFT}

${MINILIBX_TAR}:
	wget ${MINILIBX_LINK}
	tar -zxvf ${MINILIBX_TAR}
#	${RM} ${MINILIBX_TAR}

${MINILIBX}: ${MINILIBX_TAR}
	${MAKE} -sC ${MLX_PATH}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}

${OBJS}: ${OBJS_PATH}/%.o: %.c ${HEADERS} Makefile
	mkdir -p ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDE} ${LIB_INCUDE} -O3

clean:
	${RM} -r ${OBJS_PATH}
	${RM} ${MINILIBX_TAR}
	${MAKE} -C ${MLX_PATH} clean
	${MAKE} -C ${LIBFT_PATH} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_PATH} fclean

re: fclean
	${MAKE}
	${MAKE} -C ${MLX_PATH} re

.PHONY: all clean fclean re