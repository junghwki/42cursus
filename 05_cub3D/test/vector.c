/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:49 by junghwki          #+#    #+#             */
/*   Updated: 2021/02/25 14:20:50 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec           ft_new_vec(double x, double y)
{
    t_vec       result;

    result.x = x;
    result.y = y;
    return (result);
}

t_vec           ft_add_vec(t_vec a, t_vec b)
{
    a.x += b.x;
    a.y += b.y;
    return (a);
}

t_vec           ft_sub_vec(t_vec a, t_vec b)
{
    a.x -= b.x;
    a.y -= b.y;
    return (a);
}

t_vec           ft_mul_vec(t_vec a, double k)
{
    a.x *= k;
    a.y *= k;
    return (a);
}

t_vec           ft_rot_vec(t_vec a, double theta)
{
    double      sin_theta;
    double      cos_theta;
    t_vec       result;

    sin_theta = sin(theta);
    cos_theta = cos(theta);
    result.x = cos_theta * a.x + sin_theta * a.y;
    result.y = -1 * (sin_theta * a.x) + cos_theta * a.y;
    return (result);
}
