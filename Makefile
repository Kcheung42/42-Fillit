# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcheung <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 00:16:37 by kcheung           #+#    #+#              #
#    Updated: 2016/12/13 12:35:33 by kcheung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
SRC_NAME =	main.c \
 			read.c \
			solve.c \
			helper.c \
			validate.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR),$(SRC_NAME:%.c=%.o))

LIB_PATH = ./libft/
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = ./includes/
INC = -I$(LIB_PATH)$(INC_DIR) -I$(INC_DIR)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: obj $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [$<] $(OK)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)
	@chmod 755 $@
	@echo "Compiling" [ $(NAME)] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p $(OBJ_DIR)
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)
re: fclean all
