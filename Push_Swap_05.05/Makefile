# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 23:40:08 by luferna3          #+#    #+#              #
#    Updated: 2025/04/15 00:23:07 by luferna3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# NAME = push_swap
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a
# SRCS = list_ops.c operations.c parsing.c freeing_ops.c less_simple_sorting.c
# 		simple_sorting.c main.c
# OBJ_FILES = $(SRCS:.c=.o)

# all: $(NAME) $(LIBFT)

# $(LIBFT): $(LIBFT_DIR)/libft.a
# 	$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJ_FILES)
# 	ar -rc $(NAME) $(OBJ_FILES) $(LIBFT)

# %.o: %.c libft.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	rm -f $(OBJ_FILES)

# fclean: clean 
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	rm -f $(NAME)

# re: fclean $(ALL)

# .PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = list_ops.c operations.c parsing.c freeing_ops.c \
	less_simple_sorting.c simple_sorting.c main.c

OBJ_FILES = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
