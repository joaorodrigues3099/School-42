/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memchr.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Find the first occurrence of the character c in the
 * initial n bytes pointed by s.
 *
 * @param s A pointer to the source that should be scanned.
 * @param c The character to check for.
 * @param n The amount of bytes to check for the character.
 * @return A pointer to the first occurence of the character.
 * NULL if there was no occurence.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sc;
	size_t		i;

	sc = (const char *)s;
	i = -1;
	while (i++ < n)
	{
		if (*(sc + i) == (char)c)
			return ((void *)sc + 1);
	}
	return (NULL);
}
