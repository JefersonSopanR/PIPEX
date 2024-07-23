/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_here_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 18:52:41 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 18:52:41 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_get_input(char *delimeter, int pfd[])
{
	char	*line;

	close(pfd[0]);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (ft_strncmp(line, delimeter, ft_strlen(delimeter)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(pfd[1], line, ft_strlen(line));
		free(line);
	}
}

void	get_here_doc(char *delimeter)
{
	int		pfd[2];
	pid_t	pid;

	if (pipe(pfd) == -1)
	{
		perror("Error in pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error when forking");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_get_input(delimeter, pfd);
	else
	{
		wait(NULL);
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
}
