/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:11:15 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/03 15:27:25 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strnbr(char *str, long long int nbr)
{
	if (nbr / 10 == 0)
	{
		*str = nbr % 10 + '0';
		return ;
	}
	while (nbr > 0)
	{
		*str = nbr % 10 + '0';
		nbr = nbr / 10;
		str--;
	}
}

static int	ft_nbrlen(long long int nbr)
{
	int				len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*result;
	int				nbr_len;
	long long int	nbr;

	nbr_len = ft_nbrlen((long long int)n);
	if (!(result = (char *)malloc(sizeof(char) * (nbr_len + 1))))
		return (NULL);
	result[nbr_len] = '\0';
	nbr = n;
	if (n < 0)
	{
		nbr = nbr * -1;
		*result = '-';
	}
	ft_strnbr(&result[nbr_len - 1], nbr);
	return (result);
}
