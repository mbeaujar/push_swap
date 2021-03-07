NAME = checker
PATH_LIB = ../libft
LIB = ft
SRCS = main.c parsing.c read_stdin.c instructions.c
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : 
	@$(CC) $(CFLAGS) -L$(PATH_LIB) -l$(LIB) $(SRCS) -o $(NAME)

clean : 
	@$(RM) ./$(NAME)

fclean : clean 

re : fclean all