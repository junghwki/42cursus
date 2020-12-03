/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:34:50 by junghwki          #+#    #+#             */
/*   Updated: 2020/11/30 17:13:44 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_f_lst {
	int			minus_f;
	int			zero_f;
	int			width_l;
	int			prec_f;
	int			prec_l;
	int			print_w_l;
	int			print_p_l;
	int			zero_value;
	int			return_value;
}				t_f_lst;

int				ft_printf(const char *format, ...);
void			ft_reset_lst(t_f_lst *flag_lst);
void			ft_im_flag(char c, t_f_lst *flag_lst);
void			ft_print_width(t_f_lst *flag_lst, long long int result);
void			ft_print_prec(t_f_lst *flag_lst, long long int result);
void			ft_res_l_cmp(t_f_lst *flag_lst, int res_l);
void			ft_im_diu(char c, t_f_lst *flag_lst, va_list ap);
void			ft_im_x(char c, t_f_lst *flag_lst, va_list ap);
void			ft_im_p(char c, t_f_lst *flag_lst, va_list ap);
void			ft_im_c(t_f_lst *flag_lst, va_list ap);
void			ft_im_pct(t_f_lst *flag_lst);
void			ft_im_s(t_f_lst *flag_lst, va_list ap);
char			*ft_itoa_base_lo(long long int value, int base);
char			*ft_itoa_base_up(long long int value, int base);
char			*ft_llitoa(long long int nbr);
int				ft_putstr(char *str);
#endif
