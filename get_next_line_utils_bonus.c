/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:11:36 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/18 11:11:36 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (src == 0 || size == 0)
		return ;
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	free(s1);
	return (str);
}

t_node	*get_node(int fd, t_node **list)
{
	t_node	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			break ;
		node = node->next;
	}
	if (node == NULL)
	{
		node = malloc(sizeof(t_node));
		if (node == NULL)
			return (NULL);
		node->fd = fd;
		node->str = NULL;
		node->next = *list;
		*list = node;
	}
	return (node);
}

void	free_list(int should_free, int fd, t_node **list)
{
	t_node	*node;
	t_node	*last;

	if (!should_free)
		return ;
	if ((*list)->fd == fd)
	{
		last = (*list)->next;
		free(*list);
		*list = last;
		return ;
	}
	node = *list;
	while (node)
	{
		if (node->fd == fd)
			break ;
		last = node;
		node = node->next;
	}
	last->next = node->next;
	free(node);
}
