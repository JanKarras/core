/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:35:08 by rmatthes          #+#    #+#             */
/*   Updated: 2024/02/06 18:03:07 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *text, int fd)
{
	int		b;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	b = 1;
	while (ft_strchr_bonus(buffer, '\n') == NULL && b != 0)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[b] = '\0';
		text = ft_join_bonus(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*extract_line(char *text)
{
	size_t	i;
	char	*line;

	i = 0;
	if (*text != '\0')
	{
		while (text[i] != '\0' && text[i] != '\n')
			i++;
		line = (char *)malloc(sizeof(char) * (i + 2));
		if (line == NULL)
			return (NULL);
		line = ft_strcpy_endl(line, text);
		return (line);
	}
	return (NULL);
}

char	*cut_the_line(char *text)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*cutted_text;

	i = 0;
	j = 0;
	len = ft_strlen_bonus(text);
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	cutted_text = (char *)malloc(sizeof(char *) * (len - i + 1));
	if (cutted_text == NULL)
		return (NULL);
	i++;
	while (text[i] != '\0')
		cutted_text[j++] = text[i++];
	cutted_text[j] = '\0';
	free(text);
	return (cutted_text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_file(text, fd);
	if (!text)
		return (NULL);
	line = extract_line(text);
	text = cut_the_line(text);
	return (line);
}
