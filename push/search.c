/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:03:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 14:43:58 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		search_number(int *sorted, int len, int nb)
{
	int i;

	i = 0;
	if (nb > sorted[len - 1])
		return (sorted[0]);
	i = 0;
	while (i < len - 1)
	{
		if (sorted[i] > nb)
			return (sorted[i]);
		i++;
	}
	if (nb < sorted[len - 1])
		return (sorted[len - 1]);
	return (sorted[0]);
}

t_stack	*search_pos(t_var *var, int index)
{
	t_stack *a;
	int		*sorted;
	int		nb;
	int		i;

	if (!(sorted = malloc(sizeof(int) * (var->size_a))))
		return (NULL);
	lstcpy(sorted, var->a, var->size_a);
	sorting_tab(sorted, var->size_a);
	nb = search_number(sorted, var->size_a, index);
	i = 0;
	a = var->a;
	while (i < var->size_a)
	{
		if (nb == a->data)
		{
			free(sorted);
			return (a);
		}
		i++;
		a = a->next;
	}
	free(sorted);
	return (a);
}

void	refresh_dir(t_dir *dir)
{
	dir->a = 0;
	dir->len_a = 0;
	dir->b = 0;
	dir->len_b = 0;
}
