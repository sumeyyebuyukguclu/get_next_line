/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuyukgu <sbuyukgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:56:03 by sbuyukgu          #+#    #+#             */
/*   Updated: 2022/07/27 13:18:39 by sbuyukgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_get_line(char *str);
char	*get_next_line_bonus(int fd);
char	*read_from_file(int fd, char *str);
char	*shift_endline(char *str);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char	*dst, const char *src, size_t	dstsize);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_free(void *str);
int		check_newline(char *ptr);

#endif