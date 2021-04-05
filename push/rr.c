/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:31:12 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 22:55:10 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rra(t_var *var)
{
	var->a = var->a->next;
	var->e_a = var->e_a->next;
}

void	rrb(t_var *var)
{
	var->b = var->b->next;
	var->e_b = var->e_b->next;
}

void	rrr(t_var *var)
{
	rra(var);
	rrb(var);
}

void	freelists(t_var *var)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (var->a)
	{
		while (i < var->size_a - 1)
		{
			tmp = var->a;
			var->a = var->a->next;
			free(tmp);
			i++;
		}
	}
	i = 0;
	if (var->b)
	{
		while (i < var->size_b - 1)
		{
			tmp = var->b;
			var->b = var->b->next;
			free(tmp);
			i++;
		}
	}
}

void	error(int error)
{
	ft_printf("Error\n");
	exit(error);
}
