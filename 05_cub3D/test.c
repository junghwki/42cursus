void		ft_draw_3d(t_box *box)
{
	// ft_wall_check(box, 0);
	int		x;
	int		y;
	double	ray_theta;
	double	wall_height;

	ray_theta = box->win.width / 2;
	x = box->win.width - 1;
	while (x)
	{
		wall_height = (box->win.height / ft_wall_check(box, ft_deg_to_rad((66 / (double)box->win.width) * ray_theta))) * 0.34;
		// y = (box->win.height / 2) - wall_height;
		// if (y < 0)
		// 	y = 0;
		// if (y >= box->win.height)
		// 	y = box->win.height - 1;
		ft_draw_tex(box,wall_height, x);
		// printf("%f\n",box->pos.tex_x);
		// while ((y < (box->win.height / 2) + wall_height) && (y < box->win.height && y >= 0))
		// {
		// 	if(box->comp.x && box->dir.x < 0)
		// 		ft_pixel_put(box, x, y, 0xFF0000);
		// 	else if(box->comp.x && box->dir.x >= 0)
		// 		ft_pixel_put(box, x, y, 0x00FF00);
		// 	else if(box->comp.y && box->dir.y < 0)
		// 		ft_pixel_put(box, x, y, 0x0000FF);
		// 	else if(box->comp.y && box->dir.y >= 0)
		// 		ft_pixel_put(box, x, y, 0xFFFFFF);
		// 	y++;
		// }
		ray_theta--;
		x--;
	}
}