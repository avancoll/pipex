/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:37 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/12 15:07:14 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!haystack || !needle) && len == 0)
		return (NULL);
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && needle[j] == haystack[i + j] && (i + j) < len)
				j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2 || !s1[0] || !s2[0])
	{
		free(s1);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

int	error_handler(int errnum)
{
	if (errnum == ARGC_ERROR)
		write(2, "Error: Wrong number of arguments\n", 34);
	else if (errnum == PIPE_ERROR)
		write(2, "Error: Pipe could not work properly\n", 37);
	else if (errnum == FORK_ERROR)
		write(2, "Error: Fork could not work properly\n", 37);
	else if (errnum == MALLOC_ERROR)
		write(2, "Error: Malloc could not work properly\n", 39);
	else if (errnum == INPUTFILE_ERROR)
		write(2, "Error: Open could not work properly with the input file\n", 57);
	else if (errnum == OUTPUTFILE_ERROR)
		write(2, "Error: Open could not work properly with the output file\n", 58);
	else if (errnum == CMD_ERROR)
		write(2, "Error: Command not found\n", 26);
	return (1);
}
