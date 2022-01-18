/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:11:25 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/18 11:11:25 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>

typedef struct s_node
{
	int				fd;
	char			*str;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
void	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*get_line(char *s, int size);
t_node	*get_node(int fd, t_node **list);
void	free_list(int should_free, int fd, t_node **list);

#endif
