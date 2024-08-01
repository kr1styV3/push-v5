/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/01 19:21:17 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
in ft_order_check: 0 disordinato, 1 ordinato

nel caso in cui l'input sia una stringa vuota stampo:
"Usage: ./push_swap <numbers>\n" oppure "Error: No stack found\n"
forse dovrei controllarli assieme e stampare un solo messaggio di errore
controllando se il primo char e' \0 con: (argc == 2 && !argv[1][0])


*/

#include "push_swap.h"

int	ft_isdup(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_order_check(t_nodes *stack)
{
	t_nodes	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	if (current != NULL)
		return (1);
	return (0);
}

char	**ft_usage_check(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		args = argv + 1;
		if (argc == 1)
		{
			ft_printf("Usage: ./push_swap <numbers>\n");
			exit(1);
		}
	}
	return (args);
}

char	**ft_arg_checker(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	args = ft_usage_check(argc, argv);
	while (args[i])
	{
		if (!ft_isnum(args[i]))
		{
			ft_printf("Error: Invalid stack. Only numbers allowed\n");
			exit(1);
		}
		tmp = ft_atoi_minmax(args[i]);
		if (ft_isdup(tmp, args, i))
		{
			ft_printf("Error: Invalid stack. Contains duplicate\n");
			exit(1);
		}
		i++;
	}
	return (args);
}
