/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:54:15 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/23 15:08:40 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_join(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		s3[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*read_file(char *txt, int fd)
{
	int		b;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	b = 1;
	while (ft_strchr(buffer) && b != 0)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
			return (free(buffer), NULL);
		buffer[b] = '\0';
		txt = str_join(txt, buffer);
		if (txt == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (txt[0] == '\0')
		return (free(txt), NULL);
	return (txt);
}

char	*extract_line(char *txt)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (txt[j] != '\n' && txt[j] != '\0')
		j++;
	if (txt[j] == '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		line[i] = txt[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*cut_the_line(char *txt)
{
	char	*new_txt;
	int		i;
	int		j;

	i = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	if (txt[i] == '\n')
		i++;
	new_txt = (char *)malloc(sizeof(char) * (ft_strlen(txt) - i + 1));
	if (new_txt == NULL)
		return (NULL);
	j = 0;
	while (i != ft_strlen(txt))
	{
		new_txt[j] = txt[i];
		i++;
		j++;
	}
	new_txt[j] = '\0';
	free(txt);
	return (new_txt);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_file(text, fd);
	if (text == NULL)
		return(free(text), NULL);
	line = extract_line(text);
	if (line == NULL)
		return (free(text), NULL);
	text = cut_the_line(text);
	if (text == NULL)
		return (free(text), NULL);
	return (line);
}

//valgrind --leak-check=full ./push_swap "4 2 1"
