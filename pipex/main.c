/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 16:37:23 by jkarras          ###   ########.fr       */
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
		return(-1);
	if (check_access(data) != 0)
		return(ft_free_data(data), -1);
	if (create_processes(data) != 0)
		return (ft_free_data(data), -1);
	ft_free_data(data);
	return (0);
}
