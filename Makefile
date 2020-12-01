# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 14:49:47 by tbeedril          #+#    #+#              #
#    Updated: 2020/12/01 18:54:36 by tbeedril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
INCS = -I./parser -I./utils -I./srcs
CFLAGS = -Wall -Wextra -g $(INCS)

SRCS = srcs/main.c\
		./srcs/ft_errors.c\
		./srcs/ft_exec.c\
		./srcs/ft_signals.c\
		./srcs/ft_useful.c\
		./srcs/minishell.c\
		./srcs/minishell2.c\
		./parser/parse1.c\
		./parser/parse2.c\
		./parser/parse3.c\
		./parser/parse4.c\
		./srcs/ft_cd.c\
		./srcs/ft_echo.c\
		./srcs/ft_env.c\
		./srcs/ft_exit.c\
		./srcs/ft_export.c\
		./srcs/ft_pwd.c\
		./srcs/ft_unset.c\
		./utils/ft_split.c\
		./utils/ft_strdups.c\
		./utils/ft_strjoins.c\
		./utils/get_next_line.c\
		./utils/lst_utils.c\
		./utils/lst2_utils1.c\
		./utils/lst2_utils2.c\
		./utils/util.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
