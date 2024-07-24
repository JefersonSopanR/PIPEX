/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 17:23:36 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-11 17:23:36 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*create_path(char *path, char *cmd)
{
	char	*add_slash;
	char	*cmd_path;

	add_slash = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(add_slash, cmd);
	free(add_slash);
	return (cmd_path);
}

char	*get_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**all_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	all_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_path[i])
	{
		cmd_path = create_path(all_path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_strings(all_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_strings(all_path);
	return (NULL);
}

void	execute_command(char *command, char **envp)
{
	char	**split_cmd;
	char	*path_cmd;

	if (command == NULL || command[0] == '\0')
		return ;
	if (ft_strchr(command, '\''))
		split_cmd = ft_handle_quotes(command);
	else
		split_cmd = ft_split(command, ' ');
	path_cmd = get_path(split_cmd[0], envp);
	if (execve(path_cmd, split_cmd, envp) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, split_cmd[0], ft_strlen(split_cmd[0]));
		write(2, "\n", 1);
		free_strings(split_cmd);
		exit(EXIT_FAILURE);
	}
}
