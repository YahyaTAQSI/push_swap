# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:48:26 by ytaqsi            #+#    #+#              #
#    Updated: 2022/12/22 15:32:56 by ytaqsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCMAN = ft_atoi.c \
	ft_lst_utils.c \
	ft_split.c \
	ft_strjoin.c \
	markuphead.c \
	parsing.c \
	push_swap.c \
	pushab.c \
	reverseab.c \
	rotateab.c \
	swapab.c \
	from_a_to_b.c \
	checksign.c \

SRCBONUS = checker.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_atoi.c \
	ft_lst_utils.c \
	ft_split.c \
	ft_strjoin.c \
	markuphead.c \
	parsing.c \
	pushab.c \
	reverseab.c \
	rotateab.c \
	swapab.c \
	from_a_to_b.c \
	checksign.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra
FRM = rm -rf

NAME = push_swap
BNS = checker
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

$(BNS): $(SRCBONUS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCBONUS) -o $(BNS)

bonus: $(BNS)

clean:
	$(FRM) $(NAME)

fclean: clean
	$(FRM) $(BNS)

re: fclean all
