# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beatz <beatz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 14:49:47 by tbeedril          #+#    #+#              #
#    Updated: 2020/12/13 01:25:54 by beatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
INCS = -I./parser -I./utils -I./srcs
CFLAGS = -g -Wall -Wextra -Werror $(INCS)
FT_PRINTF = ft_printf
LIBFTPRINTF = libftprintf
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
		./parser/parse5.c\
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
		./utils/util.c\

OBJS = $(SRCS:.c=.o)

all: MKPRINTF $(NAME)

MKPRINTF:
	make -C $(FT_PRINTF)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(FT_PRINTF)/$(LIBFTPRINTF).a

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF) fclean

re: fclean all
	make -C $(FT_PRINTF) fclean

.PHONY: all clean fclean re
