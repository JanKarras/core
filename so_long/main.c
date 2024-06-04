/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:34:22 by jkarras           #+#    #+#             */
/*   Updated: 2024/05/22 16:43:40 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*text;

	if (argc != 2)
		return (ft_putendl_fd("Error\nWrong ARG number", 1), -1);
	if (check_param(argv[1]) != 0)
		return (ft_putendl_fd("Error\nNot an .ber file", 1), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nCan't find file", 1), -1);
	text = read_map(fd);
	if (text == NULL)
		return (ft_putendl_fd("Error\nMalloc Error", 1), -1);
	close(fd);
	if (check_text(text) != 0)
		return (free(text), ft_putendl_fd("Error\nNot a Map", 1), -1);
	argv = ft_split(text, '\n');
	if (argv == NULL)
		return (free(text), ft_putendl_fd("Error\nMalloc Error", 1), -1);
	if (check_map(argv) != 0)
		return (-1);
	if (start_game(argv) != 0)
		return (free_argv(argv), ft_putendl_fd("Error", 1), -1);
	free_argv(argv);
	return (0);
}

//valgrind --leak-check=full ./push_swap "4 2 1"
//lldb ./checker '1 2 3'
//r
