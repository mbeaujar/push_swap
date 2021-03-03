/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:43:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/03 21:34:55 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void error(int error)
{
    ft_printf("Error\n");
    exit(error);
}

int is_number(char *arg)
{
    int i;
    
    i = 0;
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

//  + passer en long long et check overflow positif et negatif

int recup_nb(char *arg)
{
    int i;
    int nb;

    i = 0;
    nb = 0;
    if (is_number(arg) == 0)
        error(1);
    while (arg[i])
    {
        nb = (nb) * 10 + (arg[i] - 48);
        i++;
    }
    return (nb);
}

void check_nb(t_stack *begin, int nb)
{
    t_stack *head;

    head = begin;
    while (begin)
    {
        if (begin->data == nb)
        {
            freelist(head);
            error(1);
        }
        begin = begin->next;
    }
}

t_stack *parsing(int argc, char **argv)
{
    int i;
    t_stack *head;
    int nb;
    
    i = 1;
    if (argc == 1)
        error(1);
    while (i < argc)
        recup_nb(argv[i++]);
    i = 1;
    head = lstnew(recup_nb(argv[i++]));
    while (i < argc)
    {
        nb = recup_nb(argv[i]);
        check_nb(head, nb);
        lstadd_front(&head, lstnew(nb));
        i++;
    }
    return (head);
}