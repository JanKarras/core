/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:20:53 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/14 13:17:14 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child_process(t_data *data, int *pipefd_1, int *pipefd_2)
{
	close(pipefd_1[0]);
    close(pipefd_1[1]);
    close(pipefd_2[1]);
	int fd = open(data->o, O_WRONLY);
	dup2(pipefd_2[0], STDIN_FILENO);
	close(pipefd_2[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execve(data->path2, data->argv2, data->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	first_child_process(t_data *data, int *pipefd_1, int *pipefd_2)
{
	close(pipefd_1[1]);
	close(pipefd_2[0]);
	dup2(pipefd_1[0], STDIN_FILENO);
	close(pipefd_1[0]);
	dup2(pipefd_2[1], STDOUT_FILENO);
	close(pipefd_2[1]);
	execve(data->path1, data->argv1, data->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	read_infile(t_data *data, int *pipefd_1)
{
	int		fd;
	int		b;
	char	*line;

	b = 1;
	fd = open(data->i, O_RDONLY);
	line = (char *)malloc(1);
	if (line == NULL)
		return (-1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		write(pipefd_1[1], line, ft_strlen(line));
	}
	return(0);
}

void	parent_process(int *pipefd_1, int *pipefd_2, pid_t cpid1, pid_t cpid2, t_data *data)
{
	read_infile(data, pipefd_1);
	close(pipefd_1[0]);
	close(pipefd_1[1]);
	close(pipefd_2[0]);
	close(pipefd_2[1]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
}

int	do_stuff(t_data *data)
{
	int		pipefd_1[2];
	int		pipefd_2[2];
	pid_t	cpid1;
	pid_t	cpid2;
	if (pipe(pipefd_1) == -1 || pipe(pipefd_2) == -1)
		return (ft_printf("Error\n"), -1);
	cpid1 = fork();
	if (cpid1 == -1)
		return (-1);
	if (cpid1 == 0)
		first_child_process(data, pipefd_1, pipefd_2);
	else
	{
		cpid2 = fork();
		if (cpid2 == -1)
			return (-1);
		if (cpid2 == 0)
			second_child_process(data, pipefd_1, pipefd_2);
		else
			parent_process(pipefd_1, pipefd_2, cpid1, cpid2, data);
	}
	return (0);
}

int	ckeck_files(t_data *data)
{
	if (access(data->i, F_OK))
		return (ft_putendl_fd("Infile does not exist", 1), -1);
	else if (access(data->i, R_OK))
		return (ft_putendl_fd("Infile is not readable", 1), -1);
	else if (access(data->o, F_OK))
		return (ft_putendl_fd("Outfile does not exist", 1), -1);
	else if (access(data->o, W_OK))
		return (ft_putendl_fd("Outfile ist not writeable", 1), -1);
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
	if (ckeck_files(data) != 0)
		return (free_data(data), -1);
	if (do_stuff(data) != 0)
		return (free_data(data), -1);
	free_data(data);
	return (0);
}

//< infile.txt wc -l | cat > outfile.txt
// chmod a-r infile.txt lesebrechtigung nehmen
// chmod a+r infile.txt lesebrechetigung wieder hinzufuegen
// chmod a+w outfile.txt schreiberechtigung hinzufuegen
// chmod a-w outfile.txt schreiberechtigung entfernen
