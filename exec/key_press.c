/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:19:31 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 16:08:43 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	ft_escape(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		system("killall afplay");
		exit(0);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_all_the_time	*all;

	all = param;
	ft_escape(keydata);
	if ((all->map[all->pos_y_player - 1][all->pos_x_player] != '1')
		&& (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS))
		dothiswhenkeyup(all);
	if ((all->map[all->pos_y_player + 1][all->pos_x_player] != '1')
		&& (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_PRESS))
		dothiswhenkeydown(all);
	if ((all->map[all->pos_y_player][all->pos_x_player + 1] != '1')
		&& ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
		&& (keydata.action == MLX_PRESS))
		dothiswhenkeyright(all);
	if ((all->map[all->pos_y_player][all->pos_x_player - 1] != '1')
		&& (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_PRESS))
		dothiswhenkeyleft(all);
}
