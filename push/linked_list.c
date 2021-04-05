/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:27:20 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/04 22:56:51 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*lstnew(int data)
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

int		cmdsize(t_ope *cmd)
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

void	freecmd(t_ope *cmd)
{
	t_ope *tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
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
