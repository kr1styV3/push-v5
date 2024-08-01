/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:42:17 by mailinci          #+#    #+#             */
/*   Updated: 2024/07/23 23:13:35 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_nodes **stack_a)
{
    t_nodes *first;
    t_nodes *last;

    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
        return;
    first = *stack_a;
    *stack_a = first->next;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_putendl_fd("ra", 1);
}

void rb(t_nodes **stack_b)
{
    t_nodes *first;
    t_nodes *last;

    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
        return;
    first = *stack_b;
    *stack_b = first->next;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_putendl_fd("rb", 1);
}

void rr(t_nodes **stack_a, t_nodes **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_putendl_fd("rr", 1);
}



