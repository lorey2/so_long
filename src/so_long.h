/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:40:39 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 15:54:43 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <bits/types/struct_timeval.h>
# include <X11/keysym.h>
# include "get_next_line.h"
# include <sys/time.h>

# define MALLOC_ERROR	1
# define CASE_SIZE		50

typedef struct s_img
{
	void	*img2;
	void	*img3;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*player;
	void	*door;
	void	*opendoor;
	void	*monster;
	int		coin_state;
	int		ennemy_state;
}				t_img;

typedef struct s_mlx_data
{
	int				is_finished;
	int				is_window;
	int				is_mlx;
	int				is_img;
	int				is_big_tab;
	int				size_x_window;
	int				size_y_window;
	void			*mlx_ptr;
	void			*win_ptr;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				next_case_x;
	int				next_case_y;
	char			*big_tab[50];
	int				n_coins_to_collect;
	int				n_coins_collected;
	int				n_coins_fullfill;
	int				n_door_fullfill;
	int				pos_next_coin_x;
	int				pos_next_coin_y;
	int				pos_next_en_y;
	int				pos_next_en_x;
	int				next_en_x;
	int				next_en_y;
	int				move_count;
	int				j;
	struct timeval	milis_start;
	struct timeval	milis_now;
	t_img			img;
}				t_mlx_data;

char				*ft_itoa(int n);
void				parsing(t_mlx_data *data, char **argv);
int					print_basic_map(t_mlx_data *data);
int					handle_input(int keysym, t_mlx_data *data);
void				setup_img_ptrs(t_mlx_data *data);
int					update_sprite(t_mlx_data *data);
void				some_setup_and_call_parsing(t_mlx_data *data, char **argv);
unsigned long int	time_diff(t_mlx_data *data);
int					free_everything(t_mlx_data *data, char *error_message);
void				move_ennemy(t_mlx_data *data, int keysym);

#endif
