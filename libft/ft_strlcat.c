/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:35:52 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/09 16:18:29 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	j = i;
	if (size > 0)
	{
		while (src[i - j] != '\0' && i < size - 1)
		{
			dst[i] = src[i - j];
			i++;
		}
		if (j < size)
			dst[i] = '\0';
	}
	return (j + ft_strlen(src));
}
