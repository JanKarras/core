/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:59:14 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:36:06 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(t_data *data)
{
	if (access(data->i, F_OK))
		return (ft_putendl_fd("Infile does not exist", 1), -1);
	if (access(data->i, R_OK))
		return (ft_putendl_fd("Infile is not readable", 1), -1);
	else
	{
		*(data->fd_in) = open(data->i, O_RDONLY);
		if (data->fd_in < 0)
			return (ft_putendl_fd("Open infile error", 1), -1);
	}
	if (access(data->o, F_OK))
		return (ft_putendl_fd("Outfile does not exist", 1), -1);
	if (access(data->o, W_OK))
		return (ft_putendl_fd("Outfile ist not writeable", 1), -1);
	else
	{
		*(data->fd_out) = open(data->o, O_WRONLY | O_TRUNC);
		if (data->fd_out < 0)
		{
			close(*(data->fd_in));
			return (ft_putendl_fd("Open outfile error", 1), -1);
		}
	}
	return (0);
}
