/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:24:49 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 16:27:16 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13)
		box->key.w = 1;
	else if (keycode == 1)
		box->key.s = 1;
	else if (keycode == 0)
		box->key.a = 1;
	else if (keycode == 2)
		box->key.d = 1;
	else if (keycode == 123)
		box->key.left = 1;
	else if (keycode == 124)
		box->key.right = 1;
	else if (keycode == 46 && box->key.m == 0)
		box->key.m = 1;
	else if (keycode == 46 && box->key.m == 1)
		box->key.m = 0;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_key_release(int keycode, t_box *box)
{
	if (keycode == 13)
		box->key.w = 0;
	else if (keycode == 1)
		box->key.s = 0;
	else if (keycode == 0)
		box->key.a = 0;
	else if (keycode == 2)
		box->key.d = 0;
	else if (keycode == 123)
		box->key.left = 0;
	else if (keycode == 124)
		box->key.right = 0;
	return (0);
}

int		ft_key_function(t_box *box)
{
	if (box->key.w)
		ft_move_up(box);
	if (box->key.s)
		ft_move_down(box);
	if (box->key.a)
		ft_move_left(box);
	if (box->key.d)
		ft_move_right(box);
	if (box->key.left)
		ft_rotate_left(box);
	if (box->key.right)
		ft_rotate_right(box);
	return (0);
}
