NAME_PUSH = push_swap
NAME_CHECK = checker
LIB = ft
PATH_LIB = ./libft
FILE_LIB=./libft/libft.a
SRC_PUSH = index.c linked_list.c main.c \
	markup_head.c parsing.c path.c solve.c \
	switch_to_a.c switch_to_b.c \
	p.c r.c rr.c s.c search.c path_finding.c debug.c bonus.c
SRCS_PUSH = $(addprefix push/, $(SRC_PUSH))
SRC_CHECK = main.c parsing.c read_stdin.c r.c \
	p.c rr.c s.c bonus.c
SRCS_CHECK = $(addprefix check/, $(SRC_CHECK))
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH) :
ifeq ("$(wildcard $(FILE_LIB))","")
	@make -C libft
endif
	@$(CC) $(CFLAGS)  $(SRCS_PUSH) -l$(LIB) -L$(PATH_LIB) -o $(NAME_PUSH)

$(NAME_CHECK) : 
	@$(CC) $(CFLAGS)  $(SRCS_CHECK) -l$(LIB) -L$(PATH_LIB) -o $(NAME_CHECK)

clean : 
	@$(RM) $(NAME_CHECK)
	@$(RM) $(NAME_PUSH)

fclean : clean 
	
fclean_lib : 
	@make fclean -C $(PATH_LIB)

re : fclean all
