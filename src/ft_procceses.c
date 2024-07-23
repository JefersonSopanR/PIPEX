/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procceses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-10 00:10:23 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-10 00:10:23 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **av, int pfd[], char **envp)
{
	int	infile_fd;

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd == -1)
	{
		perror("Infile: ");
		exit(EXIT_FAILURE);
	}
	close(pfd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close(infile_fd);
	close(pfd[1]);
	execute_command(av[2], envp);
}

void	ft_parent_process(char **av, int pfd[], char **envp)
{
	int	outfile_fd;

	outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		perror("outfile");
		exit(EXIT_FAILURE);
	}
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(pfd[0]);
	execute_command(av[3], envp);
}
