/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:53:20 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/06 17:47:18 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	ra(t_stack **a, int *check)
{
	t_stack *begin;
	t_stack *tmp;

	begin = *a;
	(*check)++;
	if (begin && begin->next != NULL)
	{
		while (begin->next->next != NULL)
			begin = begin->next;
		tmp = begin->next;
		begin->next = NULL;
		tmp->next = *a;
		*a = tmp;
		(*a)->color = 1;

	}
}

void	rb(t_stack **b, int *check)
{
	t_stack *begin;
	t_stack *tmp;

	begin = *b;
	(*check)++;
	if (begin && begin->next != NULL)
	{
		while (begin->next->next != NULL)
			begin = begin->next;
		tmp = begin->next;
		begin->next = NULL;
		tmp->next = *b;
		*b = tmp;
		(*b)->color = 1;
	}
}

void	rr(t_stack **a, t_stack **b, int *check)
{
	ra(a, check);
	rb(b, check);
}

void	error_free(int error, t_stack *begin)
{
	freelist(begin);
	ft_printf("Error\n");
	exit(error);
}
