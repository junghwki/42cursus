/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:21:44 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/10 15:44:40 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long long int nbr)
{
	int		len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_llitoa(long long int nbr)
{
	char	*result;
	int		nbr_len;

	if (nbr == 0)
		return (ft_strdup("0"));
	nbr_len = ft_nbrlen(nbr);
	if (!(result = (char *)malloc(nbr_len + 1)))
		return (NULL);
	result[nbr_len] = '\0';
	if (nbr < 0)
	{
		*result = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		result[nbr_len - 1] = nbr % 10 + '0';
		nbr /= 10;
		nbr_len--;
	}
	return (result);
}
