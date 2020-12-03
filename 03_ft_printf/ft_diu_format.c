/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diu_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:47:22 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/09 20:31:31 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_diu_format(char c, t_f_lst *flag_lst, va_list ap)
{
	char			*itoa_str;
	char			*str_start;
	long long int	res;
	int				res_l;

	if (c == 'u')
		res = (long long int)va_arg(ap, unsigned int);
	else
		res = (long long int)va_arg(ap, int);
	itoa_str = ft_llitoa(res);
	str_start = itoa_str;
	if (res < 0)
		itoa_str++;
	res_l = ft_strlen(itoa_str);
	if (res == 0 && flag_lst->prec_f && !(flag_lst->prec_l))
	{
		res_l = 0;
		flag_lst->zero_value = 1;
	}
	ft_res_l_cmp(flag_lst, res_l);
	if (res < 0)
		flag_lst->print_w_l--;
	free(str_start);
	return (res);
}

void				ft_im_diu(char c, t_f_lst *flag_lst, va_list ap)
{
	long long int	print_int;
	char			*print_str;
	char			*str_start;

	if (flag_lst->prec_f)
		flag_lst->zero_f = 0;
	print_int = ft_diu_format(c, flag_lst, ap);
	print_str = ft_llitoa(print_int);
	str_start = print_str;
	if (print_int < 0)
		print_str++;
	if (flag_lst->minus_f)
	{
		ft_print_prec(flag_lst, print_int);
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
	}
	ft_print_width(flag_lst, print_int);
	if (flag_lst->minus_f == 0)
	{
		ft_print_prec(flag_lst, print_int);
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
	}
	free(str_start);
}
