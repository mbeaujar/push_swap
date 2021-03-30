/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/30 16:18:35 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void error(int error)
{
	ft_printf("Error\n");
	exit(error);
}

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

int main(int argc, char **argv)
{
	t_var var; 
	
	if (argc == 1)
		error(1);
	init_struct(&var);
	var.a = parsing(argc, argv);
	reset_struct(&var);
	init_order(&var);
	init_keep(&var);
	if (var.a)
		freelist(var.a);
	if (var.b)
		freelist(var.b);
	return (0);
}
