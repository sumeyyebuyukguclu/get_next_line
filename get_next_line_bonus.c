/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuyukgu <sbuyukgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:56:14 by sbuyukgu          #+#    #+#             */
/*   Updated: 2022/07/27 16:23:00 by sbuyukgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*dizi;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dizi = malloc(sizeof(char) * (i + 2));
	if (!dizi)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		dizi[i] = str[i];
	if (str[i] == '\n')
	{
		dizi[i] = str[i];
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}

char	*shift_endline(char *str)
{
	int		i;
	int		j;
	char	*dizi;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	dizi = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dizi)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dizi[j++] = str[i++];
	dizi[j] = '\0';
	free(str);
	return (dizi);
}

char	*read_from_file(int fd, char *str)
{
	char	*buff;
	int		rc;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 1;
	while (check_newline(str) && rc != 0)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
			return (ft_free(buff));
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = read_from_file(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_get_line(str[fd]);
	str[fd] = shift_endline(str[fd]);
	return (line);
}


#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    char *buff;
    char *b;
    b = "buse\nero\n";
    fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    write(fd,b,5);
    //close(fd);
    buff = get_next_line(fd);
    printf("%s", buff);
    // printf("%d",fd);
    // printf("%s",get_next_line(fd));
}
	

