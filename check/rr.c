/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:53:54 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 15:00:45 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	rra(t_stack **a, int *check)
{
	t_stack *begin;

	begin = *a;
	(*check)++;
	if (begin)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = *a;
		*a = (*a)->next;
		begin->next->next = NULL;
	}
}

void	rrb(t_stack **b, int *check)
{
	t_stack *begin;

	begin = *b;
	(*check)++;
	if (begin)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = *b;
		*b = (*b)->next;
		begin->next->next = NULL;
	}
}

void	rrr(t_stack **a, t_stack **b, int *check)
{
	rra(a, check);
	rrb(b, check);
}
