#include "cub3d.h"

void		ft_pixel_put(t_box *box, int x, int y, int color)
{
	box->img.img_addr[(box->win.width * y) + x] = color;
}

void		ft_clear_image(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height))
	{
		box->img.img_addr[index] = 0;
		index++;
	}
}

void		ft_background_init(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height) / 2)
	{
		box->img.img_addr[index] = 0x7777FF;
		index++;
	}
	while (index < (box->win.width) * (box->win.height))
    {
        box->img.img_addr[index] = 0x77FF77;
        index++;
    }    
}

double		ft_gradient_cmp(double x, double y)
{
	return (fabs(x) >= fabs(y));
}

int         ft_exit(t_box *box)
{
	exit(0);
	return (0);
}

double      ft_deg_to_rad(double x)
{
    return (x * M_PI / 180);
}

t_vec		ft_theta_check(double theta)
{
	if(theta > ft_deg_to_rad(0) && theta < ft_deg_to_rad(90))
		return(ft_new_vec(1,1));
	else if(theta > ft_deg_to_rad(90) && theta < ft_deg_to_rad(180))
		return(ft_new_vec(-1,1));
	else if(theta > ft_deg_to_rad(180) && theta < ft_deg_to_rad(270))
		return(ft_new_vec(-1,-1));
	else if(theta > ft_deg_to_rad(270) && theta < ft_deg_to_rad(360))
		return(ft_new_vec(1,-1));
	else if(theta == ft_deg_to_rad(90))
		return(ft_new_vec(0,1));
	else if(theta == ft_deg_to_rad(180))
		return(ft_new_vec(-1,0));
	else if(theta == ft_deg_to_rad(270))
		return(ft_new_vec(0,-1));
	else if(theta == ft_deg_to_rad(360) || theta == ft_deg_to_rad(0))
		return(ft_new_vec(1,0));
	else
		return(ft_new_vec(0,0));
}

double		ft_rot_theta(t_box *box, double theta)
{
	double	result;

	result = box->pos.theta;
	if(result + theta <= 0)
		result = (result + (2 * M_PI)) + theta;
	else if(result + theta >= 2 * M_PI)
		result = (result - (2 * M_PI)) + theta;
	else
		result += theta;
	return (result);
}