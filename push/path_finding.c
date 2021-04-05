/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:08:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 23:27:52 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	path_a_part2(t_dir *dir, int ra, int rra)
{
	if (ra < rra)
	{
		dir->a = 0;
		dir->len_a = ra;
	}
	else
	{
		dir->a = 1;
		dir->len_a = rra;
	}
}

void	path_finding_a(t_var *var, t_dir *dir, t_stack *current)
{
	t_stack	*curr;
	int		ra;
	int		rra;

	ra = 0;
	curr = current;
	while (var->e_a != curr)
	{
		curr = curr->next;
		ra++;
	}
	rra = 0;
	curr = current;
	while (var->e_a != curr)
	{
		curr = curr->previous;
		rra++;
	}
	path_a_part2(dir, ra, rra);
}

void	path_b_part2(t_dir *dir, int rb, int rrb)
{
	if (rb < rrb)
	{
		dir->b = 0;
		dir->len_b = rb;
	}
	else
	{
		dir->b = 1;
		dir->len_b = rrb;
	}
}

void	path_finding_b(t_var *var, t_dir *dir, t_stack *current)
{
	t_stack	*curr;
	int		rb;
	int		rrb;

	rb = 0;
	curr = current;
	while (var->e_b != curr)
	{
		curr = curr->next;
		rb++;
	}
	rrb = 0;
	curr = current;
	while (var->e_b != curr)
	{
		curr = curr->previous;
		rrb++;
	}
	path_b_part2(dir, rb, rrb);
}
