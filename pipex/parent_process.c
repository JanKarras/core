/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:33:27 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:12:43 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_file(t_data *data, int b, char *buff)
{
	while (b != 0)
	{
		b = read(*(data->fd_in), buff, 1023);
		if (b < 0)
			return (ft_putendl_fd("Read Error", 1), -1);
		if ((data->argv1)[0] != NULL)
			write((data->pipefd_1)[1], buff, b);
		else if ((data->argv2)[0] != NULL)
			write((data->pipefd_2)[1], buff, b);
		else
			write(*(data->fd_out), buff, b);
	}
	return (free(buff), 0);
}

int	parent_process(t_data *data)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 1024);
	if (buff == NULL)
		return (-1);
	if (read_file(data, 1, buff) != 0)
	{
		return (-1);
	}
	close((data->pipefd_1)[0]);
	close((data->pipefd_1)[1]);
	close((data->pipefd_2)[0]);
	close((data->pipefd_2)[1]);
	waitpid(*(data->cpid1), NULL, 0);
	waitpid(*(data->cpid2), NULL, 0);
	return (0);
}
