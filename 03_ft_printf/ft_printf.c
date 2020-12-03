/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:18:55 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/20 16:40:08 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_im_format(char c, t_f_lst *flag_lst, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'u')
		ft_im_diu(c, flag_lst, ap);
	else if (c == 'x' || c == 'X')
		ft_im_x(c, flag_lst, ap);
	else if (c == 'p')
		ft_im_p(c, flag_lst, ap);
	else if (c == 'c')
		ft_im_c(flag_lst, ap);
	else if (c == '%')
		ft_im_pct(flag_lst);
	else if (c == 's')
		ft_im_s(flag_lst, ap);
}

void		ft_im_wildcard(t_f_lst *flag_lst, va_list ap)
{
	if (flag_lst->prec_f)
	{
		flag_lst->prec_l = va_arg(ap, int);
		if (flag_lst->prec_l < 0)
		{
			flag_lst->prec_f = 0;
			flag_lst->prec_l = 0;
		}
	}
	else
	{
		flag_lst->width_l = va_arg(ap, int);
		if (flag_lst->width_l < 0)
		{
			flag_lst->zero_f = 0;
			flag_lst->minus_f = 1;
			flag_lst->width_l *= -1;
		}
	}
}

int			ft_im_digit(const char **str, t_f_lst *flag_lst)
{
	int		index;

	index = 0;
	if (flag_lst->prec_f)
		flag_lst->prec_l = ft_atoi(*str);
	else
		flag_lst->width_l = ft_atoi(*str);
	while (ft_isdigit(*(*str + 1)))
	{
		(*str)++;
		index++;
	}
	return (index);
}

int			ft_formatadventure(const char *str, t_f_lst *flag_lst, va_list ap)
{
	int		fm_len;

	fm_len = 1;
	while (*str != 'c' && *str != 's' && *str != 'p' &&
	*str != 'd' && *str != 'i' && *str != 'u' &&
	*str != 'x' && *str != 'X' && *str != '%')
	{
		if (*str == '-' || *str == '0' || *str == '.')
			ft_im_flag(*str, flag_lst);
		else if (ft_isdigit(*str) || *str == '*')
			if (*str == '*')
				ft_im_wildcard(flag_lst, ap);
			else
				fm_len += ft_im_digit(&str, flag_lst);
		else
			return (0);
		fm_len++;
		str++;
	}
	ft_im_format(*str, flag_lst, ap);
	return (fm_len);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_f_lst	*flag_lst;
	int		fm_len;
	int		return_value;

	va_start(ap, format);
	flag_lst = (t_f_lst *)malloc(sizeof(t_f_lst));
	flag_lst->return_value = 0;
	ft_reset_lst(flag_lst);
	while (*format)
		if (*format != '%')
		{
			write(1, format, 1);
			flag_lst->return_value++;
			format++;
		}
		else
		{
			fm_len = ft_formatadventure(format + 1, flag_lst, ap);
			format += fm_len + 1;
			ft_reset_lst(flag_lst);
		}
	va_end(ap);
	return_value = flag_lst->return_value;
	free(flag_lst);
	return (return_value);
}
