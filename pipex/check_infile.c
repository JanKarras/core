/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:58:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/11 13:18:04 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(t_data *data)
{
	if (access(data->i, F_OK) == 0)
	{
		if (access(data->i, R_OK) == 0)
			return (0);
		else
			return (ft_printf("%s: Permission denied\n", data->i), -1);
	}
	else
		return (ft_printf("bash : %s: No such file or directory\n", data->i), -1);
	return (0);
}
