NAME = push_swap
PATH_LIB = ../libft
LIB = ft
SRCS = parsing.c main.c linked_list.c instructions.c
CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all : $(NAME)

$(NAME) : 
	@test ! -f ../libft/libft.a && make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) -L$(PATH_LIB) -l$(LIB) $(SRCS) -o $(NAME)

clean : 
	@$(RM) ./$(NAME)

fclean : clean
	@test -f ../libft/libft.a && make fclean -C $(PATH_LIB)

re : fclean all