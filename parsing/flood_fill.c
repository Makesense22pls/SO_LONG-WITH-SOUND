/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:15:15 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/17 23:41:24 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	fill(t_all_the_time *all, char **map_copie, size_t position_x,
		size_t position_y)
{
	if (map_copie[position_y][position_x] == '1'
		|| map_copie[position_y][position_x] == 'W')
		return ;
	if (position_y < 0 || position_y >= all->balade.nb_line || position_x < 0
		|| position_x >= all->balade.nb_colum)
		return ;
	if (map_copie[position_y][position_x] == 'C')
		all->count_collectible_ff++;
	if (map_copie[position_y][position_x] == 'E')
		all->check_exit_ff += 1;
	map_copie[position_y][position_x] = 'W';
	fill(all, map_copie, position_x, position_y - 1);
	fill(all, map_copie, position_x, position_y + 1);
	fill(all, map_copie, position_x - 1, position_y);
	fill(all, map_copie, position_x + 1, position_y);
}

int	flood_fill(t_all_the_time *all, t_stp *pls)
{
	int		position_x_player;
	int		position_y_player;
	int		y;
	char	**map_copie;

	map_copie = malloc(sizeof(char *) * (all->balade.nb_line + 1));
	y = 0;
	while (all->map[y] != NULL)
	{
		map_copie[y] = ft_strdup(all->map[y]);
		y++;
	}
	map_copie[y] = NULL;
	position_y_player = pls->positon_y_player_ff;
	position_x_player = pls->position_x_player_ff;
	fill(all, map_copie, position_x_player, position_y_player);
	ft_free_all(map_copie);
	if (all->nb_collectible != all->count_collectible_ff
		|| all->check_exit_ff == 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
