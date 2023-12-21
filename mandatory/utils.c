/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:10:22 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/21 09:07:24 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fd_open(int nb, char *link)
{
	int	fd;

	if (nb == 0 && access(link, F_OK | R_OK) != 0)
		write_err("right access");
	if (nb == 0)
		fd = open(link, O_RDONLY);
	else if (nb == 1)
		fd = open(link, O_WRONLY | O_CREAT | O_APPEND, 00777);
	else
		fd = open(link, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (fd < 0)
		write_err("open");
	return (fd);
}

void	write_err(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

char	**get_paths(char **env)
{
	char	**paths;

	while (ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	*env += 5;
	paths = ft_split(*env, ':');
	return (paths);
}

char	*cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	paths = get_paths(envp);
	while (paths[i])
	{
		cmd_path = ft_strjoin1(paths[i], "/");
		cmd_path = ft_strjoin1(cmd_path, cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			i++;
			while (paths[i++])
				free(paths[i]);
			free(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(paths);
	return (NULL);
}
