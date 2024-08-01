/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/01 19:56:35 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sort2(t_nodes **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
    return (0);
}

void ft_sort3(t_nodes **stack_a)
{
    if (ft_lstsize_int(*stack_a) != 3)
        return;

    int first = (*stack_a)->index;
    int second = (*stack_a)->next->index;
    int third = (*stack_a)->next->next->index;

    if (first > second && second < third && third > first) 
        sa(stack_a);
    else if (first > second && second > third && third < first)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && third < first)
        ra(stack_a);
    else if (first < second && second > third && third > first)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && third < first)
        rra(stack_a);
}

