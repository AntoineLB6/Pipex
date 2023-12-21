/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:33 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/21 08:58:28 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_words(char **str)
{
	int	size;

	size = 0;
	while (str[size] != NULL)
	{
		free(str[size]);
		size++;
	}
	free(str);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**splitted_cmds;
	char	*path;

	splitted_cmds = ft_split(cmd, ' ');
	path = cmd_path(splitted_cmds[0], envp);
	if (!path)
	{
		free_words(splitted_cmds);
		write_err("no valid adress");
	}
	if (execve(path, splitted_cmds, envp) == -1)
	{
		free_words(splitted_cmds);
		write_err("execve");
	}
}

void	ft_here_doc(char *limiter, int *p_fd)
{
	char	*buff;

	close(p_fd[0]);
	while (1)
	{
		buff = get_next_line(0);
		if (ft_strncmp(buff, limiter, ft_strlen(limiter)) == 0)
		{
			free(buff);
			exit(0);
		}
		ft_putstr_fd(buff, p_fd[1]);
		free(buff);
	}
}

void	ft_pipe(char *cmd, char **envp, int here_doc)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		write_err("pipe");
	pid = fork();
	if (pid == -1)
		write_err("fork");
	if (pid == 0 && !here_doc)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		execute_cmd(cmd, envp);
	}
	else if (pid == 0 && here_doc)
		ft_here_doc(cmd, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	in_fd;
	int	out_fd;

	if (argc < 5)
		write_err("5 args min required");
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			write_err("6 args min required for here_doc");
		i++;
		out_fd = fd_open(1, argv[argc - 1]);
		ft_pipe(argv[2], envp, 1);
	}
	else
	{
		in_fd = fd_open(0, argv[1]);
		out_fd = fd_open(2, argv[argc - 1]);
		dup2(in_fd, 0);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp, 0);
	dup2(out_fd, 1);
	execute_cmd(argv[argc - 2], envp);
}
