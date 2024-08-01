/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:52:26 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/01 23:43:06 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_createstack_a(char **args)
{
	t_nodes	*stack_a;
	t_nodes	*value;
	int		num; //nel caso di zero non crea il primo nodo
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i] != NULL)
	{
        num = ft_atoi_minmax(args[i]);
        //printf("DEBUG: Processing value: %d\n", num);
		value = ft_lstnew_int(num);
        //printf("DEBUG: Adding value: %d\n\n", num);
		ft_lstadd_back_int(&stack_a, value);
		i++;
	}
	return (stack_a);
}

void	ft_print_nodes(t_nodes *stack)
{
	t_nodes *current = stack;
	while (current)
	{
		printf("[%d] -> ", current->value);
		current = current->next;
	}
	printf("[NULL]\n");
}


int     ft_create_temp_array(t_nodes *stack, int **array)
{
    int len = ft_lstsize_int(stack);
	t_nodes *current = stack;
    int i = 0;

    *array = malloc(sizeof(int) * len);
	while (current)
	{
		(*array)[i++] = current->value;
		current = current->next;
	}
    return (i);
}

void ft_print_indices_and_values(t_nodes *stack_a)
{
    t_nodes *current = stack_a;

    while (current != NULL)
    {
        printf("index: %d \t value: %d\n", current->index, current->value);
        current = current->next;
    }
}

// void ft_cheapest(t_nodes *stack_a, t_nodes *stack_b)
// {
//     t_nodes *current = stack_b;
//     t_moves *rise_cost_rotate_a;
//     t_moves *rise_cost_reverse_rotate_stack_a=
//     t_moves *rise_cost_rotate_stack_b=

//     if index proximity to the top of the stack is less than the bottom of the stack

//         current->
//         }
//         current = current->next;
//     }
//     free(moves);
//     return (*cheapest_moves);
// }

void index_moves(int index, t_moves *moves, int i)
{

}

t_moves *return_bestindex(t_nodes *stack_b, t_nodes *stack_a)
{
    t_nodes *current = stack_b;
    t_moves *top_node_stack_a;
    t_moves *top_node_stack_b;
    unsigned int ra = 0;
    unsigned int rb = 0;
    int cost = 0;

if (current->index > current->next->index )

    while (current != NULL)
    {
        moves = moves_init();
        moves->dest = current;
§

        cost = ft_push_cost(current);
        if (cost > best_cost)
        {
            best_cost = cost;
            best_moves->ra = current->moves->ra;
            best_moves->rb = current->moves->rb;
            best_moves->rra = current->moves->rra;
            best_moves->rrb = current->moves->rrb;
            best_moves->rr = current->moves->rr;
            best_moves->rrr = current->moves->rrr;
            best_moves->dest = current->moves->dest;
        }
        current = current->next;
    }
    free(moves);
    return (best_moves);
}


int	main(int argc, char **argv)
{
    t_nodes *stack_a = NULL;
    t_nodes *stack_b = NULL;
    t_moves *moves;
    char **args;
    int free_flag;
    int *temp_array = NULL;
    int len = 0;
    int stack_size = ft_lstsize_int(stack_a);
    int *array = NULL;
    int i;
    int chunk_size = 0;

    free_flag = 0;
    args = ft_arg_checker(argc, argv);

    if (argc == 2 && args != argv)
        free_flag = 1;

    stack_a = ft_createstack_a(args);
    stack_b = NULL;

    if (ft_order_check(stack_a) || ft_lstsize_int(stack_a) == 1)
    {
        ft_printf("Error: stack already ordered\n");
        if (free_flag)
            free(args);
        exit(1);
    }

    if (!stack_a)
    {
        ft_printf("Error: No stack found\n");
        if (free_flag)
            free(args);
        return (1);
    }


    stack_size = ft_lstsize_int(stack_a);
    array = malloc(sizeof(int) * stack_size);
    if (!array)
    {
        ft_printf("Error: Memory allocation failed\n");
        if (free_flag)
            free(args);
        return (1);
    }

    t_nodes *current = stack_a;
    for (i = 0; current != NULL; i++)
    {
        array[i] = current->value;
        current = current->next;
    }


    len = ft_create_temp_array(stack_a, &temp_array);
    cold_start(temp_array, &stack_a, len);
    ft_sort_temp_array(temp_array, len);
    //ft_print_temp_array(temp_array, len);
    ft_assign_indices(stack_a, temp_array, len);
    ft_print_indices_and_values(stack_a);
    printf("\n");

    chunk_size = make_chunks(stack_size);
    (void)chunk_size;
    push_chunks(&stack_a, &stack_b, stack_size);


    printf("\nstack_a\n");
	ft_print_nodes(stack_a);
    printf("\nstack_b\n");
    ft_print_nodes(stack_b);
    if (ft_lstsize_int(stack_a) == 3)
    {
        ft_sort3(&stack_a);
    }
    free (temp_array);

    while (stack_b)
    {
        ft_apply_moves(moves, &stack_a, &stack_b);
        free(moves);
    }
    // ft_rotate_to_min

    printf("\nstack_a\n");
	ft_print_nodes(stack_a);
    printf("\nstack_b\n");
    ft_print_nodes(stack_b);



    free(array);
    if (free_flag)
        free(args);
    if (temp_array)
        free(temp_array);

    return 0;
}
