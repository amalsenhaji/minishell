/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:03:02 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:00:20 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_plus(int *i, int plus)
{
	if (!plus)
		(*i)++;
	else
		(*i) += plus;
}

void	check_cmd_state(t_elem**ptr, char **env, int *value)
{
	if ((*ptr)->state == GENERAL)
	{
		(*value)++;
		if ((*ptr)->type == ENV)
		{
			if (ft_strcmp(expand_env((*ptr)->content, env), "") == EQUAL)
				(*value)--;
		}
	}
	else
	{
		while ((*ptr) && (*ptr)->state != GENERAL)
			(*ptr) = (*ptr)->next;
		(*value)++;
	}
}
