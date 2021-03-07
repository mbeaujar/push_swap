/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:35:02 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/06 22:25:42 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/inc/libft.h"

// sa sb ss pa pb ra rb rr rra rrb rrr

typedef struct s_stack
{
    int data;
    struct s_stack *next;
} t_stack;

t_stack *lstnew(int data);
void lstadd_front(t_stack **alst, t_stack *neww);
void printlist(t_stack *lst);
t_stack *parsing(int argc, char **argv);
void printlist(t_stack *lst);
void freelist(t_stack *lst);
void error(int error);
int lstsize(t_stack *lst);
void read_stdin(t_stack *a);

void sa(t_stack **a, int *check);
void sb(t_stack **b, int *check);
void ss(t_stack **a, t_stack **b, int *check);
void pa(t_stack **a, t_stack **b, int *check);
void pb(t_stack **a, t_stack **b, int *check);
void ra(t_stack **a, int *check);
void rb(t_stack **b, int *check);
void rr(t_stack **a, t_stack **b, int *check);
void rra(t_stack **a, int *check);
void rrb(t_stack **b, int *check);
void rrr(t_stack **a, t_stack **b, int *check);

#endif 
