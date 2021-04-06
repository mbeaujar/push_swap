/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:30:47 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 16:36:31 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

void printtab(int *sorted, int len)
{
	int i;

	i = 0;
	ft_printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	while (i < len)
	{
		ft_printf("%d ", sorted[i]);
		i++;
	}
	ft_printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
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