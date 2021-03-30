NAME = push_swap
PATH_LIB = ../libft
LIB = ft
SRCS = parsing.c main.c linked_list.c instructions.c search_middle.c fill_stack.c sorting.c sorting_a.c sorting_b.c
CC = clang
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -f

all : $(NAME)

$(NAME) : 
ifeq ("$(wildcard $(../libft/libft.a))","")
	@make -C $(PATH_LIB)
endif
	@$(CC) $(CFLAGS) -L$(PATH_LIB) -l$(LIB) $(SRCS) -o $(NAME)

clean : 
	@$(RM) ./$(NAME)

fclean : clean

re : fclean all
