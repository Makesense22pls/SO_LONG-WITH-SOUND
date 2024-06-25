/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:00:55 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 13:35:21 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	ft_free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = (NULL);
		i++;
	}
	free(map);
	map = (NULL);
}

void	free_the_world(t_all_the_time *all, t_pixel *force, t_stp *pls)
{
	if (all->map != NULL)
	{
		ft_free_all(all->map);
		all->map = NULL;
	}
	if (all != NULL)
	{
		free(all);
		all = NULL;
	}
	if (pls != NULL)
	{
		free(pls);
		pls = NULL;
	}
	if (force != NULL)
	{
		free(force);
		force = NULL;
	}
}

t_all_the_time	*ft_mallocstruc(t_all_the_time *innit)
{
	innit = malloc(sizeof(t_all_the_time));
	if (!innit)
		return (0);
	return (innit);
}
