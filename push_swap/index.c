/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:11:25 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/01 16:22:25 by mbeaujar         ###   ########.fr       */
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

void indexing(t_var *var)
{
    int *sorted;
    int len;

    len = lstsize(var->a);
    if (!(sorted = malloc(sizeof(int) * len)))
        return;
    lstcpy(sorted, var->a);
    sorting_tab(sorted, len);
    set_index(var->a, sorted);
    free(sorted);
}