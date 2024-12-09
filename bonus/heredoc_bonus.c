/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:59:56 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/11 14:24:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_end_only(char *line, char *delim, size_t len)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line_len > 0 && line[line_len - 1] == '\n')
		line_len --;
	printf("%d | %zu-%zu\n", ft_memcmp(delim, line, len), len, line_len);
	return ((ft_memcmp(delim, line, len) == 0 && len == line_len)
		|| (ft_memcmp(delim, "EOF", 3) == 0
			&& line[0] == '\0'
			&& ft_strlen(line) == 0));
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
		return (return_error("Failed to create pipe", -1, 1, -1));
	len = ft_strlen(delim);
	ft_putstr_fd(">", 1);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			continue ;
		if (is_end_only(s, delim, len))
			break ;
		ft_putstr_fd(s, hfd[1]);
		ft_putstr_fd(">", 1);
		free(s);
	}
	free(s);
	close(hfd[1]);
	return (hfd[0]);
}
