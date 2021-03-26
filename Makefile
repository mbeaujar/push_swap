NAME=push_swap
PATH_CHECKER=checker/
PATH_PUSH_SWAP=push_swap


all : $(NAME)

$(NAME): 
	make -C $(PATH_CHECKER) && mv checker/checker ..
	make -C $(PATH_PUSH_SWAP) && mv checker/push_swap ..

# EN CONSTRUCTIOn