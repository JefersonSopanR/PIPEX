/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 20:06:23 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 20:06:23 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	setup_here_doc(char **av, int ac)
{
	int	outfile_fd;

	if (ac < 6)
	{
		ft_putstr_fd("Invalid number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	get_here_doc(av[2]);
	outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (outfile_fd == -1)
	{
		perror("outfile");
		exit(EXIT_FAILURE);
	}
	dup2(outfile_fd, 1);
	close(outfile_fd);
}

void	setup_input_file(char **av, int ac)
{
	int	outfile_fd;
	int	infile_fd;

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd == -1)
	{
		perror("Infile: ");
		exit(EXIT_FAILURE);
	}
	dup2(infile_fd, 0);
	close(infile_fd);
	outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
	{
		perror("outfile");
		exit(EXIT_FAILURE);
	}
	dup2(outfile_fd, 1);
	close(outfile_fd);
}
