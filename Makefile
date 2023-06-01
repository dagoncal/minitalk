CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

INC = ./inc

SRC_C = client.c
SRC_S = server.c
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c
SRCS = 	utils/ft_atoi.c \
 		utils/ft_isdigit.c \
  		utils/ft_putnbr.c \
  		utils/ft_putstr.c \
  		utils/ft_straddc.c \
  		utils/ft_strdup.c \
  		utils/ft_strlen.c
OBJS = ${SRCS:.c=.o}
UTILS = libutilsminitalk.a
NAME = $(CLIENT) $(SERVER)
LIBC = ar rc
LIBR = ranlib

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -I $(INC) -c $< -o ${<:.c=.o}

all: mandatory

mandatory: utils
	$(CC) $(CFLAGS) -I $(INC) $(SRC_C) $(UTILS) -o $(CLIENT)
	$(CC) $(CFLAGS) -I $(INC) $(SRC_S) $(UTILS) -o $(SERVER)

bonus: utils
	$(CC) $(CFLAGS) -I $(INC) $(SRC_C_BONUS) $(UTILS) -o $(CLIENT);
	$(CC) $(CFLAGS) -I $(INC) $(SRC_S_BONUS) $(UTILS) -o $(SERVER);

utils: ${OBJS}
	${LIBC} ${UTILS} ${OBJS}
	${LIBR} ${UTILS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${UTILS} $(CLIENT) $(SERVER)

re: fclean all
