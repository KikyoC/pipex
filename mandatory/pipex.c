/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:13:02 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/11 10:15:36 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (setup_end_loop(fds, &argv[argc - 2], envp, &error))
		execute(fds, argv[i + 2], envp, pids);
	return (close_pids(pids, error));
}

/* parse:
*	Iterate and on all arguments and try to find "" argument
*/
int	parse(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp("", argv[i], 1) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* main:
*	Main function
*/
int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	fds[3];

	if (argc != 5 || !parse(argc, argv))
		return (0);
	else if (access(argv[1], R_OK) == 0)
		infile = open(argv[1], O_RDONLY);
	else
		infile = -1;
	fds[0] = -1;
	if (infile > 0)
		fds[0] = infile;
	fds[1] = -1;
	fds[2] = -1;
	return (loop(fds, argc, argv, envp));
}
