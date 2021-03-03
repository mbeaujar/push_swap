/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:26:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/03/03 22:10:32 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int check_instructions(char *str, t_stack **a, t_stack **b)
{
    int check;
    
    check = 0;
    if (strcmp(str, "sa") == 0)
        sa(a, &check);
    if (strcmp(str, "sb") == 0)
        sb(b, &check);
    if (strcmp(str, "ss") == 0)
        ss(a, b, &check);
    if (strcmp(str, "pa") == 0)
        pa(a, b, &check);
    if (strcmp(str, "pb") == 0)
        pb(a, b, &check);
    if (strcmp(str, "ra") == 0)
        ra();
    if (strcmp(str, "rb") == 0)
        rb();
    if (strcmp(str, "rr") == 0)
        sb();
    if (strcmp(str, "rra") == 0)
        sb();
    if (strcmp(str, "rrb") == 0)
        sb();
    if (strcmp(str, "rrr") == 0)
        sb();
    return (check);
}

void read_stdin(t_stack *a)
{
    int ret;
    char *str;
    t_stack *b;
    
    ret = 1;
    b = NULL;
    while (ret)
    {
        if ((ret = get_next_line(0, &str)) == -1)
        {
            freelist(a);
            error(1);
        }
        if (check_instructions(str, &a, &b) == 0)
        {
            freelist(a);
            freelist(b);
            error(0);
        }
    }
}