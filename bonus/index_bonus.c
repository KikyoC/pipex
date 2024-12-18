/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:43:01 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/18 12:44:18 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* loop:
*	Take 3 fd, and input of main function
*	Call execute for each argument
*/
int	loop(int fds[3], int argc, char **argv, char **envp)
{
	int		i;
	int		*pids;
	int		error;

	i = 0;
	error = 0;
	pids = create_pids(argc);
	if (!pids)
		return (1);
	if (setup_first_loop(fds, argv[2], envp, &error) > 0)
		execute(fds, argv[2], envp, pids);
	while (++i < argc - 4)
	{
		if (setup_middle_loop(fds, argv[i + 2], envp, &error))
			execute(fds, argv[i + 2], envp, pids);
	}
	if (ft_strncmp(argv[0], "here_doc", 9) == 0
		&& setup_heredoc_loop(fds, &argv[argc - 2], envp, &error))
		execute(fds, argv[i + 2], envp, pids);
	else if (setup_end_loop(fds, &argv[argc - 2], envp, &error))
		execute(fds, argv[i + 2], envp, pids);
	multiple_close(fds[0], fds[1], fds[2]);
	return (close_pids(pids, error));
}

/* main:
*	Main function
*/
int	main(int argc, char **argv, char **envp)
{
	int	fds[3];

	if (argc < 5)
		return (1);
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		if (argc < 6)
			return (0);
		fds[0] = here_doc(argv[2]);
		if (fds[0] < 0)
			return (1);
		argv = &argv[1];
		argc--;
	}
	else
		fds[0] = infile(argv[1]);
	fds[1] = -1;
	fds[2] = -1;
	if (fds[0] < 0)
		return (1);
	return (loop(fds, argc, argv, envp));
}
