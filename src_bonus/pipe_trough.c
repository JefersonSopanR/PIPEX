/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_trough.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 17:08:13 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 17:08:13 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_executor(char *command, int pfd[], char **envp)
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	close(pfd[1]);
	execute_command(command, envp);
}

void	pipe_trough(char *command, char **envp)
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
		child_executor(command, pfd, envp);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
}
