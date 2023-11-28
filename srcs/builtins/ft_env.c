/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:59:05 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:00:55 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd, char **env)
{
	int	i;

	i = 0;
	if (!cmd->args[1])
	{
		while (env[i])
		{
			if (ft_strchr(env[i], '=') != -1)
				printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		g_data.exit_status = EXIT_FAILURE;
		return (ft_perror("minishell: env: Too many arguments.", NULL));
	}
	return (EXIT_SUCCESS);
}
