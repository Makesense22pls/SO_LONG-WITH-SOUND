/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:41:20 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 13:44:12 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	ft_putimage_player(t_pixel *force, t_all_the_time *all)
{
	if (mlx_image_to_window(all->mlx, all->img_floor
			, force->px_player, force->py_player) < 0)
		return (EXIT_FAILURE);
	else if (mlx_image_to_window(all->mlx, all->img_perso
			, force->px_player, force->py_player) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

void	ft_give_pos_player(t_pixel *force, t_all_the_time *all)
{
	all->pos_x_player = force->x;
	all->pos_y_player = force->y;
	force->px_player = force->machinx;
	force->py_player = force->machiny;
}
