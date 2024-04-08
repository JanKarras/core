/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:09:34 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:20:33 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child_process(t_data *data)
{
	int	fd;

	fd = open(data->o, O_WRONLY);
	if (fd < 0)
	{
		perror("open");
		free(data);
		exit(EXIT_FAILURE);
	}
	close((data->pipefd_1)[0]);
	close((data->pipefd_1)[1]);
	close((data->pipefd_2)[1]);
	dup2((data->pipefd_2)[0], STDIN_FILENO);
	close((data->pipefd_2)[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (data->path2 != NULL)
	{
		execve(data->path2, data->argv2, data->envp);
		perror("execve");
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	first_child_process(t_data *data)
{
	close((data->pipefd_1)[1]);
	close((data->pipefd_2)[0]);
	dup2((data->pipefd_1)[0], STDIN_FILENO);
	close((data->pipefd_1)[0]);
	if ((data->path2) != NULL)
		dup2((data->pipefd_2)[1], STDOUT_FILENO);
	else
		dup2(*(data->fd_out), STDOUT_FILENO);
	close((data->pipefd_2)[1]);
	if (data->path1 != NULL)
	{
		execve(data->path1, data->argv1, data->envp);
		perror("execve");
		free(data);
		exit(EXIT_FAILURE);
	}
}

int	create_processes(t_data *data)
{
	if (pipe(data->pipefd_1) == -1)
		return (ft_putendl_fd("Pipe_1 Error", 1), -1);
	if (pipe(data->pipefd_2) == -1)
		return (ft_putendl_fd("Pipe_2 Error", 1), -1);
	*(data->cpid1) = fork();
	if (*(data->cpid1) == -1)
		return (-1);
	if (*(data->cpid1) == 0)
		first_child_process(data);
	else
	{
		*(data->cpid2) = fork();
		if (*(data->cpid2) == -1)
			return (-1);
		if (*(data->cpid2) == 0)
			second_child_process(data);
		else
			if (parent_process(data) != 0)
				return (-1);
	}
	return (0);
}
