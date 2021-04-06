/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:28:45 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/06 17:12:58 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	total_step(t_var *var, t_dir *dir, t_stack *curr)
{
	path_finding_b(var, dir, curr);
	path_finding_a(var, dir, search_pos(var, curr->data));
}

int calcule_the_best_of_the_best(t_dir *dir)
{
	int len;
	
	len = dir->len_a + dir->len_b;
	if (dir->a != dir->b)
		len = dir->len_a + dir->len_b;
	if (dir->a == dir->b)
	{
		if (dir->len_a > dir->len_b)
			len = dir->len_a;
		else
			len = dir->len_b;
	}
	return (len);
}

void	search_path(t_var *var)
{
	int		i;
	int		best_path;
	t_dir	dir;
	t_stack	*curr;
	int len;

	if (var->b)
	{
		i = 0;
		best_path = var->size_a + var->size_b;
		curr = var->b;
		while (i < var->size_b)
		{
			refresh_dir(&dir);
			total_step(var, &dir, curr);
			len = calcule_the_best_of_the_best(&dir);
			if (len < best_path)
			{
				var->dir = dir;
				best_path = len;
			}
			curr = curr->next;
			i++;
		}
	}
}
