/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_middle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:26:39 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/30 16:17:46 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void lstcpy(int *sorted, t_stack *a)
{
    int i;
    
    i = 0;
    while (a)
	{
		sorted[i] = a->data;
		a = a->next;
		i++;
	}
}

void sorting_tab(int *sorted, int len)
{
    int tmp;
    int i;
    int b;
    
    b = 1;
    while (b)
    {
        b = 0;
        i = 0;
        while (i < len - 1)
        {
            if (sorted[i] > sorted[i + 1])
            {
                tmp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = tmp;
                b = 1;
            }
            i++;
        }
    }
}

void set_index(t_stack *a, int *sorted)
{
	int i;

	while (a)
	{
		i = 0;
		while (sorted[i] != a->data)
			i++;
		a->index = i;
		a = a->next;
	}
}

void listprint(t_stack *a)
{
	while (a)
	{
		printf("data : %d pos : %d\n", a->data, a->index);
		a = a->next;
	}
}

void printtab(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d : %d\n", i, tab[i]);
		i++;
	}
	
}

void init_order(t_var *var)
{
    int *sorted;
    int len;
    
    len = lstsize(var->a);
    if (!(sorted = malloc(sizeof(int) * len)))
        return;
    lstcpy(sorted, var->a);
    sorting_tab(sorted, len);
	//printtab(sorted, len);
	set_index(var->a, sorted);
	//listprint(var->a);
    free(sorted);
}
