/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:37:13 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 18:00:34 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
	void	*new;

	new = malloc(sizeof(void) * new_size);
	if (!new)
		return (NULL);
	new = memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
