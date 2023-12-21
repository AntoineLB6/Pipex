/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:50:44 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/09 17:01:50 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int		sign;
	int		res;
	char	*nb;

	sign = 1;
	res = 0;
	nb = (char *)nbr;
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (*nb == '+' || *nb == '-')
	{
		if (*nb == '-')
			sign *= -1;
		nb++;
	}
	while (*nb != '\0' && (*nb >= '0' && *nb <= '9'))
	{
		res = res * 10 + (*nb - 48);
		nb++;
	}
	return (res * sign);
}
