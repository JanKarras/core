/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:35:53 by rmatthes          #+#    #+#             */
/*   Updated: 2023/12/13 15:34:13 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(char *text, int fd)
{
	int		b;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	b = 1;
	while (ft_strchr(buffer, '\n') == NULL && b != 0)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[b] = '\0';
		text = ft_join(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*extract_line(char *text)
{
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
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
	len = ft_strlen(text);
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
	static char	*array[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	array[fd] = read_file(array[fd], fd);
	if (!array[fd])
		return (NULL);
	line = extract_line(array[fd]);
	array[fd] = cut_the_line(array[fd]);
	return (line);
}
