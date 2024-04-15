/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:38 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_data_help(t_data *data)
{
	if (data->argv1)
		free_char_arr(data->argv1);
	if (data->argv2)
		free_char_arr(data->argv2);
	if (data->envp)
		free_char_arr(data->envp);
	if (data->cpid1)
		free(data->cpid1);
	free(data);
}

void	ft_free_data(t_data *data)
{
	if (data->i)
		free(data->i);
	if (data->o)
		free(data->o);
	if (data->f)
		free(data->f);
	if (data->s)
		free(data->s);
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	if (data->pipefd_1)
		free(data->pipefd_1);
	if (data->pipefd_2)
		free(data->pipefd_2);
	ft_free_data_help(data);
}
