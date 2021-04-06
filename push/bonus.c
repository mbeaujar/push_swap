/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:28:48 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/07 00:32:07 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void instru(char *name, t_var *var)
{
	if (ft_strncmp(name, "sa", 5) == 0)
		sa(var);
	if (ft_strncmp(name, "sb", 5) == 0)
		sb(var);
	if (ft_strncmp(name, "ss", 5) == 0)
		ss(var);
	if (ft_strncmp(name, "pa", 5) == 0)
		pa(var);
	if (ft_strncmp(name, "pb", 5) == 0)
		pb(var);
	if (ft_strncmp(name, "ra", 5) == 0)
		ra(var);
	if (ft_strncmp(name, "rb", 5) == 0)
		rb(var);
	if (ft_strncmp(name, "rr", 5) == 0)
		rr(var);
	if (ft_strncmp(name, "rra", 5) == 0)
		rra(var);
	if (ft_strncmp(name, "rrb", 5) == 0)
		rrb(var);
	if (ft_strncmp(name, "rrr", 5) == 0)
		rrr(var);
}


void iq200(t_ope *cmd, int argc, char **argv, t_ope *free_cmd)
{
	t_var var;
	t_bonus options;
	t_ope *tmp;

	init_struct(&var);
	var.a = parsing(argc, argv, &options);
	indexing(&var);
	param_struct(&var);
	freecmd(free_cmd);
	tmp = cmd;
	cmd = cmd->next;
	free(tmp);
	while (cmd)
	{
		if (options.c && cmd->next == NULL)
			ft_printf("\033[1;31m%s\033[0m\n", cmd->name);
		else
			ft_printf("%s\n", cmd->name);
		tmp = cmd;
		instru(cmd->name, &var);
		cmd = cmd->next;
		free(tmp);
		ft_printf("Stack a : ");
		printlists(var.a, var.size_a);
		ft_printf("\nStack b : ");
		printlists(var.b, var.size_b);
		ft_printf("\n");
	}
	freelists(&var);
	exit(1);
}