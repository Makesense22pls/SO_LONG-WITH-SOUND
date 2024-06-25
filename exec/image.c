/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:53 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 13:42:21 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	map_image(t_all_the_time *all, t_pixel *force)
{
	while (all->map[force->y] != NULL)
	{
		force->x = 0;
		force->machinx = 0;
		while (all->map[force->y][force->x])
		{
			if (all->map[force->y][force->x] == '1')
				ft_putimage_wall(force, all);
			else if (all->map[force->y][force->x] == '0')
				ft_putimage_floor(force, all);
			else if (all->map[force->y][force->x] == 'P')
				ft_give_pos_player(force, all);
			else if (all->map[force->y][force->x] == 'C')
				ft_putimage_collec(force, all);
			else if (all->map[force->y][force->x] == 'E')
				ft_putimage_exit(force, all);
			force->machinx += TILE_SIZE;
			force->x++;
		}
		force->machiny += TILE_SIZE;
		force->y++;
	}
	ft_putimage_player(force, all);
	return (EXIT_SUCCESS);
}

int	ft_putimage_wall(t_pixel *force, t_all_the_time *all)
{
	force->px_wall = force->machinx;
	force->py_wall = force->machiny;
	if (mlx_image_to_window(all->mlx, all->img_wall, force->px_wall,
			force->py_wall) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	ft_putimage_floor(t_pixel *force, t_all_the_time *all)
{
	force->px_floor = force->machinx;
	force->py_floor = force->machiny;
	if (mlx_image_to_window(all->mlx, all->img_floor, force->px_floor,
			force->py_floor) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	ft_putimage_exit(t_pixel *force, t_all_the_time *all)
{
	force->px_exit = force->machinx;
	force->py_exit = force->machiny;
	if (mlx_image_to_window(all->mlx, all->img_exit, force->px_exit,
			force->py_exit) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	ft_putimage_collec(t_pixel *force, t_all_the_time *all)
{
	force->px_collec = force->machinx;
	force->py_collec = force->machiny;
	if (mlx_image_to_window(all->mlx, all->img_collec, force->px_collec,
			force->py_collec) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
