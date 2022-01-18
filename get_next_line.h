/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:22:52 by iait-bel          #+#    #+#             */
/*   Updated: 2021/11/24 18:22:52 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>

char	*get_next_line(int fd);
void	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*get_line(char *s, int size);

#endif
