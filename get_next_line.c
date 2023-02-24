/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhakim <hhakim>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:12 by hhakim            #+#    #+#             */
/*   Updated: 2023/02/24 18:28:39 by hhakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read and save the line in case '\n' wasn't found
char	*ft_read_save(char *temp_line)
{
	char	*lines;
	int		i;

	i = 0;
	if (!temp_line)
		return (NULL);
	lines = (char *)malloc(sizeof(char) * ft_strlen (temp_line) + 1);
	if (!lines)
		return (NULL);
	while (temp_line [i])
	{
		lines[i] = temp_line[i];
		i++;
	}
	lines[i] = '\0';
	return (lines);
}

//read and the left lines after a '\n'
char	*ft_read_next_lines(char *current_lines)
{
	int		i;
	int		j;
	char	*next_lines;

	i = 0;
	j = 0;
	while (current_lines[i] != '\n')
		i++;
	next_lines = (char *)malloc(ft_strlen(current_lines) - i);
	if (!next_lines)
		return (NULL);
	i++;
	while (current_lines[j])
	{
		next_lines[j] = current_lines[i];
		i++;
		j++;
	}
	next_lines[j] = '\0';
	free(current_lines);
	return (next_lines);
}

//finds 'n' in currentline
//retruns a cpy of the past chars before '\n' *PAST LINE*
char	*ft_line_dilemeter(char *current_lines)
{
	int		i;
	char	*line;

	i = 0;
	if (!current_lines)
		return (NULL);
	while (current_lines[i - 1] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (current_lines[i - 1] != '\n')
	{
		line[i] = current_lines[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

//read and save the line being read inputs fd, and char *
//returns new created str with muliple lines
char	*ft_read_lines(int fd, char *current_lines)
{
	char	*temp_line;
	int		nbyts;

	nbyts = 1;
	temp_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_line)
		return (NULL);
	while (!ft_isnewline(current_lines) && nbyts)
	{
		nbyts = read(fd, temp_line, BUFFER_SIZE);
		if (nbyts == -1)
		{
			free(temp_line);
			return (NULL);
		}
		temp_line[nbyts] = '\0';
		if (!current_lines)
		{
			current_lines = (char *)malloc(sizeof(char) * 1);
			current_lines[0] = '\0';
		}
		current_lines = ft_strjoin(current_lines, temp_line);
	}
	free (temp_line);
	return (current_lines);
}

//read a file through fd(int) and returns a ptr to the begining of the line
//that was read (until end of line \n or EOF)
char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*next_lines;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_lines = ft_read_lines(fd, next_lines);
	if (!next_lines)
		return (NULL);
	if (ft_isnewline(next_lines))
		current_line = ft_line_dilemeter(next_lines);
	else
		current_line = ft_read_save(next_lines);
	if (!ft_isnewline (next_lines))
	{
		free (next_lines);
		next_lines = NULL;
	}
	else
		next_lines = ft_read_next_lines(next_lines);
	return (current_line);
}
