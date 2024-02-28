/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:57:54 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/06 21:22:57 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv_bonus(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	ft_check_double(int nb, char **argv, int i)
{
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == nb)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (ft_isdigit(nb[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_check_args(int argc, char **argv, int *flag)
{
	char	**tmp_args;
	int		i;
	long	tmp_nb;

	i = 1;
	if (argc == 2)
		tmp_args = ft_split(ft_strjoin("a ", argv[1]), ' ');
	else
		tmp_args = argv;
	if (tmp_args == NULL)
		*flag = -1;
	while (tmp_args[i] != NULL && tmp_args != NULL)
	{
		tmp_nb = ft_atoi(tmp_args[i]);
		if (ft_isnum(tmp_args[i]) == -1)
			*flag = -1;
		if (ft_check_double(tmp_nb, tmp_args, i + 1) == -1)
			*flag = -1;
		if (tmp_nb < -2147483648 || tmp_nb > 2147483647)
			*flag = -1;
		i++;
	}
	if (argc == 2)
		free_argv_bonus(tmp_args);
}

t_list	*create_new_node(int nb)
{
	int		*tmp_nb_ptr;
	t_list	*new;

	tmp_nb_ptr = (int *)malloc(sizeof(int));
	if (tmp_nb_ptr == NULL)
		return (ft_putendl_fd("Error", 1), NULL);
	*tmp_nb_ptr = nb;
	new = ft_lstnew(tmp_nb_ptr);
	if (new == NULL)
		return (free(tmp_nb_ptr), NULL);
	return (new);
}
