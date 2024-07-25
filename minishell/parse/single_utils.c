/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:52:00 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 17:27:49 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cut_fds(t_data *data)
{
	size_t	i;

	i = 0;
	while ((data->split_input)[i])
	{
		if ((data->split_input)[i][0] == '<' || (data->split_input)[i][0] == '>')
		{
			if ((data->split_input)[i][1] != '\0')
			{
				del_index(data, i);
				i = 0;
			}
			else if ((data->split_input)[i + 1] != NULL)
			{
				del_index(data, i);
				del_index(data, i);
				i = 0;
			}
		}
		i++;
	}
}

void	del_index(t_data *data, size_t i)
{
	if ((data->split_input)[i] != NULL)
		free((data->split_input)[i]);
	while ((data->split_input)[i])
	{
		(data->split_input)[i] = (data->split_input)[i + 1];
		i++;
	}
}

void	del_index_char(char **arr, size_t i)
{
	if (arr[i] != NULL)
		free(arr[i]);
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
}

int	is_builtin(char **cmd)
{
	if (ft_strncmp(cmd[0], "cd", 2) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "export", 6) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "unset", 5) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "exit", 4) == 0)
		return (0);
	if (ft_strncmp(cmd[0], "env", 3) == 0)
		return (0);
	return (1);
}
