# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:35:04 by omiroshn          #+#    #+#              #
#    Updated: 2018/06/29 18:35:06 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = omiroshn.filler
CC = clang
FILES = main malloc algo
LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SPEED = -O3
FLAGS = -Wall
HEADERS = -I./includes -I./libft/includes -I./ft_printf/includes

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re

$(NAME): libft/libft.a ft_printf/libftprintf.a $(OBJ)
	@echo "\033[36mLinking...\033[0m"
	@$(CC) -o $(NAME) $(FLAGS) $(SPEED) $(OBJ) $(CGFLAGS) $(FRAMEWORKS) libft/libft.a ft_printf/libftprintf.a
	@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
libft/libft.a:
	@make --no-print-directory -j3 -C $(LIBFT_DIR)
ft_printf/libftprintf.a:
	@make --no-print-directory -j3 -C $(PRINTF_DIR)
obj/%.o: src/%.c
	@$(CC) -o $@ $(FLAGS) $(SPEED) $(HEADERS) $(INCLUDES) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"
clean:
	@rm -f $(OBJ)
	@make --no-print-directory -j3 -C $(LIBFT_DIR) clean
	@make --no-print-directory -j3 -C $(PRINTF_DIR) clean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
fclean:
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@make --no-print-directory -j3 -C $(LIBFT_DIR) fclean
	@make --no-print-directory -j3 -C $(PRINTF_DIR) fclean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all
