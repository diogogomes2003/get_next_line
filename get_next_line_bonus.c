/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:20:49 by dduarte-          #+#    #+#             */
/*   Updated: 2023/05/09 10:04:32 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_and_join(int fd, char *temp)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(temp, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	temp[fd] = ft_read_and_join(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = ft_get_line(temp[fd]);
	temp[fd] = ft_new_temp(temp[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	char		*line;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s \n",i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s\n", i,line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s\n", i,line);
// 		free(line);
// 		i++;
// 	}
//     close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }