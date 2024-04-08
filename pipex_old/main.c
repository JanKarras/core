/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:20:53 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:30:42 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (create_processes(data) != 0)
		return (free_data(data), -1);
	close(data->fd_in);
	close(data->)
	free_data(data);
	return (0);
}

//< infile.txt wc -l | cat > outfile.txt
//< infile.txt cat | wc -l > outfile.txt
//< infile.txt ls -l | ls > outfile.txt
//< infile.txt ls | cat > outfile.txt

// chmod a-r infile.txt lesebrechtigung nehmen
// chmod a+r infile.txt lesebrechetigung wieder hinzufuegen
// chmod a+w outfile.txt schreiberechtigung hinzufuegen
// chmod a-w outfile.txt schreiberechtigung entfernen
// valgrind --leak-check=full ./push_swap "4 2 1"
