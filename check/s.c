/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:54:27 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 15:32:20 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	sa(t_stack **a, int *check)
{
	t_stack		*begin;
	int			tmp;

	begin = *a;
	(*check)++;
	if (lstsize(begin) <= 1)
		return ;
	while (begin->next->next != NULL)
	{
		begin = begin->next;
	}
	tmp = begin->data;
	begin->data = begin->next->data;
	begin->next->data = tmp;
}

void	sb(t_stack **b, int *check)
{
	t_stack		*begin;
	int			tmp;

	begin = *b;
	(*check)++;
	if (lstsize(begin) <= 1)
		return ;
	while (begin->next->next != NULL)
	{
		begin = begin->next;
	}
	tmp = begin->data;
	begin->data = begin->next->data;
	begin->next->data = tmp;
}

void	ss(t_stack **a, t_stack **b, int *check)
{
	sa(a, check);
	sb(b, check);
}
