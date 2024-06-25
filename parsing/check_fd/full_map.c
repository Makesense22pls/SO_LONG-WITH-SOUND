/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:37:10 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 12:52:41 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	ft_count_line(char *arg)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(arg, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		if (str == NULL)
			return (close(fd), i);
		i++;
		str = get_next_line(fd);
	}
	return (close(fd), i);
}

char	**full_map(char *arg, t_all_the_time *evry)
{
	t_go	draveil;
	int		fd;
	int		i;

	evry->balade.nb_line = 0;
	draveil.i = 0;
	if (ft_count_line(arg) == 0 || ft_count_line(arg) <= 2)
	{
		printf("ERROR, map INCCORECT");
		return (false);
	}
	evry->balade.nb_line = ft_count_line(arg);
	fd = open(arg, O_RDONLY);
	evry->map = malloc(sizeof(char *) * (evry->balade.nb_line + 1));
	if (!evry->map)
		return (free(evry->map), evry->map = NULL, NULL);
	while (evry->balade.nb_line > draveil.i)
	{
		evry->map[draveil.i] = get_next_line(fd);
		draveil.i++;
	}
	evry->map[draveil.i] = NULL;
	i = 0;
	return (close(fd), evry->map);
}

bool	check_len_char(char **map, t_all_the_time *evry)
{
	t_go	lib;

	evry->balade.nb_colum = 0;
	lib.ycheh = 0;
	while (lib.ycheh < evry->balade.nb_line)
	{
		evry->balade.nb_colum = ft_strlensolong(map[lib.ycheh]);
		if (lib.ycheh > 0)
		{
			if (ft_strlensolong(map[lib.ycheh - 1]) != evry->balade.nb_colum)
				return (printf("ERROR, SIZE MAP"), false);
		}
		lib.ycheh ++;
	}
	if (check_map_all_c(evry) == true)
		return (true);
	else
		return (printf("ERROR, WRONG CHAR\n"), false);
}

bool	check_map_all_c(t_all_the_time *evry)
{
	t_go	lib;

	lib.ycheh = 0;
	while (evry->map[lib.ycheh] != NULL)
	{
		lib.x = 0;
		while (evry->map[lib.ycheh][lib.x] != '\0')
		{
			if (evry->map[lib.ycheh][lib.x] == 'E')
			{
				evry->pos_x_exit = lib.x;
				evry->pos_y_exit = lib.ycheh;
			}
			if (evry->map[lib.ycheh][lib.x] == 'C')
				evry->nb_collectible++ ;
			if (!(ft_strchrmap("10EPC\n", evry->map[lib.ycheh][lib.x])))
				return (false);
			lib.x ++;
		}
		lib.ycheh ++;
	}
	return (true);
}

int	checking(t_all_the_time *all, char *str, t_stp *pls)
{
	if (!(full_map(str, all)))
		return (EXIT_FAILURE);
	if (!(check_len_char(all->map, all)) || !(check_map_place(all->map, all)))
		return (EXIT_FAILURE);
	need_pos(all, pls);
	if (flood_fill(all, pls) == 1)
	{
		ft_printf("ERROR, UNPLAYABLE MAP\n");
		return (EXIT_FAILURE);
	}
	if (all->balade.nb_colum > 41 || all->balade.nb_line > 21)
	{
		printf("ERROR MAP TOO BIG");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
