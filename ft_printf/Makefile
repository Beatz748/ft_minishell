NAME = libftprintf

LIBFT = libft

SRC = ft_parce_utils.c ft_put_int.c ft_put_types.c ft_utils1.c\
		ft_utils2.c ft_put_cs.c ft_put_cs_utils.c ft_put_di.c ft_put_di_utils.c\
		ft_put_u.c ft_put_u_utils.c ft_put_x.c ft_put_x_utils.c ft_printf.c

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))

HEADERS = ft_printf.h

FLAGS = -Wall -Wextra -Werror -g

all: MKLIB $(NAME).a

MKLIB:
	make -C $(LIBFT)
$(NAME).a: $(LIBFT)/$(LIBFT).a $(SRC_OBJECTS)
	cp $(LIBFT)/$(LIBFT).a ./$(NAME).a
	ar rcs $(NAME).a $(SRC_OBJECTS)

# $@ -Имя цели обрабатываемого правила
# $< Имя первой зависимости обрабатываемого правила
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
clean:
	@/bin/rm -rf $(SRC_OBJECTS)
	make -C $(LIBFT) clean
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME).a
	make -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re:
	make -C $(LIBFT) fclean
	make fclean
	make all

.PHONY: all clean fclean re
