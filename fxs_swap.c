/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:25:32 by mailinci          #+#    #+#             */
/*   Updated: 2024/07/23 23:13:43 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_nodes **stack_a)
{
    t_nodes *first;
    t_nodes *second;

    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
        return 0;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    ft_putendl_fd("sa", 1);
    return 1;
}

int sb(t_nodes **stack_b)
{
    t_nodes *first;
    t_nodes *second;

    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
        return 0;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    ft_putendl_fd("sb", 1);
    return 1;
}

int ss(t_nodes **stack_a, t_nodes **stack_b)
{
    int result_a;
    int result_b;

    result_a = sa(stack_a);
    result_b = sb(stack_b);
    ft_putendl_fd("ss", 1);
    return result_a && result_b;
}
