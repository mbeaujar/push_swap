/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:49:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 23:19:31 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		keeping(t_stack *a, int size_a)
{
	int i;

	i = 0;
	if (a)
	{
		while (i < size_a)
		{
			if (!a->keep_in_stack)
				return (1);
			i++;
			a = a->next;
		}
	}
	return (0);
}

int		make_sa(t_var *var, int (*markup_fct)(t_stack *, t_stack *))
{
	int nb_keep;

	if (var->a && var->size_a >= 2)
	{
		sa(var);
		nb_keep = markup_fct(var->a, var->markup_head);
		sa(var);
		markup_fct(var->a, var->markup_head);
		if (nb_keep > var->nb_keep)
			return (1);
	}
	return (0);
}

void	switch_to_b(t_var *var, t_ope *cmd,
		int (*markup_fct)(t_stack *, t_stack *))
{
	while (keeping(var->a, var->size_a))
	{
		if (make_sa(var, markup_fct))
		{
			sa(var);
			listadd_back(&cmd, listnew("sa"));
			var->nb_keep = markup_fct(var->a, var->markup_head);
		}
		else if (var->e_a->keep_in_stack == 0)
		{
			pb(var);
			listadd_back(&cmd, listnew("pb"));
		}
		else
		{
			ra(var);
			listadd_back(&cmd, listnew("ra"));
		}
	}
}
