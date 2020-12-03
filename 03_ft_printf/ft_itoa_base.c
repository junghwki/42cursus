/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:21:44 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/10 18:46:06 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long long int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}

static char	ft_change_base_up(long long int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n > 9 && n < 16)
		return (n - 10 + 'A');
	return (0);
}

static char	ft_change_base_lo(long long int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n > 9 && n < 16)
		return (n - 10 + 'a');
	return (0);
}

char		*ft_itoa_base_up(long long int value, int base)
{
	char	*result;
	int		value_len;

	if (value == 0)
		return (ft_strdup("0"));
	value_len = ft_nbrlen(value, base);
	if (!(result = (char *)malloc(value_len + 1)))
		return (NULL);
	result[value_len] = '\0';
	if (value < 0)
	{
		*result = '-';
		value *= -1;
	}
	while (value)
	{
		result[value_len - 1] = ft_change_base_up(value % base);
		value /= base;
		value_len--;
	}
	return (result);
}

char		*ft_itoa_base_lo(long long int value, int base)
{
	char	*result;
	int		value_len;

	if (value == 0)
		return (ft_strdup("0"));
	value_len = ft_nbrlen(value, base);
	if (!(result = (char *)malloc(value_len + 1)))
		return (NULL);
	result[value_len] = '\0';
	if (value < 0)
	{
		*result = '-';
		value *= -1;
	}
	while (value)
	{
		result[value_len - 1] = ft_change_base_lo(value % base);
		value /= base;
		value_len--;
	}
	return (result);
}
