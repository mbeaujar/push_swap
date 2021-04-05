/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:32:36 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 12:59:12 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	pa_part_3(t_var *var, t_stack *prev)
{
	var->e_a->next = var->a;
	var->a->previous = var->e_a;
	var->e_b->next = var->b;
	var->b->previous = var->e_b;
	var->size_b--;
	var->size_a++;
	if (var->size_b == 0)
	{
		var->b = NULL;
		var->e_b = NULL;
		var->e_a->next = var->a;
		var->a->previous = var->e_a;
		var->e_a->previous = prev;
	}
}

void	pa_part_2(t_var *var, t_stack *prev, t_stack *tmp)
{
	if (var->a)
	{
		var->e_a->next = tmp;
		tmp->previous = var->e_a;
		tmp->next = var->a;
		var->e_a = tmp;
		var->a->previous = var->e_a;
	}
	else
	{
		var->a = tmp;
		var->a->next = tmp;
		var->a->previous = tmp;
		var->e_a = var->a;
	}
	pa_part_3(var, prev);
}

void	pa(t_var *var)
{
	t_stack *tmp;
	t_stack *prev;

	if (var->b == NULL)
		return ;
	prev = NULL;
	if (var->size_b == 1)
		prev = var->e_a;
	tmp = var->e_b;
	var->e_b = tmp->previous;
	if (var->e_b && var->b)
		var->e_b->next = var->b;
	else
		var->b = NULL;
	pa_part_2(var, prev, tmp);
}

void	pb_part2(t_var *var, t_stack *tmp, t_stack *prev)
{
	if (var->b)
	{
		prev = var->e_b;
		var->e_b->next = tmp;
		tmp->previous = prev;
		var->e_b = tmp;
	}
	else
	{
		var->b = tmp;
		var->b->next = NULL;
		var->b->previous = NULL;
		var->e_b = var->b;
	}
	var->e_b->next = var->b;
	var->b->previous = var->e_b;
	var->e_a->next = var->a;
	var->a->previous = var->e_a;
	var->size_a--;
	var->size_b++;
}

void	pb(t_var *var)
{
	t_stack *tmp;
	t_stack *prev;

	if (var->a == NULL)
		return ;
	prev = NULL;
	tmp = var->e_a;
	var->e_a = tmp->previous;
	if (var->e_a)
		var->e_a->next = NULL;
	else
		var->a = NULL;
	pb_part2(var, tmp, prev);
}
