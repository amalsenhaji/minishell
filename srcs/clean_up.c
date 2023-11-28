/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:35:13 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:00:53 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_list *lexer)
{
	free_list(lexer);
}

void	free_parser(t_ast *tree)
{
	free_tree(tree->root);
	free(tree);
}

void	free_lexer_parser(t_list *lexer, t_ast *tree)
{
	free_lexer(lexer);
	free_parser(tree);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		free(cmd->args[i++]);
	free(cmd->args);
	free_redir_list(cmd->redir);
	free(cmd);
}

void	free_2d(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}
