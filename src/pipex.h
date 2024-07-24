/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-10 00:12:03 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-10 00:12:03 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include "../libft/libft.h"

char	**ft_handle_quotes(char	*command);
char	**ft_handle_dquotes(char *command, int quotes, int i, int j);
char	**ft_handle_quotes(char	*command);
char	*get_path(char *cmd, char **envp);
void	execute_command(char *command, char **envp);
void	ft_child_process(char **av, int pfd[], char **envp);
void	ft_parent_process(char **av, int pfd[], char **envp);
void	free_split(char **split);
char	*create_path(char *path, char *cmd);
int		main(int ac, char **av, char **envp);

#endif