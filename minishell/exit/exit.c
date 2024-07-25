/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:46:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 16:13:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_programm(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->input)
		free(data->input);
	if (data->envp)
		free_char_arr(data->envp);
	while (i < data->cmd_nb)
	{
		if ((data->cmds)[i].path)
			free((data->cmds)[i].path);
		if ((data->cmds)[i].argv)
			free_char_arr((data->cmds)[i].argv);
		i++;
	}
	if (data->split_input)
		free_char_arr(data->split_input);
	free(data);
	exit(0);
}
