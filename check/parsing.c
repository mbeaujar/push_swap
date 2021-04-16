/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:43:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/16 22:00:41 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	error(int error)
{
	ft_putstr_fd("Error\n", 1);
	exit(error);
}

int		is_number(char *arg)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
			return (0);
		if (arg[i] == '-')
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int		recup_nb(char *arg, t_stack *begin)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (is_number(arg) == 0)
		error_free(3, begin);
	if (arg[i] == '-' && ++i)
		sign = -1;
	while (arg[i])
	{
		nb = (nb) * 10 + (arg[i] - 48);
		i++;
	}
	if (i > 11)
		error_free(1, begin);
	if (nb > 2147483647 || nb < -2147483648)
		error_free(2, begin);
	return (nb * sign);
}

void	check_nb(t_stack *begin, int nb)
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

t_stack	*parsing(int argc, char **argv, t_bonus *options)
{
	int		i;
	t_stack	*head;
	int		nb;

	if (argc == 1)
		exit(1);
	i = enable_flags(argv, options);
	empty_string(argc, argv);
	head = lstnew(recup_nb(argv[i++], NULL));
	while (i < argc)
	{
		nb = recup_nb(argv[i], head);
		check_nb(head, nb);
		lstadd_front(&head, lstnew(nb));
		i++;
	}
	return (head);
}
