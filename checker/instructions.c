/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:22 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/03 22:14:26 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void sa(t_stack **a, int *check)
{
    t_stack *begin;
    int tmp;
    
    begin = *a;
    (*check)++;
    if (lstsize(begin) <= 1)
        return;
    while (begin->next->next != NULL)
    {
        begin = begin->next;
    }
    tmp = begin->data;
    begin->data = begin->next->data;
    begin->next->data = tmp;
}

void sb(t_stack **b, int *check)
{
    t_stack *begin;
    int tmp;

    begin = *b;
    (*check)++;
    if (lstsize(begin) <= 1)
        return;
    while (begin->next->next != NULL)
    {
        begin = begin->next;
    }
    tmp = begin->data;
    begin->data = begin->next->data;
    begin->next->data = tmp;
}

void ss(t_stack **a, t_stack **b, int *check)
{
    sa(a, check);
    sb(b, check);
}

void pa(t_stack **a, t_stack **b, int *check)
{
    t_stack *begin_a;
    t_stack *begin_b;

    begin_a = *a;
    begin_b = *b;
    (*check)++;
    if (begin_b == NULL)
        return;
    while (begin_a->next != NULL)
        begin_a = begin_a->next;
    while (begin_b->next != NULL)
        begin_b = begin_b->next;
    begin_a->next = begin_b;
    begin_b = NULL;
}

void pb(t_stack **a, t_stack **b, int *check)
{
    t_stack *begin_a;
    t_stack *begin_b;

    begin_a = *a;
    begin_b = *b;
    (*check)++;
    if (begin_a == NULL)
        return;
    while (begin_b->next != NULL)
        begin_b = begin_b->next;
    while (begin_a->next != NULL)
        begin_a = begin_a->next;
    begin_b->next = begin_a;
    begin_a = NULL;
}

void ra(t_stack **a, int *check)
{
    t_stack *begin;
    t_stack *tmp;

    begin = *a;
    while (begin->next != NULL)
        begin = begin->next;
}