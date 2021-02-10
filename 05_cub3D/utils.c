#include "cub3d.h"

void		ft_pixel_put(t_box *box, int x, int y, int color)
{
	box->i.img_addr[(box->win.width * y) + x] = color;
}

void		ft_clear_image(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height))
	{
		box->i.img_addr[index] = 0;
		index++;
	}
}

void		ft_background_init(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height) / 2)
	{
		box->i.img_addr[index] = 0x999999;
		index++;
	}
	while (index < (box->win.width) * (box->win.height))
    {
        box->i.img_addr[index] = 0xBBBBBB;
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