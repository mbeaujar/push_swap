/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 19:11:47 by mbeaujar         ###   ########.fr       */
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

void	init_struct(t_var *var)
{
	var->a = NULL;
	var->e_a = NULL;
	var->b = NULL;
	var->e_b = NULL;
	var->size_a = 0;
	var->size_b = 0;
	var->nb_keep = 0;
	var->markup_head = NULL;
}

void	compare_resultat_part2(t_ope *cmd_gt, t_ope *cmd_index)
{
	t_ope *tmp;

	freecmd(cmd_index);
	tmp = cmd_gt;
	cmd_gt = cmd_gt->next;
	free(tmp);
	while (cmd_gt)
	{
		ft_printf("%s\n", cmd_gt->name);
		tmp = cmd_gt;
		cmd_gt = cmd_gt->next;
		free(tmp);
	}
}

void	compare_resultat(t_ope *cmd_gt, t_ope *cmd_index)
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
			ft_printf("%s\n", cmd_index->name);
			tmp = cmd_index;
			cmd_index = cmd_index->next;
			free(tmp);
		}
	}
	else
		compare_resultat_part2(cmd_gt, cmd_index);
}

int		main(int argc, char **argv)
{
	t_var var;
	t_ope *cmd_gt;
	t_ope *cmd_index;

	if (argc == 1)
		error(1);
	init_struct(&var);
	var.a = parsing(argc, argv);
	indexing(&var);
	param_struct(&var);
	markup_head(&var, markup_greater_than);
	cmd_gt = solve(&var, markup_greater_than);
	//printvar(&var); //
	freelists(&var);
	init_struct(&var);
	var.a = parsing(argc, argv);
	indexing(&var);
	param_struct(&var);
	markup_head(&var, markup_index);
	cmd_index = solve(&var, markup_index);
	//printvar(&var); //
	compare_resultat(cmd_gt, cmd_index);
	freelists(&var);
	return (0);
}
