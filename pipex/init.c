/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:55 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:14:32 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_args_cmds(t_data *data, char **argv)
{
	data->i = ft_strdup(argv[1]);
	if (data->i == NULL)
		return (-1);
	data->o = ft_strdup(argv[4]);
	if (data->o == NULL)
		return (ft_free_data(data), -1);
	data->f = ft_strdup(argv[2]);
	if (data->f == NULL)
		return (ft_free_data(data), -1);
	data->s = ft_strdup(argv[3]);
	if (data->s == NULL)
		return (ft_free_data(data), -1);
	data->envp = (char **)malloc(sizeof(char *));
	if (data->envp == NULL)
		return (ft_free_data(data), -1);
	(data->envp)[0] = NULL;
	data->argv1 = ft_split(data->f, ' ');
	if (data->argv1 == NULL)
		return (ft_free_data(data), -1);
	data->argv2 = ft_split(data->s, ' ');
	if (data->argv2 == NULL)
		return (ft_free_data(data), -1);
	return (0);
}

int	init_path_helper(t_data *data)
{
	data->path1 = ft_strjoin("/bin/", (data->argv1)[0]);
	if (data->path1 == NULL)
		return (ft_free_data(data), -1);
	data->path2 = ft_strjoin("/bin/", (data->argv2)[0]);
	if (data->path2 == NULL)
		return (ft_free_data(data), -1);
	return (0);
}

int	init_paths(t_data *data)
{
	if ((data->argv1)[0] != NULL && (data->argv2)[0] != NULL)
	{
		if (init_path_helper(data) != 0)
			return (-1);
	}
	else if ((data->argv1)[0] != NULL)
	{
		data->path1 = ft_strjoin("/bin/", (data->argv1)[0]);
		if (data->path1 == NULL)
			return (ft_free_data(data), -1);
		data->path2 = NULL;
	}
	else if ((data->argv2)[0] != NULL)
	{
		data->path2 = ft_strjoin("/bin/", (data->argv2)[0]);
		if (data->path2 == NULL)
			return (ft_free_data(data), -1);
		data->path1 = NULL;
	}
	else
	{
		data->path1 = NULL;
		data->path2 = NULL;
	}
	return (0);
}

int	init_fd_cpid(t_data *data)
{
	data->fd_in = (int *)malloc(sizeof(int));
	if (data->fd_in == NULL)
		return (ft_free_data(data), -1);
	data->fd_out = (int *)malloc(sizeof(int));
	if (data->fd_out == NULL)
		return (ft_free_data(data), -1);
	data->pipefd_1 = (int *)malloc(sizeof(int) * 2);
	if (data->pipefd_1 == NULL)
		return (ft_free_data(data), -1);
	data->pipefd_2 = (int *)malloc(sizeof(int) * 2);
	if (data->pipefd_2 == NULL)
		return (ft_free_data(data), -1);
	data->cpid1 = (pid_t *)malloc(sizeof(pid_t));
	if (data->cpid1 == NULL)
		return (ft_free_data(data), -1);
	data->cpid2 = (pid_t *)malloc(sizeof(pid_t));
	if (data->cpid2 == NULL)
		return (ft_free_data(data), -1);
	return (0);
}

int	init(t_data *data, char **argv)
{
	if (init_args_cmds(data, argv) != 0)
		return (ft_putendl_fd("Malloc Error", 1), -1);
	if (init_paths(data) != 0)
		return (ft_putendl_fd("Malloc Error", 1), -1);
	if (init_fd_cpid(data) != 0)
		return (ft_putendl_fd("Malloc Error", 1), -1);
	return (0);
}
