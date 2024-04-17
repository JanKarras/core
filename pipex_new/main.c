/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:38 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/17 14:14:45 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0777);
	if (fd_infile < 0)
		error();
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd_infile, STDIN_FILENO);
	close(pipe_fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
		error();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	cpid1;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error();
		cpid1 = fork();
		if (cpid1 == -1)
			error();
		if (cpid1 == 0)
			child_process(argv, envp, pipe_fd);
		waitpid(cpid1, NULL, 0);
		parent_process(argv, envp, pipe_fd);
	}
	else
	{
		ft_printf("Bad number of args!\n.pipex <file1> <cmd1> <cmd2> <file2>");
	}
	return (0);
}
//0 reading pipe
//1 writing pipe
//valgrind --leak-check=full --trace-children=yes
//./piepx infile cat "wc -l" outfile
