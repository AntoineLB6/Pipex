/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:10:39 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/14 12:01:40 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	source = src;
	destination = dest;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			destination[n] = source[n];
	}
	return (dest);
}
