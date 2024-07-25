/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:38:47 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 15:57:08 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_input(t_data *data)
{
	char	*input;
	char	*prompt;

	prompt = get_env_value("USER", data->envp);
	if (prompt == NULL)
		return (NULL);
	prompt = ft_strjoin(prompt, "% ");
	if (prompt == NULL)
		return (NULL);
	input = readline(prompt);
	free(prompt);
	if (input == NULL)
		return (NULL);
	if (input && *input)
		add_history(input);
	return (input);
}

void	set_input_output(t_data *data)
{
	size_t	i;

	ft_memset(data->infile, '\0', sizeof(data->infile));
	ft_memset(data->outfile, '\0', sizeof(data->outfile));
	i = 0;
	while ((data->split_input)[i])
	{
		if ((data->split_input)[i][0] == '<')
		{
			if ((data->split_input)[i][1] != '\0')
				ft_strlcpy(data->infile, &(data->split_input)[i][1], sizeof(data->infile));
			else if ((data->split_input)[i + 1] != NULL)
			{
				ft_strlcpy(data->infile, (data->split_input)[i + 1], sizeof(data->infile));
				i++;
			}
		}
		else if ((data->split_input)[i][0] == '>')
		{
			if ((data->split_input)[i][1] != '\0')
				ft_strlcpy(data->outfile, &(data->split_input)[i][1], sizeof(data->infile));
			else if ((data->split_input)[i + 1] != NULL)
			{
				ft_strlcpy(data->outfile, (data->split_input)[i + 1], sizeof(data->infile));
				i++;
			}
		}
		i++;
	}
}
