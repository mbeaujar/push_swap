/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:30:47 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/07 16:54:19 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	printlists(t_stack *a, int size)
{
	int i;

	if (a)
	{
		i = 0;
		while (i < size)
		{
			ft_printf("%d ", a->data);
			a = a->next;
			i++;
		}
	}
}

void	printvar(t_var *var)
{
	ft_printf("\n------------------------------\n");
	if (var->markup_head)
		ft_printf("markup_head : %d\n", var->markup_head->data);
	ft_printf("size_a : %d\nsize_b : %d\n", var->size_a, var->size_b);
	ft_printf("a : %d e_a : %d\n", var->a->data, var->e_a->data);
	if (var->b)
		ft_printf("b : %d e_b : %d\n", var->b->data, var->e_b->data);
	printlists(var->a, var->size_a);
	ft_printf("\n");
	printlists(var->b, var->size_b);
	ft_printf("\n------------------------------\n");
}

void	empty_string(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			error(1);
		i++;
	}
}

void	enable_flags_part2(char **argv, t_bonus *options, int *nb_options)
{
	if (ft_strncmp(argv[2], "-v", 3) == 0)
	{
		if (options->v)
			error(5);
		options->v = 1;
		(*nb_options)++;
	}
	if (ft_strncmp(argv[2], "-c", 3) == 0)
	{
		if (options->c)
			error(4);
		options->c = 1;
		(*nb_options)++;
	}
}

int		enable_flags(char **argv, t_bonus *options)
{
	int nb_options;

	nb_options = 1;
	options->v = 0;
	options->c = 0;
	if (ft_strncmp(argv[1], "-v", 3) == 0)
	{
		options->v = 1;
		nb_options++;
	}
	if (ft_strncmp(argv[1], "-c", 3) == 0)
	{
		options->c = 1;
		nb_options++;
	}
	if (nb_options > 1)
		enable_flags_part2(argv, options, &nb_options);
	return (nb_options);
}
