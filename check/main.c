/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:26 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/06 17:54:03 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

t_stack	*lstnew(int data)
{
	t_stack *cell;

	if (!(cell = malloc(sizeof(t_stack) * 1)))
		return (NULL);
	cell->data = data;
	cell->color = 0;
	cell->next = NULL;
	return (cell);
}

void	lstadd_front(t_stack **alst, t_stack *neww)
{
	t_stack *cell;

	if (!*alst)
	{
		*alst = neww;
		return ;
	}
	cell = *alst;
	neww->next = cell;
	*alst = neww;
}

int		lstsize(t_stack *lst)
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

void	printlist(t_stack *lst)
{
	ft_printf("base | ");
	while (lst)
	{
		ft_printf("%d -> ", lst->data);
		lst = lst->next;
	}
	ft_printf("NULL | sommet\n");
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_bonus options;

	a = parsing(argc, argv, &options);
	read_stdin(a, &options);
	freelist(a);
	return (0);
}
