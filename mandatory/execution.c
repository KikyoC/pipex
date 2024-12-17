/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:03:45 by tom               #+#    #+#             */
/*   Updated: 2024/12/17 11:20:33 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* execommand:
*	Take 3 fd, the path to the command, arguments and environment as argument
*	Create a child and execute the command.
*	Returns the child's PID
*/
int	execommand(int p[3], char *path, char **argv, char **envp)
{
	int		f;

	f = fork();
	if (f == -1)
	{
		multiple_close(p[0], p[1], p[2]);
		perror("Cannot fork");
		return (-1);
	}
	if (f == 0)
	{
		dup2(p[0], 0);
		dup2(p[1], 1);
		multiple_close(p[0], p[1], p[2]);
		execve(path, argv, envp);
		perror("Pipex execution");
		return (-1);
	}
	multiple_close(p[0], p[1], -1);
	return (f);
}

/* get_command:
*	Take the path splited witht he command name as argument
*	Check if the command is already a valid path or try to find it
*/
char	*get_command(char **path, char *command)
{
	char	*res;
	char	*tmp;

	if (access(command, X_OK) == 0 && access(command, F_OK) == 0)
		return (command);
	tmp = ft_strdup(command);
	if (!tmp)
		return (NULL);
	free(command);
	command = ft_strjoin("/", tmp);
	free(tmp);
	if (!command)
		return (NULL);
	res = ft_strjoin(get_command_path(path, command), command);
	free(command);
	return (res);
}

/* build_arg:
*	Take the complete command and environment as parameter
*	Build the argument for the next execve call
*	Split and change the first element by the right one if needed
*/
char	**build_arg(char *arg, char **envp)
{
	char	**res;
	char	**path;
	char	*command;

	res = ft_split(arg, ' ');
	if (!res)
		return (NULL);
	if (!get_path(envp))
		return (no_env(res));
	path = ft_split(get_path(envp), ':');
	if (!path)
		return (free_split(res));
	command = get_command(path, ft_strdup(res[0]));
	free_split(path);
	if (!command)
		return (free_split(res));
	free(res[0]);
	res[0] = command;
	return (res);
}

/* execute:
*	Take 3 fd, th command, environment variable and pids list as argument
*	Try to build a command, execute it and save the PID returned
*/
int	execute(int fds[3], char *cmd, char **envp, int *pids)
{
	char	**args;
	int		pid;

	args = build_arg(cmd, envp);
	if (args)
		args = arg_fixer(args);
	if (!args)
	{
		free_split(args);
		multiple_close(fds[0], fds[1], fds[2]);
		return (0);
	}
	pid = execommand(fds, args[0], args, envp);
	insert_pid(pids, pid);
	free_split(args);
	return (1);
}
