/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:28 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/11 14:44:44 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_file(t_data *data)
{
	int		b;
	int		fd;
	char	buff[2];

	fd = open(data->i, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Can't open infile"), -1);
	b = 1;
	while (b != 0)
	{
		b = read(fd, buff, 1);
		if (b < 0)
			return (ft_printf("Read Error"), -1);
		buff[b] = '\0';
		write((data->pipefd_1)[1], buff, b);
	}
	close(fd);
	return (0);
}

void	parent_process(t_data *data)
{
	int	fd;

	close((data->pipefd_1)[0]);
	close((data->pipefd_2)[1]);
	if (!data->infile_error)
	{
		if (read_file(data) != 0)
		{
			ft_free_data(data);
			exit(EXIT_FAILURE);
		}
	}
	close((data->pipefd_1)[1]);
	fd = open(data->o, O_WRONLY | O_TRUNC);
	if (fd < 0)
	{
		ft_putendl_fd("Error, open outfile", 2);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	dup2((data->pipefd_2)[0], STDIN_FILENO);
	close((data->pipefd_2)[0]);
	//dup2(fd, STDOUT_FILENO);
	close(fd);
	execve(data->path2, data->argv2, data->envp);
	perror("execve");
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

void	child_process(t_data *data)
{
	close((data->pipefd_1)[1]);
	close((data->pipefd_2)[0]);
	dup2((data->pipefd_1)[0], STDIN_FILENO);
	close((data->pipefd_1)[0]);
	dup2((data->pipefd_2)[1], STDOUT_FILENO);
	close((data->pipefd_2)[1]);
	if (execve(data->path1, data->argv1, data->envp) != 0)
	{
		ft_putstr_fd(data->f, 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_free_data(data);
		exit(EXIT_SUCCESS);
	}
}

void	processes(t_data *data)
{
	if (pipe(data->pipefd_1) == -1)
	{
		ft_printf("Error, creating pipe");
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	if (pipe(data->pipefd_2) == -1)
	{
		ft_printf("Error, creating pipe");
		close((data->pipefd_1)[0]);
		close((data->pipefd_1)[1]);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	*(data->cpid1) = fork();
	if (*(data->cpid1) < 0)
	{
		ft_printf("Error, creating child");
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
	else if (*(data->cpid1) == 0)
		child_process(data);
	else
		parent_process(data);
}
