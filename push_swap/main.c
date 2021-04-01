/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/01 23:10:09 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void error(int error)
{
	ft_printf("Error\n");
	exit(error);
}

void param_struct(t_var *var)
{
	t_stack *tmp;
	int i;

	tmp = var->a;
	i = 0;
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	var->e_a = tmp;
	var->size_a = ++i;
	var->e_a->next = var->a;
	var->a->previous = var->e_a;
}

void init_struct(t_var *var)
{
	var->a = NULL;
	var->e_a = NULL;
	var->b = NULL;
	var->e_b = NULL;
	var->size_a = 0;
	var->size_b = 0;
	var->nb_keep = 0;
	var->markup_head = NULL;
}

void printlists(t_stack *a, int size)
{
	int i;

	if (a)
	{
		i = 0;
		while (i < size)
		{
			ft_printf("%d ", a->data);
			a = a->next;
			i++;
		}
	}
}

void printvar(t_var *var)
{
	ft_printf("\n------------------------------\n");
	if (var->markup_head)
		ft_printf("markup_head : %d\n", var->markup_head->data);
	ft_printf("size_a : %d\nsize_b : %d\n", var->size_a, var->size_b);
	ft_printf("a : %d e_a : %d\n", var->a->data, var->e_a->data);
	if (var->b)
		ft_printf("b : %d e_b : %d\n", var->b->data, var->e_b->data);
	printlists(var->a, var->size_a);
	ft_printf("\n");
	printlists(var->b, var->size_b);
	ft_printf("\n------------------------------\n");
}

int main(int argc, char **argv)
{
	t_var var;
	t_ope *cmd;

	if (argc == 1)
		error(1);
	cmd = NULL;
	init_struct(&var);
	var.a = parsing(argc, argv);
	indexing(&var);
	param_struct(&var);
	markup_head(&var, markup_greater_than);
	printvar(&var);
	cmd = solve(&var, markup_greater_than);
	printvar(&var);
	/*ra(&var);
	printvar(&var);
	ra(&var);
	ft_printf("next e_a : %d\n", var.e_a->next->data);
	printvar(&var);*/
	t_ope *tmp;
	int i = 0;
	tmp = cmd;
	cmd = cmd->next;
	free(tmp);
	while (cmd)
	{
		ft_printf("s : %s\n", cmd->name);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
		i++;
	}
	ft_printf("result : %d\n", i);
	freelists(&var);
	return (0);
}
