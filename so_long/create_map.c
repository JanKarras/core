/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:54:22 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/05 17:14:13 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_text(char *text)
{
	int	i;

	if (ft_strlen(text) < 17)
		return (-1);
	if (text[0] == '\n')
		return (-1);
	i = 0;
	while (text[i] != '\0' && text[i + 1])
	{
		if (text[i] == '\n' && text[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	check_param(char *file_name)
{
	int	len;

	len = my_ft_strlen(file_name);
	len = len - 5;
	if (file_name[len] == '.')
		return (-1);
	len++;
	if (file_name[len] == 'b')
		return (-1);
	len++;
	if (file_name[len] == 'e')
		return (-1);
	len++;
	if (file_name[len] == 'r')
		return (-1);
	return (0);
}

char	*read_map(int fd)
{
	int		b;
	char	*buffer;
	char	*text;

	buffer = (char *)malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	text = (char *)malloc(sizeof(char) * 1);
	if (text == NULL)
		return (free(buffer), NULL);
	text[0] = '\0';
	b = 1;
	while (b != 0)
	{
		b = read(fd, buffer, 1023);
		if (b == -1)
			return (free(buffer), free(text), NULL);
		buffer[b] = '\0';
		text = ft_strjoin(text, buffer);
		if (text == NULL)
			return (free(buffer), NULL);
	}
	return (free(buffer), text);
}
