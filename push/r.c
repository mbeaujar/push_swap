/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:31:53 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 23:26:17 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ra(t_var *var)
{
	var->a = var->a->previous;
	var->e_a = var->e_a->previous;
}

void	rb(t_var *var)
{
	var->b = var->b->previous;
	var->e_b = var->e_b->previous;
}

void	rr(t_var *var)
{
	ra(var);
	rb(var);
}

void	listadd_back(t_ope **alst, t_ope *neww)
{
	t_ope *cell;

	if (!*alst)
	{
		*alst = neww;
		return ;
	}
	cell = *alst;
	while (cell->next)
		cell = cell->next;
	cell->next = neww;
}

t_ope	*listnew(void *content)
{
	t_ope *cell;

	if (!(cell = malloc(sizeof(t_ope) * 1)))
		return (NULL);
	cell->name = content;
	cell->next = NULL;
	return (cell);
}
