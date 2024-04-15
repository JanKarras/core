/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/09 19:13:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5)
		return (ft_putendl_fd("Wrong arg nb", 1), -1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_putendl_fd("Malloc Error", 1), -1);
	if (init(data, argv) != 0)
		return (ft_putendl_fd("Error", 1), -1);
	if (check_infile(data) != 0)
		data->infile_error = true;
	processes(data);
}

//< infile.txt ls -l | wc -l > outfile
