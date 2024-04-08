/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:04:00 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/12 13:18:53 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_data *data)
{
	if (data->f)
		free(data->f);
	if (data->i)
		free(data->i);
	if (data->o)
		free(data->o);
	if (data->s)
		free(data->s);
	if (data->argv1)
		free_char_arr(data->argv1);
	if (data->argv1)
		free_char_arr(data->argv2);
	if (data->envp)
		free_char_arr(data->envp);
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	free(data);
}
