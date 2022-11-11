/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:18:19 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/10 13:15:51 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*obtain_line(char *buff, char *line);
int		find_char(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*update(char *buff);

#endif // GET_NEXT_LINE