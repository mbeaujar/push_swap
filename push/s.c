/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:11 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/06 17:55:12 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sa(t_var *var)
{
	t_stack *curr;
	t_stack *prev;

	curr = var->e_a;
	prev = curr->previous;
	curr->previous = prev->previous;
	prev->previous = curr;
	curr->next = prev;
	curr->previous->next = curr;
	var->e_a = prev;
	var->e_a->next = var->a;
	var->a->previous = var->e_a;
}

void	sb(t_var *var)
{
	t_stack *curr;
	t_stack *prev;

	curr = var->e_b;
	prev = curr->previous;
	curr->previous = prev->previous;
	prev->previous = curr;
	curr->next = prev;
	curr->previous->next = curr;
	var->e_b = prev;
	var->e_b->next = var->b;
	var->b->previous = var->e_b;
}

void	ss(t_var *var)
{
	if (lstsize(var->a) > 1)
		sa(var);
	if (lstsize(var->b) > 1)
		sb(var);
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

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack *cell;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cell = *lst;
	new->next = cell;
	cell->previous = new;
	*lst = new;
}
