/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:17:59 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 18:33:45 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ascend_b(t_var *var)
{
    if (var->e_b && var->e_b->previous)
    {
        if (var->e_b->limit == 0 && var->e_b->data < var->e_b->previous->data)
            var->sb = 1;
        else
            var->rb = 1;
        return;
    }
}

void descend_b(t_var *var)
{
    if (var->e_b && var->e_b->previous)
    {
        if (var->e_b->limit == 0 && var->e_b->data < var->e_b->previous->data)
            var->sb = 1;
        else
            var->rrb = 1;
        return;
    }
}

void sorting_b(t_var *var)
{
    if (var->e_b->limit == 1)
    {
        //printlist(var->b, 'B');
        var->dir_b = 1;
    }
    if (var->b->limit == 1)
    {
        //printlist(var->b, 'B');
        var->dir_b = 0;
    }
    if (var->dir_b == 0)
        ascend_b(var);
    else
        descend_b(var);
}