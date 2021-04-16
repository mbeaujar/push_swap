NAME_PUSH = push_swap
NAME_CHECK = checker
LIB = ft
PATH_LIB = ./libft
FILE_LIB=./libft/libft.a
SRC_PUSH = index.c \
		linked_list.c \
		main.c \
		markup_head.c \
		parsing.c \
		path.c solve.c \
		switch_to_a.c \
		switch_to_b.c \
		p.c \
		r.c \
		rr.c \
		s.c \
		search.c \
		path_finding.c \
		debug.c \
		bonus.c

SRCS_PUSH = $(addprefix push/, $(SRC_PUSH))
OBJS_PUSH = ${SRCS_PUSH:.c=.o}

SRC_CHECK = main.c \
		parsing.c \
		read_stdin.c \
		r.c \
		p.c \
		rr.c \
		s.c \
		bonus.c

SRCS_CHECK = $(addprefix check/, $(SRC_CHECK))
OBJS_CHECK = ${SRCS_CHECK:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH) : $(OBJS_PUSH)
	@make -C libft
	@$(CC) $(CFLAGS)  $(OBJS_PUSH) -l$(LIB) -L$(PATH_LIB) -o $(NAME_PUSH)

$(NAME_CHECK) : $(OBJS_CHECK)
	@$(CC) $(CFLAGS)  $(OBJS_CHECK) -l$(LIB) -L$(PATH_LIB) -o $(NAME_CHECK)

clean : 
	@$(RM) $(NAME_CHECK)
	@$(RM) $(NAME_PUSH)

fclean : clean 
	@make fclean -C libft
	@$(RM) $(OBJS_CHECK)
	@$(RM) $(OBJS_PUSH)
	
fclean_lib : 
	@make fclean -C $(PATH_LIB)

re : fclean all
