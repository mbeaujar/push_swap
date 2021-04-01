/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:45 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/01 22:20:33 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// x = 0 rx , 1 rrx
// len_x = length

int ascend(t_stack *a, int size)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < size)
    {
        if (a->data < a->next->data)
            count++;
        i++;
        a = a->next;
    }
    if (count > 1)
        return (1);
    return (0);
}

t_stack *search_pos(t_var *var, int index)
{
    t_stack *a;
    int i;

    a = var->a;
    i = 0;
    if (ascend(var->a, var->size_a))
    {
        while (i < var->size_a)
        {
            if (a->index < index && a->next->index > index)
                return (a);
            a = a->next;
            i++;
        }
    }
    else
    {
        while (i < var->size_a)
        {
            if (a->index > index && a->next->index < index)
                return (a);
            a = a->next;
            i++;
        }
    }
    return (a);
}

void path_finding_a(t_var *var, t_dir *dir, t_stack *current)
{
    t_stack *curr;
    int ra;
    int rra;

    ra = 0;
    curr = current;
    while (var->e_a != curr)
    {
        curr = curr->next;
        ra++;
    }
    rra = 0;
    curr = current;
    while (var->e_a != curr)
    {
        curr = curr->previous;
        rra++;
    }
    if (ra < rra)
    {
        dir->a = 0;
        dir->len_a = ra;
    }
    else
    {
        dir->a = 1;
        dir->len_a = rra;
    }
}

void path_finding_b(t_var *var, t_dir *dir, t_stack *current)
{
    t_stack *curr;
    int rb;
    int rrb;

    rb = 0;
    curr = current;
    while (var->e_b != curr)
    {
        curr = curr->next;
        rb++;
    }
    rrb = 0;
    curr = current;
    while (var->e_b != curr)
    {
        curr = curr->previous;
        rrb++;
    }
    if (rb < rrb)
    {
        dir->b = 0;
        dir->len_b = rb;
    }
    else
    {
        dir->b = 1;
        dir->len_b = rrb;
    }
    //ft_printf("path_finding_b -- rb : %d rrb : %d len_b : %d\n", rb, rrb, dir->len_b);
}

void total_step(t_var *var, t_dir *dir, t_stack *curr)
{
    path_finding_b(var, dir, curr);
    path_finding_a(var, dir, search_pos(var, curr->index));
}

void refresh_dir(t_dir *dir)
{
    dir->a = 0;
    dir->len_a = 0;
    dir->b = 0;
    dir->len_b = 0;
}

void search_path(t_var *var)
{
    int i;
    int best_path;
    t_dir dir;
    t_stack *curr;

    if (var->b)
    {
        i = 0;
        best_path = var->size_a + var->size_b;
        curr = var->b;
        while (i < var->size_b)
        {
            refresh_dir(&dir);
            total_step(var, &dir, curr);
            if (dir.len_a + dir.len_b < best_path)
            {
                var->dir = dir;
                best_path = dir.len_a + dir.len_b;
            }
            curr = curr->next;
            i++;
        }
    }
}