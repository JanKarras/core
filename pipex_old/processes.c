/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:03:50 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/14 16:08:23 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child_process(t_data *data, int *pipefd_1, int *pipefd_2)
{
	int	fd;

	fd = open(data->o, O_WRONLY);
	if (fd < 0)
	{
		perror("open");
		free(data);
		exit(EXIT_FAILURE);
	}
	close(pipefd_1[0]);
	close(pipefd_1[1]);
	close(pipefd_2[1]);
	dup2(pipefd_2[0], STDIN_FILENO);
	close(pipefd_2[0]);
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

void	first_child_process(t_data *data, int *pipefd_1, int *pipefd_2)
{
	close(pipefd_1[1]);
	close(pipefd_2[0]);
	dup2(pipefd_1[0], STDIN_FILENO);
	close(pipefd_1[0]);
	dup2(pipefd_2[1], STDOUT_FILENO);
	close(pipefd_2[1]);
	if (data->path1 != NULL)
	{
		execve(data->path1, data->argv1, data->envp);
		perror("execve");
		free(data);
		exit(EXIT_FAILURE);
	}
}

int	read_infile(t_data *data, int *pipefd_1, int *pipefd_2)
{
	int		fd;
	int		fd_2;
	int		b;
	char	buff[1024];

	b = 1;
	fd = open(data->i, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("open", 1), -1);
	fd_2 = open (data->o, O_WRONLY);
	if (fd_2 < 0)
		return (close(fd), ft_putendl_fd("open", 1), -1);
	while (b != 0)
	{
		b = read(fd, buff, 1023);
		if (b < 0)
			return (ft_putendl_fd("read", 1), -1);
		if (data->path1 != NULL)
			write(pipefd_1[1], buff, b);
		else if (data->path2 != NULL)
			write(pipefd_2[1], buff, b);
		else
			write(fd_2, buff, b);
	}
	return (close(fd), close(fd_2), 0);
}

void	parent_process(int *pipefd_1, int *pipefd_2, t_data *data)
{
	if (read_infile(data, pipefd_1, pipefd_2) != 0)
	{
		close(pipefd_1[0]);
		close(pipefd_2[0]);
		close(pipefd_2[1]);
		close(pipefd_1[1]);
		return ;
	}
	close(pipefd_1[0]);
	close(pipefd_2[0]);
	close(pipefd_2[1]);
	close(pipefd_1[1]);
	waitpid(data->cpid1, NULL, 0);
	waitpid(data->cpid2, NULL, 0);
}

int	create_processes(t_data *data)
{
	int		pipefd_1[2];
	int		pipefd_2[2];

	if (pipe(pipefd_1) == -1 || pipe(pipefd_2) == -1)
		return (ft_printf("Error\n"), -1);
	data->cpid1 = fork();
	if (data->cpid1 == -1)
		return (-1);
	if (data->cpid1 == 0)
		first_child_process(data, pipefd_1, pipefd_2);
	else
	{
		data->cpid2 = fork();
		if (data->cpid2 == -1)
			return (-1);
		if (data->cpid2 == 0)
			second_child_process(data, pipefd_1, pipefd_2);
		else
			parent_process(pipefd_1, pipefd_2, data);
	}
	return (0);
}
