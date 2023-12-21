/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:21:43 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/09 11:39:42 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *search, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)s;
	if (search[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] == search[0])
		{
			j = 0;
			while (str[i + j] && search[j]
				&& str[i + j] == search[j] && i + j < len)
				j++;
			if (search[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
