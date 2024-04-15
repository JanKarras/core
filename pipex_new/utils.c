/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:51:53 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/15 14:35:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int key, int fd)
{
	ft_putendl_fd("error", 2);
	if (key == 1)
		close(fd);
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd_name, char **envp, char **paths, char *path)
{
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		part_path = ft_strjoin(paths[i], "/");
		if (part_path == NULL)
			return (free_char_arr(paths), NULL);
		path = ft_strjoin(part_path, cmd_name);
		if (path == NULL)
			return (free_char_arr(paths), free(part_path), NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_char_arr(paths);
	return (NULL);
}

void	execute(char *argv, char **envp, int key, int fd)
{
	char	**cmds;
	char	*path;

	if (ft_strlen(argv) == 0)
		exit(EXIT_SUCCESS);
	cmds = ft_split(argv, ' ');
	if (cmds == NULL)
		error(key, fd);
	path = find_path(cmds[0], envp, NULL, NULL);
	if (path == NULL)
	{
		free_char_arr(cmds);
		error(key, fd);
	}
	if (execve(path, cmds, envp) == -1)
		error(key, fd);
}
