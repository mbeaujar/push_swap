/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:26:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/06 16:59:57 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	check_instructions_part2(char *str, t_stack **a,
	t_stack **b, int *check)
{
	if (ft_strncmp(str, "rb", 5) == 0)
		rb(b, check);
	if (ft_strncmp(str, "rr", 5) == 0)
		rr(a, b, check);
	if (ft_strncmp(str, "rra", 5) == 0)
		rra(a, check);
	if (ft_strncmp(str, "rrb", 5) == 0)
		rrb(b, check);
	if (ft_strncmp(str, "rrr", 5) == 0)
		rrr(a, b, check);
}

int		check_instructions(char *str, t_stack **a, t_stack **b)
{
	int check;

	check = 0;
	if (ft_strncmp(str, "sa", 5) == 0)
		sa(a, &check);
	if (ft_strncmp(str, "sb", 5) == 0)
		sb(b, &check);
	if (ft_strncmp(str, "ss", 5) == 0)
		ss(a, b, &check);
	if (ft_strncmp(str, "pa", 5) == 0)
		pa(a, b, &check);
	if (ft_strncmp(str, "pb", 5) == 0)
		pb(a, b, &check);
	if (ft_strncmp(str, "ra", 5) == 0)
		ra(a, &check);
	check_instructions_part2(str, a, b, &check);
	return (check);
}

void	eval(t_stack *a, t_stack *b, int note)
{
	if (note)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (a)
		freelist(a);
	if (b)
		freelist(b);
	exit(1);
}

void	check_valid(t_stack *a, t_stack *b)
{
	t_stack *begin;

	begin = a;
	if (b != NULL)
		eval(a, b, 0);
	if (a->next == NULL)
		eval(a, b, 1);
	while (begin->next->next != NULL)
	{
		if (begin->data < begin->next->data)
			eval(a, b, 0);
		begin = begin->next;
	}
	eval(a, b, 1);
}

void	read_stdin(t_stack *a, t_bonus *options)
{
	int			ret;
	t_stack		*b;
	char		*str;

	ret = 1;
	b = NULL;
	while (ret)
	{
		if ((ret = get_next_line(0, &str)) == -1)
		{
			freelist(a);
			if (b)
				freelist(b);
			error(1);
		}
		if (ret && check_instructions(str, &a, &b) == 0)
		{
			freelist(a);
			freelist(b);
			error(0);
		}
		is_bonus(a, b, options);
	}
	check_valid(a, b);
}
