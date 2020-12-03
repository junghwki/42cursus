/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:49:19 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/09 20:31:31 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_px_format(char c, t_f_lst *flag_lst, va_list ap)
{
	char			*itoa_str;
	long long int	res;
	int				res_l;

	if (c == 'p')
		res = (long long int)va_arg(ap, long long);
	else
		res = (long long int)va_arg(ap, unsigned int);
	if (c == 'x' || c == 'p')
		itoa_str = ft_itoa_base_lo(res, 16);
	else
		itoa_str = ft_itoa_base_up(res, 16);
	res_l = ft_strlen(itoa_str);
	if (res == 0 && flag_lst->prec_f && !(flag_lst->prec_l))
	{
		res_l = 0;
		flag_lst->zero_value = 1;
	}
	if (c == 'p')
		res_l += 2;
	ft_res_l_cmp(flag_lst, res_l);
	free(itoa_str);
	return (res);
}

void				ft_im_x(char c, t_f_lst *flag_lst, va_list ap)
{
	long long int	print_int;
	char			*print_str;

	if (flag_lst->prec_f)
		flag_lst->zero_f = 0;
	print_int = ft_px_format(c, flag_lst, ap);
	if (c == 'x')
		print_str = ft_itoa_base_lo(print_int, 16);
	else
		print_str = ft_itoa_base_up(print_int, 16);
	if (flag_lst->minus_f)
	{
		ft_print_prec(flag_lst, print_int);
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
		ft_print_width(flag_lst, print_int);
	}
	else
	{
		ft_print_width(flag_lst, print_int);
		ft_print_prec(flag_lst, print_int);
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
	}
	free(print_str);
}

void				ft_im_p(char c, t_f_lst *flag_lst, va_list ap)
{
	long long int	print_int;
	char			*print_str;

	if (flag_lst->prec_f)
		flag_lst->zero_f = 0;
	print_int = ft_px_format(c, flag_lst, ap);
	print_str = ft_itoa_base_lo(print_int, 16);
	if (flag_lst->minus_f)
	{
		write(1, "0x", 2);
		flag_lst->return_value += 2;
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
		ft_print_width(flag_lst, print_int);
	}
	else
	{
		ft_print_width(flag_lst, print_int);
		write(1, "0x", 2);
		flag_lst->return_value += 2;
		if (!(flag_lst->zero_value))
			flag_lst->return_value += ft_putstr(print_str);
	}
	free(print_str);
}
