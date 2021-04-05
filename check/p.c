/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:22 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 15:30:58 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	pa_part2(t_stack *begin_a, t_stack *begin_b, t_stack *tmp, t_stack **a)
{
	if (begin_b && begin_a)
	{
		while (begin_a->next != NULL)
			begin_a = begin_a->next;
		begin_a->next = tmp;
	}
	else if (begin_b)
		*a = tmp;
}

void	pa(t_stack **a, t_stack **b, int *check)
{
	t_stack *begin_a;
	t_stack *begin_b;
	t_stack *tmp;

	begin_a = *a;
	begin_b = *b;
	(*check)++;
	tmp = NULL;
	if (begin_b && begin_b->next != NULL)
	{
		while (begin_b->next->next != NULL)
			begin_b = begin_b->next;
		tmp = begin_b->next;
		begin_b->next = NULL;
	}
	else if (begin_b)
	{
		tmp = *b;
		*b = NULL;
	}
	pa_part2(begin_a, begin_b, tmp, a);
}

void	pb_part2(t_stack *begin_a, t_stack *begin_b, t_stack *tmp, t_stack **b)
{
	if (begin_a && begin_b)
	{
		while (begin_b->next != NULL)
			begin_b = begin_b->next;
		begin_b->next = tmp;
	}
	else if (begin_a)
		*b = tmp;
}

void	pb(t_stack **a, t_stack **b, int *check)
{
	t_stack *begin_a;
	t_stack *begin_b;
	t_stack *tmp;

	begin_a = *a;
	begin_b = *b;
	(*check)++;
	tmp = NULL;
	if (begin_a && begin_a->next != NULL)
	{
		while (begin_a->next->next != NULL)
			begin_a = begin_a->next;
		tmp = begin_a->next;
		begin_a->next = NULL;
	}
	else if (begin_a)
	{
		tmp = *a;
		*a = NULL;
	}
	pb_part2(begin_a, begin_b, tmp, b);
}

void	freelist(t_stack *lst)
{
	t_stack *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
