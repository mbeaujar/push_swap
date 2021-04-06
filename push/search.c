/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:03:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 19:11:08 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
/*
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
	//printtab(sorted, var->size_a - 1);
	nb = search_number(sorted, var->size_a, index);
	//ft_printf("NB : %d\n", nb);
	//printvar(var);
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
}*/

void search_value(t_stack **max, t_stack **min, t_stack *a, int size)
{
	t_stack *high;
	t_stack *low;
	int i;
	
	high = a;
	low = a;
	i = 0;
	while (i < size)
	{
		if (a->data > high->data)
			high = a;
		if (a->data < low->data)
			low = a;
		a = a->next;
		i++;
	}
	*max = high;
	*min = low;
}

t_stack *search_pos(t_var *var, int number)
{
	t_stack *a;
	t_stack *max;
	t_stack *min;
	int i;

	search_value(&max, &min, var->a, var->size_a);
	a = max;
	i = 0;
	if (number < min->data)
		return (min);
	if (number > max->data)
		return (min);
	while (i < var->size_a)
	{
		if (a->next->data < number)
			return (a);
		a = a->next;
		i++;
	}
	return (a);
}




void	refresh_dir(t_dir *dir)
{
	dir->a = 0;
	dir->len_a = 0;
	dir->b = 0;
	dir->len_b = 0;
}
