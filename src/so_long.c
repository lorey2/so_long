/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:56:55 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 20:08:59 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned long int	time_diff(t_mlx_data *data)
{
	long	seconds;
	long	useconds;
	long	mtime;

	seconds = data->milis_now.tv_sec - data->milis_start.tv_sec;
	useconds = data->milis_now.tv_usec - data->milis_start.tv_usec;
	mtime = ((seconds) * 1000 + useconds / 1000.0);
	return (mtime);
}

static int	close_cross(t_mlx_data *data)
{
	return (free_everything(data, NULL));
}

static void	check_map_name(int argc, char **argv, t_mlx_data *data)
{
	int	i;

	i = 0;
	data->is_img = 0;
	data->is_mlx = 0;
	data->is_window = 0;
	data->move_count = 0;
	data->is_finished = 0;
	data->is_big_tab = 0;
	data->img.ennemy_state = 1;
	if (argc != 2)
		free_everything(data, "Error\nyou_must_have_exactly_two_arguments");
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (argv[1][i] == '\0')
		free_everything(data, "Error\nno_map_.ber_extention");
	if (argv[1][++i] != 'b')
		free_everything(data, "Error\nwrong_extention_must_be_.ber");
	if (argv[1][++i] != 'e')
		free_everything(data, "Error\nwrong_extention_must_be_.ber");
	if (argv[1][++i] != 'r')
		free_everything(data, "Error\nwrong_extention_must_be_.ber");
	if (argv[1][++i] != '\0')
		free_everything(data, "Error\nwrong_extention_must_be_.ber");
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	check_map_name(argc, argv, &data);
	some_setup_and_call_parsing(&data, argv);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		free_everything(&data, "Error\nproblem_when_creatin_g_mlx_ptr");
	data.is_mlx = 1;
	data.win_ptr = mlx_new_window
		(data.mlx_ptr, data.size_x_window, data.size_y_window, "SO_LONG");
	if (!data.win_ptr)
		free_everything(&data, "Error\nproblem_when_creating_mlx_win");
	data.is_window = 1;
	setup_img_ptrs(&data);
	data.is_img = 1;
	mlx_expose_hook(data.win_ptr, print_basic_map, &data);
	mlx_loop_hook(data.mlx_ptr, update_sprite, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, close_cross, &data);
	mlx_loop(data.mlx_ptr);
}

//TODO LIST
//
//
//TODO BONUS LIST
//
//
