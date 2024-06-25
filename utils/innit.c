/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:22:20 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 13:46:36 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

t_all_the_time	*ft_innit(void)
{
	t_all_the_time	*innit;

	innit = NULL;
	innit = ft_mallocstruc(innit);
	innit->check = 0;
	innit->pidserv = 0;
	innit->pos_y_exit = 0;
	innit->pos_x_exit = 0;
	innit->move_count = 0;
	innit->balade.nb_colum = 0;
	innit->balade.count = 0;
	innit->balade.len = 0;
	innit->balade.nb_line = 0;
	innit->balade.count_check = 0;
	innit->pos_x_player = 0;
	innit->pos_y_player = 0;
	innit->count_collectible = 0;
	innit->balade.security = 0;
	innit->nb_collectible = 0;
	innit->count_collectible_ff = 0;
	innit->audiofile = NULL;
	innit->map = NULL;
	innit->mlx = NULL;
	innit->check_exit_ff = 0;
	return (innit);
}

t_stp	*ft_innit2(void)
{
	t_stp	*innit;

	innit = malloc(sizeof(t_stp));
	if (!innit)
		return (0);
	innit->position_x_player_ff = 0;
	innit->positon_y_player_ff = 0;
	return (innit);
}

t_pixel	*ft_innit3(void)
{
	t_pixel	*innit;

	innit = malloc(sizeof(t_pixel));
	if (!innit)
		return (0);
	innit->machinx = 0;
	innit->machiny = 0;
	innit->machinx = 0;
	innit->machiny = 0;
	innit->x = 0;
	innit->y = 0;
	innit->px_player = 0;
	innit->py_player = 0;
	innit->px_collec = 0;
	innit->py_collec = 0;
	innit->px_exit = 0;
	innit->py_exit = 0;
	innit->px_floor = 0;
	innit->py_floor = 0;
	innit->px_wall = 0;
	innit->py_wall = 0;
	return (innit);
}

size_t	ft_strlensolong(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchrmap(const char *s, int c)
{
	unsigned char	c_;
	unsigned char	*s_;

	c_ = (unsigned char)c;
	s_ = (unsigned char *)s;
	if (s == NULL)
		return (0);
	if (c_ == '\0')
	{
		while (*s_ != '\0')
			s_++;
		return ((char *)(s_));
	}
	while (*s_ != '\0')
	{
		if (*s_ == c_)
			return ((char *)(s_));
		s_++;
	}
	return (0);
}
