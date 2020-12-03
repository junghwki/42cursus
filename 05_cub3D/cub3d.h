/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:15:29 by junghwki          #+#    #+#             */
/*   Updated: 2020/12/02 19:56:39 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct	s_b_list {
	void		*ft_mlx;
	void		*ft_win;
	int			win_width;
	int			win_height;
	int			player_x;
	int			player_y;
}				t_b_list;

#endif