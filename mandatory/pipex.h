/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:36:19 by tom               #+#    #+#             */
/*   Updated: 2024/12/12 12:53:40 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/wait.h>

char	*get_command_path(char **path, char *command);
void	free_split(char **str);
char	*get_path(char **envp);
int		execute(int fds[3], char *cmd, char **envp, int *pids);
int		return_error(char *error, int fd, int type, int errcode);
void	multiple_close(int fd1, int fd2, int fd3);
int		setup_first_loop(int fds[3], char *arg, char **envp, int *error);
int		setup_end_loop(int fds[3], char **args, char **envp, int *error);
int		*create_pids(size_t size);
int		close_pids(int *pids, int error);
void	insert_pid(int *pids, int pid);
char	**no_env(char **res);
char	**build_arg(char *arg, char **envp);
void	default_pipe(int fds[3]);
void	setup_pipe(int *fds[3]);
char	**arg_fixer(char **args);

#endif
