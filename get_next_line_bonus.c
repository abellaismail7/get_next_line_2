/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:11:11 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/18 11:11:11 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	get_index(char *s, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			*count += i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *content, int *count)
{
	int		n;
	char	*buf;

	if (content && get_index(content, count))
		return (content);
	if (content)
		*count = ft_strlen(content);
	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1 || n == 0)
			break ;
		buf[n] = 0;
		content = ft_strjoin(content, buf);
		if (content == NULL || get_index(buf, count))
			break ;
		*count += n;
	}
	free(buf);
	return (content);
}

char	*get_line(char *s, int size)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char *) * (size + 1));
	if (line == NULL)
		return (NULL);
	while (s[i] && i < size)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*content;
	char			*line;
	int				line_index;
	t_node			*node;
	static t_node	*list;

	line_index = 0;
	node = get_node(fd, &list);
	if (node == NULL)
		return (NULL);
	content = read_line(fd, node->str, &line_index);
	if (content == NULL || line_index == 0)
	{
		free_list(1, fd, &list);
		free(content);
		return (NULL);
	}
	line = get_line(content, line_index);
	node->str = get_line(content + line_index, ft_strlen(content + line_index));
	free(content);
	free_list(line == NULL, fd, &list);
	return (line);
}
