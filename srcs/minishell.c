/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:00:22 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:00:54 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	data->exit_status = 0;
	data->which = 0;
	data->pid = 0;
	data->tree = NULL;
	data->ev = NULL;
	data->alloc = 0;
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1 || !*env)
		return (1);
	init_data(&g_data);
	init_sigaction(&g_data);
	lunch_program(env);
	return (0);
}
