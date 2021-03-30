/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:17:43 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 20:46:05 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// ra

void ascend_a(t_var *var)
{
    if (var->e_a && var->e_a->previous)
    {
        if (var->e_a->limit == 0 && var->e_a->data > var->e_a->previous->data)
            var->sa = 1;
        else /*if (var->e_a->limit == 0)*/
            var->ra = 1;
        return;
    }
    //var->dir_a = 1;
}


// rra

void descend_a(t_var *var)
{
    if (var->e_a && var->e_a->previous)
    {
        if (var->e_a->limit == 0 && var->e_a->data > var->e_a->previous->data)
            var->sa = 1;
        else /*if (var->e_a->limit == 0)*/
            var->rra = 1;
        return;
    }
    //var->dir_a = 0;
}

// dir 0 == ascend RA
// dir 1 == descend RRA

int check_ascend_a(t_stack *a)
{
    while (a && a->previous)
    {
        if (a->data > a->previous->data)
            return (1);
        a = a->previous;
    }
    return (0);
}

void sorting_a(t_var *var)
{
    if (!check_ascend_a(var->e_a) || var->e_a->limit == 1)
    {
        //printlist(var->a, 'A');
        var->dir_a = 1;
    }
    if (var->a->limit == 1)
    {
        //printlist(var->a, 'A');
        var->dir_a = 0;
    }
    if (var->dir_a == 0)
        ascend_a(var);
    else
        descend_a(var);
}
