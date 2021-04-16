/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/16 14:09:54 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	param_struct(t_var *var)
{
	t_stack	*tmp;
	int		i;

	tmp = var->a;
	i = 0;
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	var->e_a = tmp;
	var->size_a = ++i;
	var->e_a->next = var->a;
	var->a->previous = var->e_a;
}

void	compare_resultat_part2(t_ope *cmd_gt,
	t_ope *cmd_index, t_bonus *options)
{
	t_ope *tmp;

	freecmd(cmd_index);
	tmp = cmd_gt;
	cmd_gt = cmd_gt->next;
	free(tmp);
	while (cmd_gt)
	{
		if (options->c && cmd_gt->next == NULL)
			ft_printf("\033[1;31m%s\033[0m\n", cmd_gt->name);
		else
			ft_putstr_endl(cmd_gt->name);
		tmp = cmd_gt;
		cmd_gt = cmd_gt->next;
		free(tmp);
	}
}

void	compare_resultat(t_ope *cmd_gt, t_ope *cmd_index, t_bonus *options)
{
	t_ope *tmp;

	if (cmdsize(cmd_gt) > cmdsize(cmd_index))
	{
		freecmd(cmd_gt);
		tmp = cmd_index;
		cmd_index = cmd_index->next;
		free(tmp);
		while (cmd_index)
		{
			if (options->c && cmd_index->next == NULL)
				ft_printf("\033[1;31m%s\033[0m\n", cmd_index->name);
			else
				ft_putstr_endl(cmd_index->name);
			tmp = cmd_index;
			cmd_index = cmd_index->next;
			free(tmp);
		}
	}
	else
		compare_resultat_part2(cmd_gt, cmd_index, options);
}

void	setup(t_var *var, int argc, char **argv, t_bonus *options)
{
	var->a = NULL;
	var->e_a = NULL;
	var->b = NULL;
	var->e_b = NULL;
	var->size_a = 0;
	var->size_b = 0;
	var->nb_keep = 0;
	var->markup_head = NULL;
	var->a = parsing(argc, argv, options);
	indexing(var);
	param_struct(var);
}

int		main(int argc, char **argv)
{
	t_var	var;
	t_ope	*cmd_gt;
	t_ope	*cmd_index;
	t_bonus	options;

	if (argc == 1)
		exit(1);
	setup(&var, argc, argv, &options);
	markup_head(&var, markup_greater_than);
	cmd_gt = solve(&var, markup_greater_than);
	freelists(&var);
	setup(&var, argc, argv, &options);
	markup_head(&var, markup_index);
	cmd_index = solve(&var, markup_index);
	freelists(&var);
	if (options.v)
		iq200(cmdsize(cmd_gt) > cmdsize(cmd_index) ? cmd_index : cmd_gt,
		argc, argv,
		cmdsize(cmd_gt) > cmdsize(cmd_index) ? cmd_gt : cmd_index);
	compare_resultat(cmd_gt, cmd_index, &options);
	return (0);
}
