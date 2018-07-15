# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:20:35 by omiroshn          #+#    #+#              #
#    Updated: 2018/01/31 17:20:40 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname)
NAME = libftprintf.a
CC = gcc
LIBFT = ft_atoi \
		ft_bzero \
		ft_countwords \
		ft_isalpha \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_itoa_base \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap \
		ft_memset \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_memalloc \
		ft_memdel \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putnbr \
		ft_putstr \
		ft_putstr_fd \
		ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_toupper \
		ft_tolower \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strtrim \
		ft_strsplit \
		get_next_line \
		ft_atoi_base \
		rgb_to_int \
		rgb_smooth

LIBFT_PRINTF =  ft_printf \
				print_d \
				print_u \
				print_o \
				print_lo \
				print_x \
				print_lx \
				print_p \
				print_ls \
				print_s \
				print_c \
				print_percent \
				print_else \
				printf_cast \
				printf_parse \
				printf_countlength \
				printf_isflags \
				printf_unicode \
				printf_itoa_u

OBJ = $(addprefix obj/, $(addsuffix .o, $(LIBFT)))
OBJ_PRINTF = $(addprefix obj/, $(addsuffix .o, $(LIBFT_PRINTF)))
OBJ_LIST = $(addsuffix .o, $(LIBFT))
OBJ_LIST_PRINTF = $(addsuffix .o, $(LIBFT_PRINTF))
HEADERS = -I./includes

ifeq ($(OS), Linux)
FLAGS =
else
FLAGS = -Wall -Wextra -Werror -Ofast
endif

EOC=\033[0m
BLUE=\033[1;34m
YELLOW=\033[1;33m
LGREEN=\033[1;32m
GREEN=\033[32m
RED=\033[31m
LRED=\033[91m
BRED=\033[1;31m

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

$(NAME): $(OBJ) $(OBJ_PRINTF)
	@printf "\n"
	@ar rcs $(NAME) $(OBJ) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo  "$(LGREEN) $(NAME) $(EOC)$(GREEN)is done! $(EOC)"
$(OBJ): obj/%.o: %.c
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $^
	@printf  "$(BLUE).$(EOC)"
$(OBJ_PRINTF): obj/%.o: %.c
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $^
	@printf  "$(YELLOW).$(EOC)"
clean:
	@rm -rf $(OBJ) $(OBJ_PRINTF)
	@echo  "$(RED)[ ✔ ] Objects files $(LRED)$(OBJ_LIST) $(EOC)$(RED) removed. $(EOC)"
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft.a
	@echo "$(RED)[ ✔ ] Lib $(BRED)$(NAME) $(EOC)$(RED)removed.$(EOC)"
re: fclean all
