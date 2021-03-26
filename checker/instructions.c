/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:22 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/26 13:13:10 by mbeaujar         ###   ########.fr       */
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
    t_stack *tmp;

    begin_a = *a;
    begin_b = *b;
    (*check)++;
    if (begin_b && begin_b->next != NULL)
    {
        while (begin_b->next->next != NULL)
            begin_b = begin_b->next;
        tmp = begin_b->next;
        begin_b->next = NULL;
    }
    else if (begin_b)
    {
        tmp = *b;
        *b = NULL;
    }
    if (begin_b && begin_a)
    {
        while (begin_a->next != NULL)
            begin_a = begin_a->next;
        begin_a->next = tmp;
    }
    else if (begin_b)
        *a = tmp;
}

void pb(t_stack **a, t_stack **b, int *check)
{
    t_stack *begin_a;
    t_stack *begin_b;
    t_stack *tmp;

    begin_a = *a;
    begin_b = *b;
    (*check)++;
    if (begin_a && begin_a->next != NULL)
    {
        while (begin_a->next->next != NULL)
            begin_a = begin_a->next;
        tmp = begin_a->next;
        begin_a->next = NULL;
    }
    else if (begin_a)
    {
        tmp = *a;
        *a = NULL;
    }
    if (begin_a && begin_b)
    {
        while (begin_b->next != NULL)
            begin_b = begin_b->next;
        begin_b->next = tmp;
    }
    else if (begin_a)
        *b = tmp;
}

void ra(t_stack **a, int *check)
{
    t_stack *begin;
    t_stack *tmp;

    begin = *a;
    (*check)++;
    if (begin && begin->next != NULL)
    {
        while (begin->next->next != NULL)
            begin = begin->next;
        tmp = begin->next;
        begin->next = NULL;
        tmp->next = *a;
        *a = tmp;
    }
}

void rb(t_stack **b, int *check)
{
    t_stack *begin;
    t_stack *tmp;

    begin = *b;
    (*check)++;
    if (begin && begin->next != NULL)
    {
        while (begin->next->next != NULL)
            begin = begin->next;
        tmp = begin->next;
        begin->next = NULL;
        tmp->next = *b;
        *b = tmp;
    }
}

void rr(t_stack **a, t_stack **b, int *check)
{
    ra(a, check);
    rb(b, check);
}

void rra(t_stack **a, int *check)
{
    t_stack *begin;

    begin = *a;
    (*check)++;
    if (begin)
    {
        while (begin->next != NULL)
            begin = begin->next;
        begin->next = *a;
        *a = (*a)->next;
        begin->next->next = NULL;
    }
}

void rrb(t_stack **b, int *check)
{
    t_stack *begin;

    begin = *b;
    (*check)++;
    if (begin)
    {
        while (begin->next != NULL)
            begin = begin->next;
        begin->next = *b;
        *b = (*b)->next;
        begin->next->next = NULL;
    }
}

void rrr(t_stack **a, t_stack **b, int *check)
{
    rra(a, check);
    rrb(b, check);
}
