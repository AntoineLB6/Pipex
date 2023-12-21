/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:06:45 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/15 13:11:33 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (size != 0 && (count * size / count != size))
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	p = arr;
	while (i < count * size)
	{
		*p++ = 0;
		i++;
	}
	return (arr);
}
