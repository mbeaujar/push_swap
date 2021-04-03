/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:24:24 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/03 20:14:31 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// x = 0 rx , 1 rrx
// len_x = length

void move(t_var *var, t_ope *cmd)
{
    while (var->dir.len_a)
    {
        if (var->dir.a)
        {
            listadd_back(&cmd, listnew("rra"));
            rra(var);
            var->dir.len_a--;
        }
        else
        {
            listadd_back(&cmd, listnew("ra"));
            ra(var);
            var->dir.len_a--;
        }
    }
    while (var->dir.len_b)
    {
        if (var->dir.b)
        {
            listadd_back(&cmd, listnew("rrb"));
            rrb(var);
            var->dir.len_b--;
        }
        else
        {
            listadd_back(&cmd, listnew("rb"));
            rb(var);
            var->dir.len_b--;
        }
    }
}

void printdir(t_dir dir)
{
    ft_printf("\n_____________\n");
    ft_printf("a : %d\nlen_a : %d\nb : %d\nlen_b : %d\n", dir.a, dir.len_a, dir.b, dir.len_b);
    ft_printf("\n_____________\n");
}

void make_move(t_var *var, t_ope *cmd)
{
    if (var->dir.a == 0 && var->dir.b == 0)
    {
        while (var->dir.len_a && var->dir.len_b)
        {
            listadd_back(&cmd, listnew("rr"));
            rr(var);
            var->dir.len_a--;
            var->dir.len_b--;
        }
    }
    else if (var->dir.a == 1 && var->dir.b == 1)
    {
        while (var->dir.len_a > 0 && var->dir.len_b > 0)
        {
            listadd_back(&cmd, listnew("rrr"));
            rrr(var);
            var->dir.len_a--;
            var->dir.len_b--;
        }
    }
    move(var, cmd);
}

void switch_to_a(t_var *var, t_ope *cmd)
{
    var->dir.a = 0;
    var->dir.b = 0;
    var->dir.len_a = 0;
    var->dir.len_b = 0;
    while (var->b)
    {
        printvar(var);
        ft_printf("call search_path\n");
        search_path(var);
        printvar(var);
        printdir(var->dir);
        ft_printf("call make_move\n");
        make_move(var, cmd);
        listadd_back(&cmd, listnew("pa"));
        pa(var);
    }
}