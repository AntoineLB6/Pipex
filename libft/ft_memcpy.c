/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:55:46 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/14 12:00:55 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!dest && !src)
		return (NULL);
	i = 0;
	p = dest;
	while (i < n)
	{
		*p++ = *(unsigned char *)src++;
		i++;
	}
	return (dest);
}
