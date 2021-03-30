/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:45:19 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 20:45:27 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int listsorted(t_stack *a, t_stack *b)
{
    while (a && a->next)
    {
        if (a->data < a->next->data)
            return (0);
        a = a->next;
    }
    if (!b)
        return (1);
    return (0);
}

void call_action(t_var *var, int *count)
{
    if (var->sa && lstsize(var->a) > 1)
    {
        ft_printf("sa\n");
        s_a_b(&var->e_a);
    }
    if (var->sb && lstsize(var->b) > 1)
    {
        ft_printf("sb\n");
        s_a_b(&var->e_b);
    }
    if (var->ss)
    {
        ft_printf("ss\n");
        ss(var);
    }
    if (var->pa)
    {
        ft_printf("pa\n");
        pa(var);
    }
    if (var->pb)
    {
        ft_printf("pb\n");
        pb(var);
    }
    if (var->ra)
    {
        ft_printf("ra\n");
        ra(var);
    }
    if (var->rb)
    {
        ft_printf("rb\n");
        rb(var);
    }
    if (var->rr)
    {
        ft_printf("rr\n");
        rr(var);
    }
    if (var->rra)
    {
        ft_printf("rra\n");
        rra(var);
    }
    if (var->rrb)
    {
        ft_printf("rrb\n");
        rrb(var);
    }
    if (var->rrr)
    {
        ft_printf("rrr\n");
        rrr(var);
    }
    (*count)++;
}

void opti_ope(t_var *var, int *count)
{
    if (var->ra && var->rb)
    {
        var->rr = 1;
        var->ra = 0;
        var->rb = 0;
    }
    if (var->rra && var->rrb)
    {
        var->rrr = 1;
        var->rra = 0;
        var->rrb = 0;
    }
    if (var->sa && var->sb)
    {
        var->ss = 1;
        var->sa = 0;
        var->sb = 0;
    }
    call_action(var, count);
    init_ope(var);
}

int debug_listsorted_a(t_stack *a)
{
    while (a && a->next)
    {
        if (a->data < a->next->data)
            return (0);
        a = a->next;
    }
    return (1);
}

int debug_listsorted_b(t_stack *b)
{
    while (b && b->next)
    {
        if (b->data > b->next->data)
            return (0);
        b = b->next;
    }
    return (1);
}

void stack_b_to_a(t_var *var, int *count)
{
    while (var->b)
    {
        ft_printf("pa\n");
        pa(var);
        (*count)++;
    }
}

void sorting(t_var *var)
{
    int count;

    count = 0;
    while (!listsorted(var->a, var->b))
    {
        //printstack(var);
        if (!debug_listsorted_a(var->a))
            sorting_a(var);
        if (!debug_listsorted_b(var->b))
            sorting_b(var); 
        opti_ope(var, &count);
        if (debug_listsorted_a(var->a) && debug_listsorted_b(var->b))
        {
            stack_b_to_a(var, &count);
            //printstack(var);
            if (var->a)
                freelist(var->a);
            if (var->b)
                freelist(var->b);
            //printf("instruction : %d\n", count);
            exit(1);
        }
    }
}