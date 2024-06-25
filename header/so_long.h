/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:44:34 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/18 15:03:44 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TILE_SIZE 64

typedef struct s_stp
{
	size_t			position_x_player_ff;
	size_t			positon_y_player_ff;
}					t_stp;

typedef struct s_go
{
	size_t			i;
	size_t			j;
	size_t			x;
	size_t			ycheh;
	size_t			count;
	size_t			len;
	size_t			nb_line;
	size_t			nb_colum;
	size_t			count_check;
	size_t			security;
}					t_go;

typedef struct s_pixel
{
	size_t			machinx;
	size_t			machiny;
	size_t			x;
	size_t			y;
	size_t			px_player;
	size_t			py_player;
	size_t			px_collec;
	size_t			py_collec;
	size_t			px_exit;
	size_t			py_exit;
	size_t			px_floor;
	size_t			py_floor;
	size_t			px_wall;
	size_t			py_wall;
	size_t			security;
}					t_pixel;

typedef struct s_all_the_time
{
	t_go			balade;
	mlx_t			*mlx;
	char			**map;
	size_t			pos_x_player;
	size_t			pos_y_player;
	int				move_count;
	size_t			pos_x_exit;
	size_t			pos_y_exit;
	int				check;
	size_t			nb_collectible;
	size_t			count_collectible;
	size_t			count_collectible_ff;
	int				checksoundniska;

	char			*audiofile;
	char			**map_copie;
	pid_t			pidserv;
	int				result;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_perso;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_collec;
	mlx_texture_t	*texture_final_exit;

	mlx_image_t		*img_wall;
	mlx_image_t		*img_perso;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_collec;
	mlx_image_t		*img_final_exit;
	int				check_exit_ff;
}					t_all_the_time;

t_all_the_time		*ft_mallocstruc(t_all_the_time *innit);
t_all_the_time		*ft_innit(void);
t_stp				*ft_innit2(void);
t_pixel				*ft_innit3(void);
void				ft_escape(mlx_key_data_t keydata);
void				dothiswhenkeyleft(t_all_the_time *all);
void				dothiswhenkeyright(t_all_the_time *all);
void				dothiswhenkeyup(t_all_the_time *all);
void				dothiswhenkeydown(t_all_the_time *all);
void				print_final_window(t_all_the_time *all);
void				ft_final_sound(t_all_the_time *all);
void				my_keyhook(mlx_key_data_t keydata, void *param);
void				chicken_sound_new_floor_and_player(t_all_the_time *all,
						size_t position_x_player, size_t position_y_player);
int					map_image(t_all_the_time *all, t_pixel *force);
int					init_text_img(t_all_the_time *all);
int					ft_count_line(char *arg);
char				**full_map(char *arg, t_all_the_time *evry);
void				ft_free_all(char **map);
bool				check_map_all_c(t_all_the_time *evry);
char				*ft_strchrmap(const char *s, int c);
bool				check_len_char(char **map, t_all_the_time *evry);
size_t				ft_strlensolong(const char *s);
// CHECK MAP GOOD POSITION
bool				check_map_place(char **map, t_all_the_time *evry);
bool				check_wall_line(char **map, t_all_the_time *evry);
bool				check_wall_collumn(char **map, t_all_the_time *evry);
bool				check_p_c_e(t_all_the_time *evry);
int					flood_fill(t_all_the_time *all, t_stp *pls);
void				fill(t_all_the_time *all, char **map_copie,
						size_t position_x_player, size_t position_y_player);
void				need_pos(t_all_the_time *all, t_stp *pls);
int					check_nb_arg_ber(int argc, char *str);
void				ft_exec(t_all_the_time *all, t_pixel *force, t_stp *pls);
int					checking(t_all_the_time *all, char *str, t_stp *pls);
int					ft_putimage_wall(t_pixel *force, t_all_the_time *all);
int					ft_putimage_player(t_pixel *force, t_all_the_time *all);
int					ft_putimage_collec(t_pixel *force, t_all_the_time *all);
int					ft_putimage_floor(t_pixel *force, t_all_the_time *all);
int					ft_putimage_exit(t_pixel *force, t_all_the_time *all);
void				free_the_world(t_all_the_time *all, t_pixel *force,
						t_stp *pls);
int					putimage(t_all_the_time *all);
void				ft_give_pos_player(t_pixel *force, t_all_the_time *all);
void ft_delete_all(t_all_the_time *all);