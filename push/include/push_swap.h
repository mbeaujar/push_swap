/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:37 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/04/16 14:09:35 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/inc/libft.h"

typedef struct	s_stack
{
	int				data;
	int				index;
	int				keep_in_stack;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

typedef struct	s_bonus
{
	int				v;
	int				c;
}				t_bonus;

typedef struct	s_ope
{
	char			*name;
	struct s_ope	*next;
}				t_ope;

typedef struct	s_dir
{
	int	a;
	int	len_a;
	int	b;
	int	len_b;
}				t_dir;

typedef struct	s_var
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*e_a;
	t_stack		*e_b;
	int			size_a;
	int			size_b;
	int			nb_keep;
	t_dir		dir;
	t_stack		*markup_head;
}				t_var;

void			error(int error);
t_stack			*parsing(int argc, char **argv, t_bonus *options);
int				lstsize(t_stack *lst);
void			freelist(t_stack *lst);
t_stack			*lstnew(int data);
void			lstadd_front(t_stack **lst, t_stack *new);
void			sa(t_var *var);
void			sb(t_var *var);
void			ss(t_var *var);
void			pa(t_var *var);
void			pb(t_var *var);
void			ra(t_var *var);
void			rb(t_var *var);
void			rr(t_var *var);
void			rra(t_var *var);
void			rrb(t_var *var);
void			rrr(t_var *var);
void			lstcpy(int *sorted, t_stack *a, int size);
void			sorting_tab(int *sorted, int len);
void			path_finding_b(t_var *var, t_dir *dir, t_stack *current);
void			path_finding_a(t_var *var, t_dir *dir, t_stack *current);
void			markup_head(t_var *var,
		int (*markup_fct)(t_stack *, t_stack *));
void			switch_to_b(t_var *var, t_ope *cmd,
		int (*markup_fct)(t_stack *, t_stack *));
void			search_path(t_var *var);
void			switch_to_a(t_var *var, t_ope *cmd);
t_ope			*solve(t_var *var, int (*markup_fct)(t_stack *, t_stack *));
int				markup_greater_than(t_stack *a, t_stack *markup_head);
int				markup_index(t_stack *a, t_stack *markup_head);
void			freelists(t_var *var);
void			listadd_back(t_ope **alst, t_ope *neww);
t_ope			*listnew(void *content);
void			indexing(t_var *var);
int				cmdsize(t_ope *cmd);
void			freecmd(t_ope *cmd);
t_stack			*search_pos(t_var *var, int index);
void			refresh_dir(t_dir *dir);
void			printlists(t_stack *a, int size);
void			printvar(t_var *var);
void			printtab(int *sorted, int len);
void			new_var(t_var *var, t_var *new_var);
void			empty_string(int argc, char **argv);
int				enable_flags(char **argv, t_bonus *options);
void			iq200(t_ope *cmd, int argc, char **argv, t_ope *free_cmd);
void			setup(t_var *var, int argc, char **argv, t_bonus *options);
void			param_struct(t_var *var);
void			ft_putstr_endl(char *str);

#endif
