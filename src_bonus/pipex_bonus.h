/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 16:05:59 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 16:05:59 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
char	*create_path(char *path, char *cmd);
void	free_strings(char **strings);
void	execute_command(char *command, char **envp);
void	child_get_input(char *delimeter, int pfd[]);
void	child_executor(char *command, int pfd[], char **envp);
void	pipe_trough(char *command, char **envp);
void	setup_here_doc(char **av, int ac);
void	setup_input_file(char **av, int ac);
int		main(int ac, char **av, char **envp);
void	get_here_doc(char *delimeter);

#endif