/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:11 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/26 14:59:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// 1 -> 2 -> 3
// end = 3

void s_a_b(t_stack **end)
{
    t_stack *lst;
    int tmp;
    
    lst = *end;
    tmp = lst->data;
    lst->data = lst->previous->data;
    lst->previous->data = tmp;     
}

void ss(t_var *var)
{
    if (lstsize(var->a) > 1)
        s_a_b(&var->e_a);
    if (lstsize(var->b) > 1)
    s_a_b(&var->e_b);
}

void pa(t_var *var)
{
    t_stack *tmp;

    if (var->a == NULL)
        return;
    tmp = var->e_b;
    var->e_b = tmp->previous;
    tmp->previous->next = NULL;
    if (var->a)
        var->e_a->next = tmp;
    else
        var->e_a = tmp;
    var->e_a = var->e_a->next;
}

void pb(t_var *var)
{
    t_stack *tmp;

    if (var->b == NULL)
        return;
    tmp = var->e_a;
    var->e_a = tmp->previous;
    tmp->previous->next = NULL;
    if (var->b)
        var->e_b->next = tmp;
    else
        var->e_b = tmp;
    var->e_a = var->e_a->next;
}

