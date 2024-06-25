/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:31:19 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 16:14:34 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

bool	check_map_place(char **map, t_all_the_time *evry)
{
	if (!(check_wall_line(map, evry)) && !(check_wall_collumn(map, evry)))
	{
		return (printf("MAP MAL FERMÉ\n"), false);
	}
	if (!(check_p_c_e(evry)))
	{
		return (false);
	}
	return (true);
}

bool	check_wall_line(char **map, t_all_the_time *evry)
{
	t_go	lib;

	lib.i = 0;
	while (lib.i < evry->balade.nb_colum)
	{
		if (!(ft_strchrmap("1", map[0][lib.i])))
			return (false);
		if (!(ft_strchrmap("1", map[evry->balade.nb_line - 1][lib.i])))
			return (false);
		lib.i++;
	}
	return (true);
}

bool	check_wall_collumn(char **map, t_all_the_time *evry)
{
	t_go	lib;

	lib.i = 0;
	while (lib.i < evry->balade.nb_line)
	{
		if (!(ft_strchrmap("1", map[lib.i][0])))
			return (false);
		if (!(ft_strchrmap("1", map[lib.i][evry->balade.nb_colum])))
			return (false);
		lib.i++;
	}
	return (true);
}

bool	check_p_c_e(t_all_the_time *evry)
{
	t_go		lib;
	static int	letters[128] = {0};

	lib.ycheh = 0;
	lib.count = 0;
	while (lib.ycheh < evry->balade.nb_line)
	{
		lib.x = 0;
		while (lib.x < evry->balade.nb_colum)
		{
			if (evry->map[lib.ycheh][lib.x] == 'P' ||
				evry->map[lib.ycheh][lib.x] == 'C'
				|| evry->map[lib.ycheh][lib.x] == 'E')
				letters[(int)evry->map[lib.ycheh][lib.x]] = 1;
			if (evry->map[lib.ycheh][lib.x] == 'P' ||
				evry->map[lib.ycheh][lib.x] == 'E')
				lib.count++;
			lib.x++;
		}
		lib.ycheh++;
	}
	if (letters[80] != 1 || letters[67] != 1 || letters[69] != 1
		|| lib.count > 2)
		return (printf("ERROR, INVALID MAP ELEMENTS"), false);
	return (true);
}

void	need_pos(t_all_the_time *all, t_stp *pls)
{
	int	x;
	int	y;

	y = 0;
	while (all->map[y] != NULL)
	{
		x = 0;
		while (all->map[y][x] != '\0')
		{
			if (all->map[y][x] == 'P')
			{
				pls->position_x_player_ff = x;
				pls->positon_y_player_ff = y;
			}
			x++;
		}
		y++;
	}
}
