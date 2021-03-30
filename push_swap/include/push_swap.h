/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:37 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 18:20:41 by mbeaujar         ###   ########.fr       */
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
	int limit;
}	t_stack;

typedef struct s_var
{
	t_stack *a;
	t_stack *b;
	t_stack *e_a;
	t_stack *e_b;
	int dir_a;
	int dir_b;
	int mid;
	int min;
	int max;
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;

}	t_var;

void error(int error);
t_stack *parsing(int argc, char **argv);
int lstsize(t_stack *lst);
void printlist(t_stack *lst, char pile);
void freelist(t_stack *lst);
t_stack *lstnew(int data);
void lstadd_front(t_stack **lst, t_stack *new);
void reset_struct(t_var *var);

	void s_a_b(t_stack **end);
void ss(t_var *var);
void pa(t_var *var);
void pb(t_var *var);
void ra(t_var *var);
void rb(t_var *var);
void rr(t_var *var);
void rra(t_var *var);
void rrb(t_var *var);
void rrr(t_var *var);
int value_mid(t_var *var);
void fill_stack(t_var *var);
void init_ope(t_var *var);
void printstack(t_var *var);


void sorting(t_var *var);
void sorting_a(t_var *var);
void sorting_b(t_var *var);

#endif 
