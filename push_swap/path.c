/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:45 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/03 18:50:07 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// x = 0 rx , 1 rrx
// len_x = length


int search_number(int *sorted, int len, int nb)
{
    int i;

    i = 0;
    //if (nb > sorted[i] || nb < sorted[len - 1])
    //    return (sorted[len - 1]);
    while (i < len - 1)
    {
        if (sorted[i] > nb)
            return (sorted[i]);
        i++;
    }
    return (sorted[i]);
}

t_stack *search_pos(t_var *var, int index)
{
    t_stack *a;
    int *sorted;
    int nb;
    int i;
    
    if (!(sorted = malloc(sizeof(int) * (var->size_a))))
        return (NULL);
    lstcpy(sorted, var->a, var->size_a);
    sorting_tab(sorted, var->size_a);
    nb = search_number(sorted, var->size_a, index);
    //ft_printf("nbbbbb : %d\n", nb);
    i = 0;
    a = var->a;
    while (i < var->size_a)
    {
        if (nb == a->data)
        {
            free(sorted);
            return (a);
        }
        i++;
        a = a->next;
    }
    free(sorted);
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
    //ft_printf("var->e_b : %d curr : %d e_b next : %d curr next : %d\n", var->e_b->data, curr->data, var->e_b->next->data, curr->next->data);
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
    //ft_printf("call path_finding_b\n");
    path_finding_b(var, dir, curr);
    //ft_printf("call path_finding_a\n");
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