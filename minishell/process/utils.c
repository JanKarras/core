/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:02:13 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 16:02:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			return (free_char_arr(paths), path);
		free(path);
		i++;
	}
	free_char_arr(paths);
	return (NULL);
}
