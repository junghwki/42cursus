/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpct_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:54 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/09 20:31:33 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_im_c(t_f_lst *flag_lst, va_list ap)
{
	long long int	print_int;

	if (flag_lst->prec_f)
		flag_lst->zero_f = 0;
	flag_lst->print_w_l = flag_lst->width_l - 1;
	print_int = (long long int)va_arg(ap, int);
	if (flag_lst->minus_f)
	{
		write(1, &print_int, 1);
		flag_lst->return_value++;
		ft_print_width(flag_lst, print_int);
	}
	else
	{
		ft_print_width(flag_lst, print_int);
		write(1, &print_int, 1);
		flag_lst->return_value++;
	}
}

void				ft_im_pct(t_f_lst *flag_lst)
{
	long long int	print_int;

	flag_lst->print_w_l = flag_lst->width_l - 1;
	print_int = (long long int)'%';
	if (flag_lst->minus_f)
	{
		write(1, &print_int, 1);
		flag_lst->return_value++;
		ft_print_width(flag_lst, print_int);
	}
	else
	{
		ft_print_width(flag_lst, print_int);
		write(1, &print_int, 1);
		flag_lst->return_value++;
	}
}
