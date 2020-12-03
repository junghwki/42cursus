/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:35:47 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/10 15:43:58 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		write(1, str, 1);
		len++;
		str++;
	}
	return (len);
}
