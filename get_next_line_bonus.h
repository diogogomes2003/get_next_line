/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:21:19 by dduarte-          #+#    #+#             */
/*   Updated: 2023/05/09 09:29:41 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1234
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_and_join(int fd, char *temp);
char	*ft_strjoin(char *temp, char *buffer);
char	*ft_get_line(char *temp);
char	*ft_new_temp(char *temp);
char	*ft_strchr(char *s, int line_break);
size_t	ft_strlen(char *s);

#endif