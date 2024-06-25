/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:09:46 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 12:58:33 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"
#include "libft/ft_printf.h"

int	check_nb_arg_ber(int argc, char *str)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("WRONG NUMBERS OF ARGS");
		return (EXIT_FAILURE);
	}
	while (str[i])
		i++;
	i--;
	if ((str[i] == 'r' && str[i - 1] == 'e'
			&& str[i - 2] == 'b' && str[i - 3] == '.'))
		return (EXIT_SUCCESS);
	else
	{
		ft_printf("ERROR! INVALID MAP NAME !\n");
		return (EXIT_FAILURE);
	}
}
