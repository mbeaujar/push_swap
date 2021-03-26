/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:37 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/26 15:00:06 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/inc/libft.h"

typedef struct s_stack
{
	int data;
	struct s_stack *next;
	struct s_stack *previous;
}	t_stack;

typedef struct s_var
{
	t_stack *a;
	t_stack *b;
	t_stack *e_a;
	t_stack *e_b;
}	t_var;

void error(int error);
t_stack *parsing(int argc, char **argv);
int lstsize(t_stack *lst);
void printlist(t_stack *lst);
void freelist(t_stack *lst);
void s_a_b(t_stack **end);
t_stack *lstnew(int data);
void lstadd_front(t_stack **lst, t_stack *new);

#endif 
