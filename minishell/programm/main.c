/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:57:21 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 16:11:38 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_cmd(t_data *data)
{
	data->split_input = split_input(data->input);
	set_input_output(data);
	if (ft_strchr(data->input, '|'))
		parse_multi_cmd(data);
	else
		parse_single_cmd(data);
	//exit_programm(data);
	return (0);
}

int	run(char **envp)
{
	t_data	*data;

	if (envp == NULL)
		return (ft_putendl_fd("Copy envp error", 1), 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_putendl_fd("Malloc data err", 1), 1);
	data->envp = envp;
	while (1)
	{
		data->input = get_input(data);
		if (data->input == NULL)
			break ;
		parse_cmd(data);
		free(data->input);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*command;

	if (argc != 1)
		return (ft_printf("No ARGs allwoed\n"), 1);
	return (run(copy_envp(envp)));
}
