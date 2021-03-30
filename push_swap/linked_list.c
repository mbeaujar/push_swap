/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:27:20 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/28 16:02:46 by mbeaujar         ###   ########.fr       */
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
    cell->limit = 0;
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