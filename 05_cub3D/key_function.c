#include "cub3d.h"

int ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13) //W
		box->key.w = 1;
	else if (keycode == 1) //S
		box->key.s = 1;
	else if (keycode == 0) //A
		box->key.a = 1;
	else if (keycode == 2) //D
		box->key.d = 1;
	else if (keycode == 123) //좌측 방향키123
		box->key.left = 1;
	else if (keycode == 124) //우측 방향키124
		box->key.right = 1;
	else if (keycode == 53) //esc
		exit(0);
	return (0);
}

int ft_key_release(int keycode, t_box *box)
{
	if (keycode == 13) //W
		box->key.w = 0;
	else if (keycode == 1) //S
		box->key.s = 0;
	else if (keycode == 0) //A
		box->key.a = 0;
	else if (keycode == 2) //D
		box->key.d = 0;
	else if (keycode == 123) //좌측 방향키123
		box->key.left = 0;
	else if (keycode == 124) //우측 방향키124
		box->key.right = 0;
	return (0);
}

int ft_player_move(t_box *box)
{
	if (box->key.w) //W
		ft_move_up(box);
	if (box->key.s) //S
		ft_move_down(box);
	if (box->key.a) //A
		ft_move_left(box);
	if (box->key.d) //D
		ft_move_right(box);
	if (box->key.left) //좌측 방향키
		ft_rotate_left(box);
	if (box->key.right) //우측 방향키
		ft_rotate_right(box);
	return (0);
}