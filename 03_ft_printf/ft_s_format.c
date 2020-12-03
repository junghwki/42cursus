/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:45:52 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/09 20:31:34 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_minus_fs(char *print_str, t_f_lst *flag_lst, int str_len)
{
	int		index;

	index = 0;
	while (index < str_len)
	{
		write(1, print_str, 1);
		flag_lst->return_value += 1;
		print_str++;
		index++;
	}
	index = 0;
	while (index < flag_lst->width_l - str_len)
	{
		write(1, " ", 1);
		flag_lst->return_value += 1;
		index++;
	}
}

void		ft_s(char *print_str, t_f_lst *flag_lst, int str_len)
{
	int		index;

	index = 0;
	while (index < flag_lst->width_l - str_len)
	{
		write(1, " ", 1);
		flag_lst->return_value += 1;
		index++;
	}
	index = 0;
	while (index < str_len)
	{
		write(1, print_str, 1);
		flag_lst->return_value += 1;
		print_str++;
		index++;
	}
}

void		ft_im_s(t_f_lst *flag_lst, va_list ap)
{
	char	*print_str;
	int		index;
	int		str_len;
	char	*temp;

	index = 0;
	temp = va_arg(ap, char *);
	if (temp == 0)
		print_str = ft_strdup("(null)");
	else
		print_str = ft_strdup(temp);
	str_len = (int)ft_strlen(print_str);
	if (flag_lst->prec_f)
	{
		if (str_len < flag_lst->prec_l)
			flag_lst->prec_l = str_len;
		else
			str_len = flag_lst->prec_l;
	}
	if (flag_lst->minus_f)
		ft_minus_fs(print_str, flag_lst, str_len);
	else
		ft_s(print_str, flag_lst, str_len);
	free(print_str);
}
