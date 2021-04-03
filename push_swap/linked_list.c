/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:27:20 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/03 19:23:37 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack *lstnew(int data)
{
    t_stack *cell;

    if (!(cell = malloc(sizeof(t_stack) * 1)))
        return (NULL);
    cell->data = data;
    cell->next = NULL;
    cell->previous = NULL;
    cell->index = 0;
    cell->keep_in_stack = 0;
    return (cell);
}

int cmdsize(t_ope *cmd)
{
    int i;

    i = 0;
    while (cmd)
    {
        cmd = cmd->next;
        i++;
    }
    return (i);
}

void freecmd(t_ope *cmd)
{
    t_ope *tmp;

    while (cmd)
    {
        tmp = cmd;
        cmd = cmd->next;
        free(tmp);
    }
}

void listadd_back(t_ope **alst, t_ope *neww)
{
    t_ope *cell;

    if (!*alst)
    {
        *alst = neww;
        return;
    }
    cell = *alst;
    while (cell->next)
        cell = cell->next;
    cell->next = neww;
}

t_ope *listnew(void *content)
{
    t_ope *cell;

    if (!(cell = malloc(sizeof(t_ope) * 1)))
        return (NULL);
    cell->name = content;
    cell->next = NULL;
    return (cell);
}

int lstsize(t_stack *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}



void freelists(t_var *var)
{
    t_stack *tmp;
    int i;

    i = 0;
    if (var->a)
    {
        while (i < var->size_a - 1)
        {
            tmp = var->a;
            var->a = var->a->next;
            free(tmp);
            i++;
        }
    }
    i = 0;
    if (var->b)
    {
        while (i < var->size_b - 1)
        {
            tmp = var->b;
            var->b = var->b->next;
            free(tmp);
            i++;
        }
    }
}

void freelist(t_stack *lst)
{
    t_stack *tmp;

    while (lst)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}

void lstadd_front(t_stack **lst, t_stack *new)
{
    t_stack *cell;

    cell = *lst;
    new->next = cell;
    cell->previous = new;
    *lst = new;
}

void printlist(t_stack *lst, char pile)
{
    ft_printf("| %c base | ", pile);
    while (lst)
    {
        ft_printf("%d -> ", lst->data);
        lst = lst->next;
    }
    ft_printf("NULL | sommet\n");
}
