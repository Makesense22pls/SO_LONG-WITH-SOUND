/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_and_resume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:30:36 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 16:09:01 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	init_text_img(t_all_the_time *all)
{
	all->texture_wall = mlx_load_png("textures/WALL.png");
	all->texture_perso = mlx_load_png("textures/PLAYER.png");
	all->texture_floor = mlx_load_png("textures/FLOOR.png");
	all->texture_exit = mlx_load_png("textures/EXIT.png");
	all->texture_collec = mlx_load_png("textures/COLLEC.png");
	all->texture_final_exit = mlx_load_png("textures/FINAL_EXIT.png");
	if (!all->texture_wall || !all->texture_final_exit || !all->texture_perso
		|| !all->texture_floor || !all->texture_exit || !all->texture_collec)
		return (EXIT_FAILURE);
	all->img_wall = mlx_texture_to_image(all->mlx, all->texture_wall);
	all->img_perso = mlx_texture_to_image(all->mlx, all->texture_perso);
	all->img_floor = mlx_texture_to_image(all->mlx, all->texture_floor);
	all->img_exit = mlx_texture_to_image(all->mlx, all->texture_exit);
	all->img_collec = mlx_texture_to_image(all->mlx, all->texture_collec);
	all->img_final_exit = mlx_texture_to_image(all->mlx,
			all->texture_final_exit);
	if (!all->img_wall || !all->img_final_exit || !all->img_perso
		|| !all->img_floor || !all->img_exit || !all->img_collec)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_exec(t_all_the_time *all, t_pixel *force, t_stp *pls)
{
	(void) pls;
	init_text_img(all);
	map_image(all, force);
	mlx_key_hook(all->mlx, &my_keyhook, all);
	mlx_loop(all->mlx);
	mlx_terminate(all->mlx);
	system("killall afplay");
	free_the_world(all, force, pls);
}
