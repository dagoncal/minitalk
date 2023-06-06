CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CLIENT = client
SERVER = server

INC = ./inc

SRC_C = client.c
SRC_S = server.c
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c
SRCS = 	utils/ft_atoi.c \
 		utils/ft_isdigit.c \
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
	${CC} ${CFLAGS} -I $(INC) -I $(FT_PRINTF_DIR) -c $< -o ${<:.c=.o}

all: mandatory

mandatory: utils
	$(CC) $(CFLAGS) -I $(INC) -I $(FT_PRINTF_DIR) $(SRC_C) $(UTILS) $(FT_PRINTF) -o $(CLIENT)
	$(CC) $(CFLAGS) -I $(INC) -I $(FT_PRINTF_DIR) $(SRC_S) $(UTILS) $(FT_PRINTF) -o $(SERVER)

bonus: utils
	$(CC) $(CFLAGS) -I $(INC) -I $(FT_PRINTF_DIR) $(SRC_C_BONUS) $(UTILS) $(FT_PRINTF) -o $(CLIENT);
	$(CC) $(CFLAGS) -I $(INC) -I $(FT_PRINTF_DIR) $(SRC_S_BONUS) $(UTILS) $(FT_PRINTF) -o $(SERVER);

printf:
	$(MAKE) -C $(FT_PRINTF_DIR)

utils: printf ${OBJS}
	${LIBC} ${UTILS} ${OBJS}
	${LIBR} ${UTILS}

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	${RM} ${OBJS}

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	${RM} ${UTILS} $(CLIENT) $(SERVER)

re: fclean all
	$(MAKE) -C $(FT_PRINTF_DIR) re
