/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:33:21 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/17 16:48:37 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
