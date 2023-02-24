/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhakim <hhakim>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:15 by hhakim            #+#    #+#             */
/*   Updated: 2023/02/24 13:30:04 by hhakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//checks for the char '\n' in str
//returns 1 if found, 0 otherwise
int	ft_isnewline(char *str)
{
	char	c;

	c = (char) '\n';
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

//return the length of str
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
			i++;
	return (i);
}

//join two strings into newly created string
char	*ft_strjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) *(ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i + j] = str2[j];
		j++;
	}
	res[i + j] = '\0';
	free(str1);
	return (res);
}
