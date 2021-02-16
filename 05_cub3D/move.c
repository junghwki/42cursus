#include "cub3d.h"
int			g_map[10][10] =//row,col
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void        ft_move_up(t_box *box)
{
    box->pos.x += box->win.move_speed * (box->dis.x);
    box->pos.y += box->win.move_speed * (box->dis.y);
    if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
    {
        box->pos.x -= box->win.move_speed * (box->dis.x);
        box->pos.y -= box->win.move_speed * (box->dis.y);
        return;
    }
}

void        ft_move_down(t_box *box)
{
    box->pos.x -= box->win.move_speed * (box->dis.x);
    box->pos.y -= box->win.move_speed * (box->dis.y);
    if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
    {
        box->pos.x += box->win.move_speed * (box->dis.x);
        box->pos.y += box->win.move_speed * (box->dis.y);
        return;
    }
}

void        ft_move_left(t_box *box)
{
    t_vec   temp;

    temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
    box->pos.x += box->win.move_speed * (temp.x);
    box->pos.y += box->win.move_speed * (temp.y);
    if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
    {
        temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
        box->pos.x -= box->win.move_speed * (temp.x);
        box->pos.y -= box->win.move_speed * (temp.y);
        return;
    }
}

void        ft_move_right(t_box *box)
{
    t_vec   temp;

    temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
    box->pos.x -= box->win.move_speed * (temp.x);
    box->pos.y -= box->win.move_speed * (temp.y);
    if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
    {
        temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
        box->pos.x += box->win.move_speed * (temp.x);
        box->pos.y += box->win.move_speed * (temp.y);
        return;
    }
}

void        ft_rotate_left(t_box *box)
{
    // printf("X =%f, Y =%f\n", box->dis.x,box->dis.y);
    box->dis = ft_rot_vec(box->dis, box->win.rotate_angle);
    printf("X =%f, Y =%f\n", box->dis.x,box->dis.y);
}

void        ft_rotate_right(t_box *box)
{
    // printf("X =%f, Y =%f\n", box->dis.x,box->dis.y);
    box->dis = ft_rot_vec(box->dis, -1 * box->win.rotate_angle);
    printf("X =%f, Y =%f\n", box->dis.x, box->dis.y);
}