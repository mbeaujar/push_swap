/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:35:02 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/20 16:10:51 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/inc/libft.h"

typedef struct	s_stack
{
	int					data;
	int					color;
	struct s_stack		*next;
}				t_stack;

typedef struct	s_bonus
{
	int			v;
	int			c;
}				t_bonus;

t_stack			*lstnew(int data);
void			lstadd_front(t_stack **alst, t_stack *neww);
void			printlist(t_stack *lst);
t_stack			*parsing(int argc, char **argv, t_bonus *options);
void			printlist(t_stack *lst);
void			freelist(t_stack *lst);
void			error(int error);
void			error_free(int error, t_stack *begin);
int				lstsize(t_stack *lst);
void			read_stdin(t_stack *a, t_bonus *options);
void			sa(t_stack **a, int *check);
void			sb(t_stack **b, int *check);
void			ss(t_stack **a, t_stack **b, int *check);
void			pa(t_stack **a, t_stack **b, int *check);
void			pb(t_stack **a, t_stack **b, int *check);
void			ra(t_stack **a, int *check);
void			rb(t_stack **b, int *check);
void			rr(t_stack **a, t_stack **b, int *check);
void			rra(t_stack **a, int *check);
void			rrb(t_stack **b, int *check);
void			rrr(t_stack **a, t_stack **b, int *check);
void			empty_string(int argc, char **argv);
int				enable_flags(char **argv, t_bonus *options);
void			is_bonus(t_stack *a, t_stack *b, t_bonus *options, int ret);
void			quit_free(char *str, int ret, t_stack *a, t_stack *b);
int				check_len(char *str);

#endif
