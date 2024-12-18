/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:33:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/18 11:30:51 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* check_args:
*	Check if is it possible to execute the command
*/
int	check_args(char *arg, char **envp, int *error)
{
	char	**args;
	int		fd_try;

	args = build_arg(arg, envp);
	if (!args)
	{
		ft_putstr_fd("Command not found\n", 2);
		*error = 127;
		return (0);
	}
	fd_try = open(args[0], __O_DIRECTORY);
	free_split(args);
	if (fd_try > 0)
	{
		if (get_path(envp))
			ft_putstr_fd("Command not found\n", 2);
		else
			ft_putstr_fd("You gave a directory\n", 2);
		close(fd_try);
		return (0);
	}
	return (1);
}

/* setup_first_loop:
*	Useful for first call of execute function
*/
int	setup_first_loop(int fds[3], char *arg, char **envp, int *error)
{
	int		p[2];

	*error = 0;
	if (!check_args(arg, envp, error))
	{
		close(fds[0]);
		fds[0] = -1;
		return (0);
	}
	if (fds[0] == -1)
		default_pipe(fds);
	if (fds[0] == -1)
		return (0);
	if (pipe(p) < 0)
	{
		close(fds[0]);
		perror("Failed to create pipe");
		*error = 1;
		return (0);
	}
	fds[1] = p[1];
	fds[2] = p[0];
	return (1);
}

/* setup_end_loop:
*	Useful for last call of execute function
*/
int	setup_end_loop(int fds[3], char **args, char **envp, int *error)
{
	*error = 0;
	fds[1] = open(args[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fds[1] || access(args[1], W_OK) != 0)
	{
		perror("pipex");
		*error = 1;
		return (0);
	}
	if (!check_args(args[0], envp, error))
	{
		close(fds[1]);
		return (0);
	}
	if (access(args[1], F_OK) == 0 && access(args[1], W_OK) != 0)
	{
		close(fds[1]);
		*error = 1;
		return (0);
	}
	fds[0] = fds[2];
	fds[2] = -1;
	if (fds[0] < 0)
		default_pipe(fds);
	return (fds[0] > 0);
}
