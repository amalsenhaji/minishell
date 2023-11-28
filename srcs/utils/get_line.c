/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:38:50 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:01 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_next_line(int fd)
{
	char	line[8000000];
	char	buf;
	int		i;

	i = 0;
	write(1, "> ", 2);
	while (read(fd, &buf, 1) == 1)
	{
		line[i++] = buf;
		if (buf == '\n')
			break ;
	}
	line[i] = '\0';
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
