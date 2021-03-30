/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:01:29 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/30 17:06:31 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void greater_than(t_stack *a)
{
	int num;

	num = -1;
	while (a)
	{
		if (a->index > num)
		{
			num = a->index;
			a->keep = 1;
		}
		a = a->next;
	}
}


void by_index(t_stack *a)
{
	int pos;

	pos = -1;
	while (a)
	{
		if (a->index - 1 == pos)
		{
			pos = a->index;
			a->keep = 1;
		}
		a = a->next;
	}
}

void printchaine(t_stack *a)
{
	while (a)
	{
		ft_printf("data : %d index : %d keep : %d\n", a->data, a->index, a->keep);
		a = a->next;
	}
}

void init_keep(t_var *var)
{
	printchaine(var->a);
	//greater_than(var->a);
	by_index(var->a);
	printchaine(var->a);

}
