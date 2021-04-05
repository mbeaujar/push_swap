/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:54:05 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 23:24:01 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	dir_align(t_var *var, int ra_size, int rra_size, t_ope *cmd)
{
	while (var->e_a->index != 0 && (ra_size < rra_size))
	{
		listadd_back(&cmd, listnew("ra"));
		ra(var);
	}
	while (var->e_a->index != 0 && !(ra_size < rra_size))
	{
		listadd_back(&cmd, listnew("rra"));
		rra(var);
	}
}

int		maximum_index(t_stack *a, int size)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (i < size)
	{
		if (a->index > index)
			index = a->index;
		a = a->next;
		i++;
	}
	return (index);
}

void	align_stack_a(t_var *var, t_ope *cmd)
{
	t_stack	*curr;
	int		ra;
	int		rra;

	rra = 0;
	curr = var->e_a;
	while (curr->index != 0)
	{
		rra++;
		curr = curr->next;
	}
	ra = 0;
	curr = var->e_a;
	while (curr->index != 0)
	{
		curr = curr->previous;
		ra++;
	}
	dir_align(var, ra, rra, cmd);
}

t_ope	*solve(t_var *var, int (*markup_fct)(t_stack *, t_stack *))
{
	t_ope *cmd;

	cmd = listnew("first");
	switch_to_b(var, cmd, markup_fct);
	switch_to_a(var, cmd);
	align_stack_a(var, cmd);
	return (cmd);
}
