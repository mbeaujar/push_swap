/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:18:46 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/08 16:06:00 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

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

void	printlists(t_stack *a, t_stack *b, t_bonus *options)
{
	ft_printf("\n-------------------------------\n");
	ft_printf("base |");
	while (a)
	{
		if (options->c && a->color && a->color--)
			ft_printf(" \033[1;31m%d\033[0m ->", a->data);
		else
			ft_printf(" %d ->", a->data);
		a = a->next;
	}
	ft_printf(" NULL | sommet\n");
	ft_printf("base |");
	while (b)
	{
		if (options->c && b->color && b->color--)
			ft_printf(" \033[1;31m%d\033[0m ->", b->data);
		else
			ft_printf(" %d ->", b->data);
		b = b->next;
	}
	ft_printf(" NULL | sommet\n");
	ft_printf("\n-------------------------------\n");
}

void	is_bonus(t_stack *a, t_stack *b, t_bonus *options, int ret)
{
	if (ret && options->v)
		printlists(a, b, options);
}
