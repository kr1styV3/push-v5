/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_revrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:02:15 by mailinci          #+#    #+#             */
/*   Updated: 2024/07/23 23:13:28 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_nodes **stack_a)
{
    t_nodes *prev;
    t_nodes *last;

    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
        return;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    ft_putendl_fd("rra", 1);
}

void rrb(t_nodes **stack_b)
{
    t_nodes *prev;
    t_nodes *last;

    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
        return;
    last = *stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    ft_putendl_fd("rrb", 1);
}

void rrr(t_nodes **stack_a, t_nodes **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_putendl_fd("rrr", 1);
}
