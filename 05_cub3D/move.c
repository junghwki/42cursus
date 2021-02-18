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
	box->pos.x += box->win.move_speed * cos(box->pos.theta);
	box->pos.y += box->win.move_speed * sin(box->pos.theta);
	if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
	{
		box->pos.x -= box->win.move_speed * cos(box->pos.theta);
		box->pos.y -= box->win.move_speed * sin(box->pos.theta);
		return;
	}
}

void        ft_move_down(t_box *box)
{
	box->pos.x -= box->win.move_speed * cos(box->pos.theta);
	box->pos.y -= box->win.move_speed * sin(box->pos.theta);
	if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
	{
		box->pos.x += box->win.move_speed * cos(box->pos.theta);
		box->pos.y += box->win.move_speed * sin(box->pos.theta);
		return;
	}
}

void        ft_move_left(t_box *box)
{
    double	temp;

    temp = box->pos.theta - ft_deg_to_rad(90);
    box->pos.x += box->win.move_speed * cos(temp);
    box->pos.y += box->win.move_speed * sin(temp);
    if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
    {
    	box->pos.x -= box->win.move_speed * cos(temp);
    	box->pos.y -= box->win.move_speed * sin(temp);
    }
}

void        ft_move_right(t_box *box)
{
    double	temp;

	temp = box->pos.theta + ft_deg_to_rad(90);
	box->pos.x += box->win.move_speed * cos(temp);
	box->pos.y += box->win.move_speed * sin(temp);
	if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
	{
		box->pos.x -= box->win.move_speed * cos(temp);
		box->pos.y -= box->win.move_speed * sin(temp);
	}
}

void        ft_rotate_left(t_box *box)
{
    // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
    box->pos.theta -= box->win.rotate_angle;
	if(box->pos.theta < -1 * M_PI)
		box->pos.theta += 2 * M_PI;
	// printf("%f\n",box->pos.theta);
    // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
}

void        ft_rotate_right(t_box *box)
{
    // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
    box->pos.theta += box->win.rotate_angle;
	if(box->pos.theta > M_PI)
		box->pos.theta -= 2 * M_PI;
	// printf("%f\n",box->pos.theta);
    // printf("X =%f, Y =%f\n", box->dir.x, box->dir.y);
}

// #include "cub3d.h"
// int			g_map[10][10] =//row,col
// 	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	 {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
// 	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// void        ft_move_up(t_box *box)
// {
//     box->pos.x += box->win.move_speed * (box->dir.x);
//     box->pos.y += box->win.move_speed * (box->dir.y);
//     if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
//     {
//         box->pos.x -= box->win.move_speed * (box->dir.x);
//         box->pos.y -= box->win.move_speed * (box->dir.y);
//         return;
//     }
// }

// void        ft_move_down(t_box *box)
// {
//     box->pos.x -= box->win.move_speed * (box->dir.x);
//     box->pos.y -= box->win.move_speed * (box->dir.y);
//     if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
//     {
//         box->pos.x += box->win.move_speed * (box->dir.x);
//         box->pos.y += box->win.move_speed * (box->dir.y);
//         return;
//     }
// }

// void        ft_move_left(t_box *box)
// {
//     t_vec   temp;

//     temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
//     box->pos.x += box->win.move_speed * (temp.x);
//     box->pos.y += box->win.move_speed * (temp.y);
//     if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
//     {
//         temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
//         box->pos.x -= box->win.move_speed * (temp.x);
//         box->pos.y -= box->win.move_speed * (temp.y);
//         return;
//     }
// }

// void        ft_move_right(t_box *box)
// {
//     t_vec   temp;

//     temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
//     box->pos.x -= box->win.move_speed * (temp.x);
//     box->pos.y -= box->win.move_speed * (temp.y);
//     if (g_map[(int)(box->pos.y / box->win.height_len)][(int)(box->pos.x / box->win.width_len)] == 1)
//     {
//         temp = ft_rot_vec(box->dis, ft_deg_to_rad(90));
//         box->pos.x += box->win.move_speed * (temp.x);
//         box->pos.y += box->win.move_speed * (temp.y);
//         return;
//     }
// }

// void        ft_rotate_left(t_box *box)
// {
//     // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
//     box->dis = ft_rot_vec(box->dis, box->win.rotate_angle);
//     // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
// }

// void        ft_rotate_right(t_box *box)
// {
//     // printf("X =%f, Y =%f\n", box->dir.x,box->dir.y);
//     box->dis = ft_rot_vec(box->dis, -1 * box->win.rotate_angle);
//     printf("X =%f, Y =%f\n", box->dir.x, box->dir.y);
// }