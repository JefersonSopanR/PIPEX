/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 16:00:00 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 16:00:00 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	if (ac < 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		setup_here_doc(av, ac);
		i = 3;
	}
	else
	{
		setup_input_file(av, ac);
		i = 2;
	}
	while (i < ac - 2)
	{
		pipe_trough(av[i], envp);
		i++;
	}
	execute_command(av[ac - 2], envp);
	return (0);
}
