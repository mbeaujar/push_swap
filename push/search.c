/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:03:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/21 01:16:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	search_value(t_stack **max, t_stack **min, t_stack *a, int size)
{
	t_stack *high;
	t_stack *low;
	int		i;

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

t_stack	*search_pos(t_var *var, int number)
{
	t_stack *a;
	t_stack *max;
	t_stack *min;
	int		i;

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

int		check_len(char *str)
{
	int	i;
	int	count;

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
