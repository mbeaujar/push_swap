/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:11 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/03 19:08:04 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void sa(t_var *var)
{
    t_stack *curr;
    t_stack *prev;

    curr = var->e_a;
    prev = curr->previous;
    curr->previous = prev->previous;
    prev->previous = curr;
    curr->next = prev;
    curr->previous->next = curr;
    var->e_a = prev;
    var->e_a->next = var->a;
    var->a->previous = var->e_a;
}

void sb(t_var *var)
{
    t_stack *curr;
    t_stack *prev;

    curr = var->e_b;
    prev = curr->previous;
    curr->previous = prev->previous;
    prev->previous = curr;
    curr->next = prev;
    curr->previous->next = curr;
    var->e_b = prev;
    var->e_b->next = var->b;
    var->b->previous = var->e_b;
}

void ss(t_var *var)
{
    if (lstsize(var->a) > 1)
        sa(var);
    if (lstsize(var->b) > 1)
        sb(var);
}

void pa(t_var *var)
{
    t_stack *tmp;
    t_stack *prev;

    if (var->b == NULL)
        return;
    if (var->size_b == 1)
        prev = var->e_a;
    tmp = var->e_b;
    var->e_b = tmp->previous;
    if (var->e_b && var->b)
        var->e_b->next = var->b;
    else
        var->b = NULL;
    if (var->a)
    {
        var->e_a->next = tmp;
        tmp->previous = var->e_a;
        tmp->next = var->a;
        var->e_a = tmp;
        var->a->previous = var->e_a;
    }
    else
    {
        var->a = tmp;
        var->a->next = tmp;
        var->a->previous = tmp;
        var->e_a = var->a;
    }
    var->e_a->next = var->a;
    var->a->previous = var->e_a;
    var->e_b->next = var->b;
    var->b->previous = var->e_b;
    var->size_b--;
    var->size_a++;
    if (var->size_b == 0)
    {
        var->b = NULL;
        var->e_b = NULL;
        var->e_a->next = var->a;
        var->a->previous = var->e_a;
        var->e_a->previous = prev;
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
    var->e_b->next = var->b;
    var->b->previous = var->e_b;
    var->e_a->next = var->a;
    var->a->previous = var->e_a;
    var->size_a--;
    var->size_b++;
}


void ra(t_var *var)
{
    var->a = var->a->previous;
    var->e_a = var->e_a->previous; 
}

void rb(t_var *var)
{
    var->b = var->b->previous;
    var->e_b = var->e_b->previous;
}

void rr(t_var *var)
{
    ra(var);
    rb(var);
}

void rra(t_var *var)
{
    var->a = var->a->next;
    var->e_a = var->e_a->next;
}

void rrb(t_var *var)
{
    var->b = var->b->next;
    var->e_b = var->e_b->next;
}

void rrr(t_var *var)
{
    rra(var);
    rrb(var);
}