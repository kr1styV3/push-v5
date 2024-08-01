/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:42:51 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/01 19:29:43 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves *moves_init()
{
    t_moves *moves = malloc(sizeof(t_moves));

    moves->ra = 0;
    moves->rb = 0;
    moves->rra = 0;
    moves->rrb = 0;
    moves->rr = 0;
    moves->rrr = 0;
    moves->dest = NULL;
    return moves;
}

void cancel_out_rotations(t_moves *moves, int size_a, int size_b)
{
    if (moves->ra > size_a / 2)
        moves->rra = size_a - moves->ra;
    if (moves->rb > size_b / 2)
        moves->rrb = size_b - moves->rb;
    moves->ra = moves->rra_after_push;
}

int ft_push_cost(t_nodes *node_b)
{
    int cost = 0;

    t_nodes *current_b = node_b;

    while (current_b->moves->ra >= 1 && current_b->moves->rb >= 1)
    {
        current_b->moves->rr++;
        current_b->moves->ra--;
        current_b->moves->rb--;
    }
    while (current_b->moves->rra >= 1 && current_b->moves->rrb >= 1)
    {
        current_b->moves->rrr++;
        current_b->moves->rra--;
        current_b->moves->rrb--;
    }
    cost = current_b->moves->ra + current_b->moves->rb + current_b->moves->rra + current_b->moves->rrb + current_b->moves->rr + current_b->moves->rrr;

    //printf("DEBUG ft_push_cost:      Cost of pushing %d is %d\n", node_b->value, cost);
    return cost;
}

void apply_rot_double(int *moves, void (*rotate_fx)(t_nodes **, t_nodes **), t_nodes **stack_a, t_nodes **stack_b)
{
    while (*moves > 0)
    {
        rotate_fx(stack_a, stack_b);
        (*moves)--;
    }
}
void apply_rot_single(int *moves, void (*rotate_fx)(t_nodes **), t_nodes **stack)
{
    while (*moves > 0)
    {
        rotate_fx(stack);
        (*moves)--;
    }
}

void apply_moves(t_nodes *cheapest_node, t_nodes **stack_a, t_nodes **stack_b)
{
    printf("DEBUG\tt_moves: ra: %d, rb: %d, rra: %d, rrb: %d, rr: %d, rrr: %d\n rra_after_push : %d\n", 
           cheapest_node->moves->ra, 
           cheapest_node->moves->rb, 
           cheapest_node->moves->rra, 
           cheapest_node->moves->rrb, 
           cheapest_node->moves->rr, 
           cheapest_node->moves->rrr, 
           cheapest_node->moves->rra_after_push);

    if (cheapest_node->moves->rr > 0)
        apply_rot_double(&(cheapest_node->moves->rr), rr, stack_a, stack_b);
    if (cheapest_node->moves->rrr > 0)
        apply_rot_double(&(cheapest_node->moves->rrr), rrr, stack_a, stack_b);
    if (cheapest_node->moves->ra > 0)
        apply_rot_single(&(cheapest_node->moves->ra), ra, stack_a);
    if (cheapest_node->moves->rb > 0)
        apply_rot_single(&(cheapest_node->moves->rb), rb, stack_b);
    if (cheapest_node->moves->rra > 0)
        apply_rot_single(&(cheapest_node->moves->rra), rra, stack_a);
    if (cheapest_node->moves->rrb > 0)
        apply_rot_single(&(cheapest_node->moves->rrb), rrb, stack_b);

    pa(stack_a, stack_b);
    if (cheapest_node->moves->rra_after_push > 0)
        apply_rot_single(&(cheapest_node->moves->rra_after_push), rra, stack_a);
}
