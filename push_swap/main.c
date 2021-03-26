/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/26 15:04:36 by mbeaujar         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_var var;
	
	if (argc == 1)
		error(1);
	var.a = parsing(argc, argv);
	reset_struct(&var);
	printlist(var.a);
	printf("A -- Head : %d Queue %d\n", var.a->data, var.e_a->data);
	printf("B -- Head : %d Queue %d\n", var.b->data, var.e_b->data);
	s_a_b(&var.a);
	printlist(var.a);
	return (0);
}
