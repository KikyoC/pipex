/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:33:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/16 13:59:53 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* check_args:
*	Check if is it possible to execute the command
*/
int	check_args(char *arg, char **envp, int *error)
{
	char	**args;

	args = build_arg(arg, envp);
	if (!args)
	{
		*error = 127;
		return (0);
	}
	free_split(args);
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

/* setup_middle_loop:
*	Useful for all call of execute function
*	except first and last
*/
int	setup_middle_loop(int fds[3], char *arg, char **envp, int *error)
{
	int		p[2];

	fds[0] = fds[2];
	if (!check_args(arg, envp, error))
		return (-1);
	if (fds[0] == -1)
		default_pipe(fds);
	if (fds[0] == -1)
		return (0);
	if (pipe(p) < 0)
	{
		perror("Failed to create pipe");
		*error = 1;
		return (0);
	}
	fds[1] = p[1];
	fds[2] = p[0];
	if (fds[0] < 0)
		default_pipe(fds);
	return (fds[0] > 0);
}

/* setup_end_loop:
*	Useful for last call of execute function
*/
int	setup_end_loop(int fds[3], char **args, char **envp, int *error)
{
	*error = 0;
	if (!check_args(args[0], envp, error))
		return (0);
	if (access(args[1], F_OK) == 0 && access(args[1], W_OK) != 0)
	{
		*error = 1;
		return (0);
	}
	fds[0] = fds[2];
	fds[1] = open(args[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fds[1])
	{
		perror("Failed to open outfile");
		*error = 1;
		return (0);
	}
	fds[2] = -1;
	if (fds[0] < 0)
		default_pipe(fds);
	return (fds[0] > 0);
}

/* setup_heredoc_loop:
*	Useful for first call of execute function
*	if it's here_doc
*/
int	setup_heredoc_loop(int fds[3], char **args, char **envp, int *error)
{
	*error = 0;
	fds[1] = open(args[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (!check_args(args[0], envp, error))
		return (0);
	if (access(args[1], F_OK) == 0 && access(args[1], W_OK) != 0)
	{
		*error = 1;
		return (0);
	}
	if (fds[0] == -1)
		default_pipe(fds);
	if (fds[0] == -1)
		return (0);
	fds[0] = fds[2];
	if (!fds[1])
	{
		perror("Failed to open outfile");
		*error = 1;
		return (0);
	}
	fds[2] = -1;
	return (1);
}
