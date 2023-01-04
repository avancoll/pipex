/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:51:41 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/04 14:57:50 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //close read write access dup dup2 execve fork pipe unlink
# include <fcntl.h> //open
# include <stdlib.h> //malloc free
# include <sys/wait.h> //wait waitpid

#endif