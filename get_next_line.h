/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhakim <hhakim>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:43:57 by hhakim            #+#    #+#             */
/*   Updated: 2023/02/24 17:57:59 by hhakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif*/

char	*get_next_line(int fd);
char	*ft_read_lines(int fd, char *current_lines);
char	*ft_read_next_lines(char *current_lines);
char	*ft_line_dilemeter(char *current_lines);
char	*ft_strjoin(char *str1, char *str2);
int		ft_isnewline(char *str);
size_t	ft_strlen(char *str);
char	*ft_read_save(char *temp_line);

#endif