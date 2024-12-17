/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:45:46 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/17 16:46:12 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* loop:
*	Take 3 fd, and input of main function
*	Call execute for each argument
*/
int	loop(int fds[3], int argc, char **argv, char **envp)
{
	int		*pids;
	int		error;

	error = 0;
	pids = create_pids(argc);
	if (!pids)
		return (1);
	if (setup_first_loop(fds, argv[2], envp, &error) > 0)
		execute(fds, argv[2], envp, pids);
	if (setup_end_loop(fds, &argv[argc - 2], envp, &error))
		execute(fds, argv[3], envp, pids);
	multiple_close(fds[0], fds[1], fds[2]);
	return (close_pids(pids, error));
}

/* main:
*	Main function
*/
int	main(int argc, char **argv, char **envp)
{
	int	fds[3];

	if (argc != 5 || !parse(argc, argv))
		return (1);
	fds[0] = infile(argv[1]);
	fds[1] = -1;
	fds[2] = -1;
	if (fds[0] < 0)
		return (1);
	return (loop(fds, argc, argv, envp));
}
