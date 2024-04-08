/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:03:21 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/14 16:00:55 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	alloc_cmd_path(t_data *data)
{
	if ((data->argv1)[0] != NULL && (data->argv2)[0] != NULL)
	{
		data->path1 = ft_strjoin("/bin/", (data->argv1)[0]);
		data->path2 = ft_strjoin("/bin/", (data->argv2)[0]);
	}
	else if ((data->argv1)[0] != NULL)
	{
		data->path1 = ft_strjoin("/bin/", (data->argv1)[0]);
		data->path2 = NULL;
	}
	else if ((data->argv2)[0] != NULL)
	{
		data->path2 = ft_strjoin("/bin/", (data->argv2)[0]);
		data->path1 = NULL;
	}
	else
	{
		data->path1 = NULL;
		data->path2 = NULL;
	}
	return (0);
}

int	alloc_cmd_mem(t_data *data)
{
	data->argv1 = ft_split(data->f, ' ');
	if (data->argv1 == NULL)
		return (-1);
	data->argv2 = ft_split(data->s, ' ');
	if (data->argv2 == NULL)
		return (-1);
	data->envp = (char **)malloc(sizeof(char *));
	if (data->envp == NULL)
		return (-1);
	(data->envp)[0] = NULL;
	if (alloc_cmd_path(data) != 0)
		return (-1);
	return (0);
}

int	init(char **argv, t_data *data)
{
	data->i = ft_strdup(argv[1]);
	if (data->i == NULL)
		return (free(data), -1);
	data->f = ft_strdup(argv[2]);
	if (data->f == NULL)
		return (free_data(data), -1);
	data->s = ft_strdup(argv[3]);
	if (data->s == NULL)
		return (free_data(data), -1);
	data->o = ft_strdup(argv[4]);
	if (data->o == NULL)
		return (free_data(data), -1);
	if (alloc_cmd_mem(data) != 0)
		return (free_data(data), -1);
	return (0);
}
