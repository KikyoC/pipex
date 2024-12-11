/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:30:35 by tom               #+#    #+#             */
/*   Updated: 2024/12/11 09:53:48 by togauthi         ###   ########.fr       */
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

/* here_doc:
*	Take a delimiter as argument
*	Handle here_doc
*/
int	here_doc(char *delim)
{
	int		hfd[2];
	int		len;
	char	*s;

	if (pipe(hfd) == -1)
	{
		perror("Failed to create pipe");
		return (-1);
	}
	len = ft_strlen(delim);
	ft_putstr_fd(">", 1);
	s = get_next_line(0);
	while (s)
	{
		if ((ft_memcmp(delim, s, len) == 0)
			|| (ft_memcmp(delim, "EOF", 3) && s[0] == '\0'))
			break ;
		ft_putstr_fd(s, hfd[1]);
		ft_putstr_fd(">", 1);
		free(s);
		s = get_next_line(0);
	}
	free(s);
	close(hfd[1]);
	return (hfd[0]);
}

/* main:
*	Main function
*/
int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	fds[3];

	if (argc < 5 || !parse(argc, argv))
		return (0);
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		if (argc < 6)
			return (0);
		infile = here_doc(argv[2]);
		if (infile < 0)
			return (1);
		argv = &argv[1];
		argc--;
	}
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
