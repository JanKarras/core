/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions_array_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:22:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/06 20:08:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_functions(char **functions)
{
	int	i;

	i = 0;
	while (functions[i] != NULL)
	{
		free(functions[i]);
		i++;
	}
	free(functions);
}

void	fill_array(char **functions)
{
	ft_strlcpy(functions[0], "sa\n", 5);
	ft_strlcpy(functions[1], "sb\n", 5);
	ft_strlcpy(functions[2], "ss\n", 5);
	ft_strlcpy(functions[3], "pa\n", 5);
	ft_strlcpy(functions[4], "pb\n", 5);
	ft_strlcpy(functions[5], "ra\n", 5);
	ft_strlcpy(functions[6], "rb\n", 5);
	ft_strlcpy(functions[7], "rr\n", 5);
	ft_strlcpy(functions[8], "rra\n", 5);
	ft_strlcpy(functions[9], "rrb\n", 5);
	ft_strlcpy(functions[10], "rrr\n", 5);
	functions[11] = NULL;
}

char	**get_functions_array(void)
{
	int		i;
	char	**functions;

	functions = (char **)malloc(sizeof(char *) * 12);
	if (functions == NULL)
		return (NULL);
	i = 0;
	while (i < 12)
	{
		functions[i] = (char *)malloc(sizeof(char) * 5);
		if (functions[i] == NULL)
			return (free_functions(functions), NULL);
		i++;
	}
	fill_array(functions);
	return (functions);
}
