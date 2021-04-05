/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:24:24 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 22:55:56 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	move_part2(t_var *var, t_ope *cmd)
{
	while (var->dir.len_b)
	{
		if (var->dir.b)
		{
			listadd_back(&cmd, listnew("rrb"));
			rrb(var);
			var->dir.len_b--;
		}
		else
		{
			listadd_back(&cmd, listnew("rb"));
			rb(var);
			var->dir.len_b--;
		}
	}
}

void	move(t_var *var, t_ope *cmd)
{
	while (var->dir.len_a)
	{
		if (var->dir.a)
		{
			listadd_back(&cmd, listnew("rra"));
			rra(var);
			var->dir.len_a--;
		}
		else
		{
			listadd_back(&cmd, listnew("ra"));
			ra(var);
			var->dir.len_a--;
		}
	}
	move_part2(var, cmd);
}

void	make_move(t_var *var, t_ope *cmd)
{
	if (var->dir.a == 0 && var->dir.b == 0)
	{
		while (var->dir.len_a && var->dir.len_b)
		{
			listadd_back(&cmd, listnew("rr"));
			rr(var);
			var->dir.len_a--;
			var->dir.len_b--;
		}
	}
	else if (var->dir.a == 1 && var->dir.b == 1)
	{
		while (var->dir.len_a > 0 && var->dir.len_b > 0)
		{
			listadd_back(&cmd, listnew("rrr"));
			rrr(var);
			var->dir.len_a--;
			var->dir.len_b--;
		}
	}
	move(var, cmd);
}

void	switch_to_a(t_var *var, t_ope *cmd)
{
	var->dir.a = 0;
	var->dir.b = 0;
	var->dir.len_a = 0;
	var->dir.len_b = 0;
	while (var->b)
	{
		search_path(var);
		make_move(var, cmd);
		listadd_back(&cmd, listnew("pa"));
		pa(var);
	}
}
