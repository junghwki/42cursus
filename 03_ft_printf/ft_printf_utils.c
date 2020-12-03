/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:15:12 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/10 15:46:54 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_lst(t_f_lst *flag_lst)
{
	flag_lst->minus_f = 0;
	flag_lst->zero_f = 0;
	flag_lst->width_l = 0;
	flag_lst->prec_f = 0;
	flag_lst->prec_l = 0;
	flag_lst->print_w_l = 0;
	flag_lst->print_p_l = 0;
	flag_lst->zero_value = 0;
}

void	ft_im_flag(char c, t_f_lst *flag_lst)
{
	if (c == '-')
	{
		flag_lst->minus_f = 1;
		flag_lst->zero_f = 0;
	}
	else if (c == '0' && flag_lst->prec_f == 0 && flag_lst->minus_f == 0)
	{
		flag_lst->zero_f = 1;
		flag_lst->minus_f = 0;
	}
	else if (c == '.')
		flag_lst->prec_f = 1;
}

void	ft_print_width(t_f_lst *flag_lst, long long int res)
{
	int	index;

	index = 0;
	if (res < 0 && flag_lst->zero_f)
	{
		write(1, "-", 1);
		flag_lst->return_value++;
	}
	if (flag_lst->zero_f)
		while (index < flag_lst->print_w_l)
		{
			write(1, "0", 1);
			flag_lst->return_value++;
			index++;
		}
	else
		while (index < flag_lst->print_w_l)
		{
			write(1, " ", 1);
			flag_lst->return_value++;
			index++;
		}
}

void	ft_print_prec(t_f_lst *flag_lst, long long int res)
{
	int	index;

	index = 0;
	if (res < 0 && !(flag_lst->zero_f))
	{
		write(1, "-", 1);
		flag_lst->return_value++;
	}
	while (index < flag_lst->print_p_l)
	{
		write(1, "0", 1);
		flag_lst->return_value++;
		index++;
	}
}

void	ft_res_l_cmp(t_f_lst *flag_lst, int res_l)
{
	if (res_l < flag_lst->prec_l)
		flag_lst->print_p_l = flag_lst->prec_l - res_l;
	if (res_l + flag_lst->print_p_l < flag_lst->width_l)
		flag_lst->print_w_l = flag_lst->width_l - flag_lst->print_p_l - res_l;
}
