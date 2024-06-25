/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_and_change_image.c.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:09:46 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 16:10:51 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	print_final_window(t_all_the_time *all)
{
	if (all->check == 1 && all->balade.security == 0)
	{
		all->balade.security++;
		all->balade.count++;
		ft_final_sound(all);
		if (mlx_image_to_window(all->mlx, all->img_final_exit, all->pos_x_exit
				* 64, (all->pos_y_exit) * 64) < 0)
			return ;
	}
}

void	chicken_sound_new_floor_and_player(t_all_the_time *all,
		size_t position_x_player, size_t position_y_player)
{
	if (all->pidserv == 0 && all->count_collectible < all->nb_collectible)
	{
		all->audiofile = "afplay textures/chicken.mp3";
		all->result = system(all->audiofile);
		exit(0);
	}
	else if (all->pidserv < 0)
	{
		ft_printf("ERROR");
		exit(0);
	}
	else
	{
		if (++all->count_collectible == all->nb_collectible)
			all->check = 1;
		all->map[position_y_player][position_x_player] = '0';
		if (mlx_image_to_window(all->mlx, all->img_floor, position_x_player
				* 64, position_y_player * 64) < 0)
			return ;
		if (mlx_image_to_window(all->mlx, all->img_perso, position_x_player
				* 64, position_y_player * 64) < 0)
			return ;
	}
}

void	ft_final_sound(t_all_the_time *all)
{
	all->pidserv = fork();
	if (all->pidserv == 0)
	{
		all->audiofile = "afplay textures/Le_poulet_cest_trop_bon.mp3";
		all->result = system(all->audiofile);
		exit(0);
	}
	else if (all->pidserv < 0)
	{
		ft_printf("ERROR");
		exit(0);
	}
}
