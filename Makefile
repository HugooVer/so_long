NAME = so_long

CC = cc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

SRCS += main.c

SRCS_PATH = srcs/

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

INCLUDE = includes/
LIBFT_INCUDE = -I ${LIBFT_PATH}/includes

HEADERS = so_long.h

vpath %.h ${INCLUDE}

vpath %.c ${SRCS_PATH}

OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ${INCLUDE} ${LIBFT_INCUDE} ${LIBFT}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}

${OBJS}: ${OBJS_PATH}/%.o: %.c ${HEADERS} Makefile
	mkdir -p ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDE} ${LIBFT_INCUDE}

clean:
	${RM} -r ${OBJS_PATH}
	${MAKE} -C ${LIBFT_PATH} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re