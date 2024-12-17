/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:13:02 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/17 16:38:40 by togauthi         ###   ########.fr       */
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

/*infile:
*	Open the file, if it fails, it will
*	return a file descriptor with nothing inside
*/
int	infile(char *file)
{
	int	fd;
	int	p[2];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		if (pipe(p) < 0)
		{
			perror("Cannot create pipe");
			return (-1);
		}
		close(p[1]);
		return (p[0]);
	}
	return (fd);
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
