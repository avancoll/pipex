/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:51:41 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/11 14:52:46 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //close read write access dup dup2 execve fork pipe unlink
# include <fcntl.h> //open
# include <stdlib.h> //malloc free
# include <sys/wait.h> //wait waitpid

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		exec(char *argv, char **env);
size_t	ft_strlen(const char *s);

#endif