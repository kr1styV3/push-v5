/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:31:02 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/01 19:01:47 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_left(int arr[], int temp_left[], int left, int low)
{
	int	i;

	i = 0;
	while (i < left)
	{
		temp_left[i] = arr[low + i];
		i++;
	}
}

void	fill_right(int arr[], int temp_right[], int right, int middle)
{
	int	i;

	i = 0;
	while (i < (right))
	{
		temp_right[i] = arr[middle + 1 + i];
		i++;
	}
}


int	create_arrays(int left, int right, int **temp_left, int **temp_right)
{
	*temp_left = malloc(sizeof(int) * left);
	if (!temp_left)
	{
		printf("ERROR: temp_left allocation failed");
		return (-1);
	}
	*temp_right = malloc(sizeof(int) * right);
	if (!temp_right)
	{
		free(temp_left);
		printf("ERROR: temp_right allocation failed");
		return (-1);
	}
	return (0);
}

int	cold_start(int arr[], t_nodes **list_a, int length)
{
	t_nodes	*current;
	int		index;
	current = *list_a;

	merge_sort(arr, length);

	//for(int i = 0; i < length; i++)
	//	printf("DEBUG: arr[%d] = %d\n", i, arr[i]);

	index = 0;
	while (index + 1 < length)
	{
		if ((arr)[index] == (arr)[index + 1])
			return (1);
		index++;
	}
	while (current != NULL)
	{
		index = binary_search(arr, current->value, 0, length);
		if (index < 0)
			return (-1);
		current->index = index;
		current = current->next;
	}
	return (0);
}

void	merge_sort(int arr[], int length)
{
	merge_sort_recursion(arr, 0, length - 1);
}

void	merge_sort_recursion(int arr[], int low, int high)
{
	int	middle;

	if (low >= high)
		return ;
	middle = low + (high - low) / 2;
	merge_sort_recursion(arr, low, middle);
	merge_sort_recursion(arr, middle + 1, high);
	merge_sorted_arrays(arr, low, middle, high);
}

void	merge_sorted_arrays(int arr[], int low, int middle, int high)
{
	int	i;
	int	j;
	int	k;
	int	*temp_left;
	int	*temp_right;

	i = create_arrays(middle - low + 1, high - middle, &temp_left, &temp_right);
	if (i == -1)
		return ;
	fill_left(arr, temp_left, middle - low + 1, low);
	fill_right(arr, temp_right, high - middle, middle);
	i = low;
	j = 0;
	k = 0;
	while (i <= high)
	{
		if ((j < (middle - low + 1)) && (k >= (high - middle)
				|| temp_left[j] <= temp_right[k]))
			arr[i] = temp_left[j++];
		else
			arr[i] = temp_right[k++];
		i++;
	}
	free(temp_left);
	free(temp_right);
}

int	binary_search(int arr[], int target, int low, int high)
{
	int	i;

	i = (low + high) / 2;
	if (arr[i] == target)
		return (i);
	if (low >= high)
		return (-1);
	if (arr[i] < target)
		return (binary_search(arr, target, i + 1, high));
	if (arr[i] > target)
		return (binary_search(arr, target, low, i - 1));
	return (i);
}
int *ft_sort_temp_array(int arr[], int length)
{
    merge_sort(arr, length);

    int *sorted_array = (int *)malloc(sizeof(int) * length);
    if (!sorted_array)
    {
        printf("ERROR: Allocation for sorted_array failed\n");
        return NULL;
    }

    int i = 0;
    while (i < length)
    {
        sorted_array[i] = arr[i];
        i++;
    }

    return sorted_array;
}

void ft_print_array(int arr[], int length)
{
    int i = 0;
    printf("Sorted array:\n");
    while (i < length)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}




void ft_assign_indices(t_nodes *stack_a, int *sorted_array, int length)
{
    t_nodes *current = stack_a;
    int index;

    while (current != NULL)
    {
        index = 0;
        while (index < length)
        {
            if (sorted_array[index] == current->value)
            {
                current->index = index;
                break;
            }
            index++;
        }
        current = current->next;
    }
}




