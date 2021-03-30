/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:51:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 19:14:16 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int ascend(t_stack *a, int mid)
{
    int count;
    
    count = 0;
    while (a)
    {
        if (a->data < mid)
            return (count);
        a = a->next;
        count++;
    }
    return (-1);
}

int descend(t_stack *a, int mid)
{
    int count;
    
    count = 0;
    while (a)
    {
        if (a->data < mid)
            return (count);
        a = a->previous;
        count++;
    }

    return (-1);
}

int under_mid(t_stack *a, int mid)
{
    while (a)
    {
        if (a->data < mid)
            return (1);
        a = a->next;
    }
    return (0);
}

void min_max(t_stack *a, int nb)
{
    while (a)
    {
        if (a->data == nb)
        {
            a->limit = 1;
            return;
        }
        a = a->next;
    }
}

void fill_stack(t_var *var)
{
    int count = 0; // debug
    while (under_mid(var->a, var->mid))
    {
        if (var->e_a->data < var->mid)
        {
            count++; // debug
            ft_printf("pb\n");
            pb(var); 
        }
        else
        {
            if (ascend(var->a, var->mid) > descend(var->e_a, var->mid))
            {
                while (var->e_a->data >= var->mid)
                {
                    count++; // debug
                    ft_printf("ra\n");
                    ra(var);
                }
            }
            else
            {
                while (var->e_a->data >= var->mid)
                {
                    ft_printf("rra\n");
                    count++; // debug
                    rra(var);
                }
            }
        }
    }
    min_max(var->a, var->max);
    min_max(var->b, var->min);
    //ft_printf("fill stack b : %d instructions\n", count);
}