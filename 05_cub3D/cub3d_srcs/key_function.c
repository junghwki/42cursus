/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:24:49 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 18:51:29 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13)
		box->key.w_flag = 1;
	else if (keycode == 1)
		box->key.s_flag = 1;
	else if (keycode == 0)
		box->key.a_flag = 1;
	else if (keycode == 2)
		box->key.d_flag = 1;
	else if (keycode == 123)
		box->key.left_flag = 1;
	else if (keycode == 124)
		box->key.right_flag = 1;
	else if (keycode == 46 && box->key.m_flag == 0)
		box->key.m_flag = 1;
	else if (keycode == 46 && box->key.m_flag == 1)
		box->key.m_flag = 0;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_key_release(int keycode, t_box *box)
{
	if (keycode == 13)
		box->key.w_flag = 0;
	else if (keycode == 1)
		box->key.s_flag = 0;
	else if (keycode == 0)
		box->key.a_flag = 0;
	else if (keycode == 2)
		box->key.d_flag = 0;
	else if (keycode == 123)
		box->key.left_flag = 0;
	else if (keycode == 124)
		box->key.right_flag = 0;
	return (0);
}

int		ft_key_function(t_box *box)
{
	if (box->key.w_flag)
		ft_move_up(box);
	if (box->key.s_flag)
		ft_move_down(box);
	if (box->key.a_flag)
		ft_move_left(box);
	if (box->key.d_flag)
		ft_move_right(box);
	if (box->key.left_flag)
		ft_rotate_left(box);
	if (box->key.right_flag)
		ft_rotate_right(box);
	return (0);
}
