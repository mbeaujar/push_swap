/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:11 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/27 18:58:43 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
    t_stack *prev;

    if (var->b == NULL)
        return;
    tmp = var->e_b;
    var->e_b = tmp->previous;
    if (var->e_b)
        var->e_b->next = NULL;
    else
        var->b = NULL;
    if (var->a)
    {
        prev = var->e_a;
        var->e_a->next = tmp;
        tmp->previous = prev;
        var->e_a = tmp;
    }
    else
    {
        var->a = tmp;
        var->a->next = NULL;
        var->a->previous = NULL;
        var->e_a = var->a;
    }
}

void pb(t_var *var)
{
    t_stack *tmp;
    t_stack *prev;
    
    if (var->a == NULL)
        return;
    tmp = var->e_a; 
    var->e_a = tmp->previous;
    if (var->e_a)
        var->e_a->next = NULL;
    else
        var->a = NULL;
    if (var->b)
    {
        prev = var->e_b;
        var->e_b->next = tmp;
        tmp->previous = prev;
        var->e_b = tmp;
    }
    else
    {
        var->b = tmp;
        var->b->next = NULL;
        var->b->previous = NULL;
        var->e_b = var->b;
    }
}


void ra(t_var *var)
{
    t_stack *tmp;
    t_stack *prev;
    
    if (var->a == NULL || var->a->next == NULL)
        return;
    tmp = var->e_a;
    prev = tmp->previous;
    if (tmp->previous)
        tmp->previous->next = NULL;
    tmp->previous = NULL;
    var->a->previous = tmp;
    tmp->next = var->a;
    var->a = tmp;
    if (prev)
        var->e_a = prev;
    else
        var->e_a = var->a;
}

void rb(t_var *var)
{
    t_stack *tmp;
    t_stack *prev;

    if (var->b == NULL || var->b->next == NULL)
        return;
    tmp = var->e_b;
    prev = tmp->previous;
    if (tmp->previous)
        tmp->previous->next = NULL;
    tmp->previous = NULL;
    var->b->previous = tmp;
    tmp->next = var->b;
    var->b = tmp;
    if (prev)
        var->e_b = prev;
    else
        var->e_b = var->b;
}

void rr(t_var *var)
{
    ra(var);
    rb(var);
}

void rra(t_var *var)
{
    t_stack *tmp;
    t_stack *next;
    
    if (var->a == NULL || var->a->next == NULL)
        return;
    tmp = var->a;
    tmp->previous = var->e_a;
    next = tmp->next;
    tmp->next = NULL;
    var->e_a->next = tmp;
    var->e_a = tmp;
    var->a = next;
    var->a->previous = NULL;
}

void rrb(t_var *var)
{
    t_stack *tmp;
    t_stack *next;

    if (var->b == NULL || var->b->next == NULL)
        return;
    tmp = var->b;
    tmp->previous = var->e_b;
    next = tmp->next;
    tmp->next = NULL;
    var->e_b->next = tmp;
    var->e_b = tmp;
    var->b = next;
    var->b->previous = NULL;
}

void rrr(t_var *var)
{
    rra(var);
    rrb(var);
}