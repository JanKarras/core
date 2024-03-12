/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:20:53 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/12 13:25:02 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child_process(t_data *data, int *pipefd)
{
	int	fd;

	fd = open(data->o, O_WRONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(fd, STDOUT_FILENO);
	execve(data->path2, data->argv2, data->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	first_child_process(t_data *data, int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execve(data->path1, data->argv1, data->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(int *pipefd, pid_t cpid1, pid_t cpid2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}

int	do_stuff(t_data *data)
{
	int		pipefd[2];
	pid_t	cpid1;
	pid_t	cpid2;

	if (pipe(pipefd) == -1)
		return (ft_printf("Error\n"), -1);
	cpid1 = fork();
	if (cpid1 == -1)
		return (-1);
	if (cpid1 == 0)
		first_child_process(data, pipefd);
	else
	{
		cpid2 = fork();
		if (cpid2 == -1)
			return (-1);
		if (cpid2 == 0)
			second_child_process(data, pipefd);
		else
			parent_process(pipefd, cpid1, cpid2);
	}
	return (0);
}

int	main(int argc, char **agrv)
{
	t_data	*data;

	if (argc != 5)
		return (perror("Wrong arg nb"), -1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (init(agrv, data) != 0)
		return (perror("Malloc Error"), -1);
	if (do_stuff(data) != 0)
		return (free_data(data), -1);
	free_data(data);
	return (0);
}

//< infile.txt wc -l | cat > outfile.txt
