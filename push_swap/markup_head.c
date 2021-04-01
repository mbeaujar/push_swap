/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:59:02 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/01 17:55:10 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int markup_greater_than(t_stack *a, t_stack *markup_head)
{
    int keep;
    int index;
    
    keep = 0;
    if (a && markup_head)
    {
        index = markup_head->index;
        markup_head->keep_in_stack = 1;
        a = markup_head->previous;
        while (a != markup_head)
        {
            if (a->index > index)
            {
                index = a->index;
                keep++;
                a->keep_in_stack = 1;
            }
            else
                a->keep_in_stack = 0;
            a = a->previous;
        }
    }
    return (keep);
}

int markup_index(t_stack *a, t_stack *markup_head)
{
    int keep;
    int index;

    keep = 0;
    if (a && markup_head)
    {
        index = markup_head->index;
        markup_head->keep_in_stack = 1;
        a = markup_head->next;
        while (a != markup_head)
        {
            if (a->index == index + 1)
            {
                index += 1;
                keep++;
                a->keep_in_stack = 1;
            }
            else
                a->keep_in_stack = 0;
            a = a->next;
        }
    }
    return (keep);
}

void markup_head(t_var *var, int (*markup_fct)(t_stack *, t_stack *))
{
    int nb_keep;
    int i;
    t_stack *a;

    i = 0;
    if (var->a && markup_fct)
    {
        a = var->a;
        while (i < var->size_a)
        {
            nb_keep = markup_fct(var->a, a);
            if (nb_keep > var->nb_keep)
            {
                var->markup_head = a;
                var->nb_keep = nb_keep;
            }
            else if (nb_keep == var->nb_keep && (!var->markup_head || a->data < var->markup_head->data))
                var->markup_head = a;
            i++;
            a = a->next;
        }
    }
    markup_fct(var->a, var->markup_head);
}