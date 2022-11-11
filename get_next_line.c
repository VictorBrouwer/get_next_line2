/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:15:54 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/11 12:28:04 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	// line = ft_calloc(sizeof(char), 1);
	while (find_char(line, '\n') == 0 /*&& line*/)
	{
		if (find_char(buff, '\0') != 0)
		{
			// free (line);
			line = obtain_line(buff, line);
			break ;
		}
		else if (find_char(buff, '\n') == 0)
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read == 0)
				return (NULL);
			if (bytes_read < BUFFER_SIZE)
			{
				// free(line);
				line = obtain_line(buff, line);
				break ;
			}
			buff[bytes_read] = '\0';
		}
		// free (line);
		line = obtain_line(buff, line);
	}
	update(buff);
	return (line);
}

char	*update(char *buff)
{
	int	i;

	if (find_char(buff, '\n') != 0)
	{
		i = find_char(buff, '\n');
		return (ft_memmove(&buff[0], &buff[i], find_char(buff, '\0') - (i - 1)));
	}
	else
	{
		buff[0] = '\0';
		return (NULL);
	}
}

char	*obtain_line(char *buff, char *line)
{
	char	*result;
	int		i;
	int		j;

	if (find_char(buff, '\n') != 0)
	{
		result = malloc(find_char(buff, '\n'));
		i = 0;
		while (i < find_char(buff, '\n'))
		{
			result[i] = buff[i];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	else
	{
		i = 0;
		result = malloc(i + find_char(buff, '\0'));
		j = 0;
		while (j < find_char(line, '\0'))
		{
			result[j] = line[j];
			j++;
		}
		while (i < find_char(buff, '\0'))
		{
			result[j] = buff[i];
			j++;
			i++;
		}
		result[j] = '\0';
		return (result);
	}
}

int	find_char(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
		while (s[i])
			i++;
	return (i);
}

#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("tekst.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		printf("\nline: %s", s);
		s = get_next_line(fd);
	}
	printf("\nline: %s", s);
	free(s);
	close(fd);
	return (0);
}