/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:53:54 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/21 01:17:20 by mbeaujar         ###   ########.fr       */
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
		begin->next->color = 1;
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
		begin->next->color = 1;
		*b = (*b)->next;
		begin->next->next = NULL;
	}
}

void	rrr(t_stack **a, t_stack **b, int *check)
{
	rra(a, check);
	rrb(b, check);
}

int		check_len(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}
