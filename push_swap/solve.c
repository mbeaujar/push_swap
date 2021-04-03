/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:54:05 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/03 19:09:45 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void dir_align(t_var *var, int ra_size, int rra_size, t_ope *cmd)
{
    //ft_printf("rra : %d ra : %d\n", rra_size, ra_size);
    while (var->e_a->index != 0 && (ra_size < rra_size))
    {
        listadd_back(&cmd, listnew("ra"));
        ra(var);
    }
    while (var->e_a->index != 0  && !(ra_size < rra_size))
    {
        //ft_printf("var->a->index : %d var->e_a->indew : %d\n", var->a->index, var->e_a->index);
        listadd_back(&cmd, listnew("rra"));
        rra(var);
    }
}

int maximum_index(t_stack *a, int size)
{
    int i;
    int index;

    i = 0;
    index = 0;
    while (i < size)
    {
        if (a->index > index)
            index = a->index;
        a = a->next;
        i++;
    }
    return (index);
}

void check_pointer(t_var *var)
{
    int i = 0;
    
    t_stack *tmp;

    tmp = var->a;
    while (i < var->size_a)
    {
        ft_printf("-----------------\n");
        ft_printf("previous : %d\ncurrent : %d\nnext : %d\n", tmp->previous->data, tmp->data, tmp->next->data);
        tmp = tmp->next;
        i++;
    }
}

void align_stack_a(t_var *var, t_ope *cmd)
{
    t_stack *curr;
    int ra;
    int rra;
    
    rra = 0;
    curr = var->e_a;
    while (curr->index != 0)
    {
        rra++;
        curr = curr->next;
    }
    ra = 0;
    curr = var->e_a;
    //check_pointer(var);
    while (curr->index != 0)
    {
        curr = curr->previous;
        ra++;
    }
    dir_align(var, ra, rra, cmd);
}

void printkeep(t_stack *a, int size_a)
{
    int i;

    i = 0;
    while (i < size_a)
    {
        ft_printf("data : %d keep : %d\n", a->data, a->keep_in_stack);
        a = a->next;
        i++;
    }
}

void printindex(t_stack *a, int size_a)
{
    t_stack *s;
    int i;

    i = 0;
    s = a;
    while (i < size_a)
    {
        ft_printf("data : %d index : %d\n", a->data, a->index);
        a = a->next;
        i++;
    }
}

t_ope *solve(t_var *var, int (*markup_fct)(t_stack *, t_stack *))
{
    t_ope *cmd;

    cmd = listnew("first");
    switch_to_b(var, cmd, markup_fct);
    switch_to_a(var, cmd);
    align_stack_a(var, cmd);
    return (cmd);
}