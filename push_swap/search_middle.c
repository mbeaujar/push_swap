/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_middle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:26:39 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 19:40:35 by mbeaujar         ###   ########.fr       */
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
            if (sorted[i] < sorted[i + 1])
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

int value_mid(t_var *var)
{
    int *sorted;
    int len;
    
    len = lstsize(var->a);
    if (!(sorted = malloc(sizeof(int) * len)))
        return (-1);
    lstcpy(sorted, var->a);
    sorting_tab(sorted, len);
    var->max = sorted[0];
    var->min = sorted[len - 1];
    ft_printf("min : %d max : %d\n", var->min ,var->max);
    if (len % 2 == 0) 
        len = sorted[(len / 2) - 1];
    else
        len = sorted[len / 2];
    free(sorted);
    return (len);
}