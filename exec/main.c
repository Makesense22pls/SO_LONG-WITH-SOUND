/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:06:04 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 15:04:54 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	main(int argc, char **argv)
{
	t_all_the_time	*all;
	t_stp			*pls;
	t_pixel			*force;

	if (check_nb_arg_ber(argc, argv[1]) == 1)
		return (EXIT_FAILURE);
	all = ft_innit();
	pls = ft_innit2();
	force = ft_innit3();
	if ((checking(all, argv[1], pls) == 1))
	{
		free_the_world(all, force, pls);
		return (EXIT_FAILURE);
	}
	all->mlx = mlx_init(all->balade.nb_colum * 64, all->balade.nb_line * 64,
			"./so_long", false);
	if (!all->mlx)
		return (EXIT_FAILURE);
	ft_exec(all, force, pls);
	ft_delete_all(all);
	return (EXIT_SUCCESS);
}

void ft_delete_all(t_all_the_time *all)
{
	mlx_delete_image(all->mlx, all->img_perso);
	mlx_delete_texture(all->texture_perso);
	mlx_delete_image(all->mlx, all->img_collec);
	mlx_delete_texture(all->texture_collec);
	mlx_delete_image(all->mlx, all->img_exit);
	mlx_delete_texture(all->texture_exit);
	mlx_delete_image(all->mlx, all->img_floor);
	mlx_delete_texture(all->texture_floor);
	mlx_delete_image(all->mlx, all->img_final_exit);
	mlx_delete_texture(all->texture_final_exit);
	mlx_delete_image(all->mlx, all->img_wall);
	mlx_delete_texture(all->texture_wall);
}
