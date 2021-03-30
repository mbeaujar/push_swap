/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 19:47:15 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void error(int error)
{
	ft_printf("Error\n");
	exit(error);
}

// init poiner end of the queue for stack a and b

void reset_struct(t_var *var)
{
	t_stack *tmp;

	tmp = var->a;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	var->e_a = tmp;
	tmp = var->b;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	var->e_b = tmp;
}

void init_struct(t_var *var)
{
	var->a = NULL;
	var->e_a = NULL;
	var->b = NULL;
	var->e_b = NULL;
	var->dir_a = 0;
	var->dir_b = 0;
}

void init_ope(t_var *var)
{
	var->sa = 0;
	var->sb = 0;
	var->ss = 0;
	var->pa = 0;
	var->pb = 0;
	var->ra = 0;
	var->rb = 0;
	var->rr = 0;
	var->rra = 0;
	var->rrb = 0;
	var->rrr = 0;
}

void printvar(t_var *var)
{
	if (var->a && var->e_a)
		ft_printf("| A -- Head : %d Queue %d\n", var->a->data, var->e_a->data);
	if (var->b && var->e_b)
		ft_printf("| B -- Head : %d Queue %d\n", var->b->data, var->e_b->data);
}

void printstack(t_var *var)
{
	ft_printf("|---------------------------------------------|\n");
	printlist(var->a, 'A');
	printlist(var->b, 'B');
	printvar(var);
}

void search_max(t_stack *a)
{
	t_stack *lst;
	int max;

	max = 0;
	lst = a;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	while (lst)
	{
		if (lst->data == max)
			lst->limit = 1;
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	t_var var;
	
	if (argc == 1)
		error(1);
	init_struct(&var);
	var.a = parsing(argc, argv);
	reset_struct(&var);
	//printstack(&var);
	var.mid = value_mid(&var);
	//ft_printf("value mid : %d\n", var.mid);
	if (lstsize(var.a) > 5)
		fill_stack(&var);
	else
		search_max(var.a);
	//printstack(&var);
	sorting(&var);
	//ft_printf("|---------------------------------------------|\n");
	if (var.a)
		freelist(var.a);
	if (var.b)
		freelist(var.b);
	return (0);
}
