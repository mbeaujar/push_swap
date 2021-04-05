/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:43:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/05 15:02:46 by beaujardm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	error(int error)
{
	ft_printf("Error\n");
	exit(error);
}

int		is_number(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		recup_nb(char *arg, t_stack *begin)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	if (is_number(arg) == 0)
		error_free(1, begin);
	while (arg[i])
	{
		nb = (nb) * 10 + (arg[i] - 48);
		i++;
	}
	if (i > 11)
		error_free(1, begin);
	if (nb > 2147483647 || nb < -2147483648)
		error_free(1, begin);
	return (nb);
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

t_stack	*parsing(int argc, char **argv)
{
	int		i;
	t_stack	*head;
	int		nb;

	i = 1;
	if (argc == 1)
		error(1);
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
