NAME = push_swap
PATH_LIB = ../libft
LIB = ft
SRCS = index.c instructions.c linked_list.c main.c \
	markup_head.c parsing.c path.c solve.c \
	switch_to_a.c switch_to_b.c
CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all : $(NAME)

$(NAME) : 
#ifeq ("$(wildcard $(../libft/libft.a))","")
#	@make -C $(PATH_LIB)
#endif
	@$(CC) $(CFLAGS) -L$(PATH_LIB) -l$(LIB) $(SRCS) -o $(NAME)

clean : 
	@$(RM) ./$(NAME)

fclean : clean

re : fclean all
