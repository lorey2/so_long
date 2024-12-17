/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:40:37 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 19:21:07 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_write_upgrade(t_mlx_data *data)
{
	if (data->big_tab[data->player_y / CASE_SIZE]
		[data->player_x / CASE_SIZE] != 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img3, data->player_x, data->player_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.player, data->next_case_x, data->next_case_y);
	data->big_tab[data->next_case_y / CASE_SIZE]
	[data->next_case_x / CASE_SIZE] = 'P';
	if (data->big_tab[data->player_y / CASE_SIZE]
		[data->player_x / CASE_SIZE] != 'M')
		data->big_tab[data->player_y / CASE_SIZE]
		[data->player_x / CASE_SIZE] = '0';
	data->player_x = data->next_case_x;
	data->player_y = data->next_case_y;
}

static void	update_counter(t_mlx_data *data)
{
	size_t	i;
	char	*number;

	i = -1;
	while (++i < ft_strlen(data->big_tab[0]))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img2, i * CASE_SIZE, 0);
	data->move_count++;
	number = ft_itoa(data->move_count);
	if (!number)
		free_everything(data, "Error\nmalloc_error");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 20, 0x00FF0000, number);
	free(number);
}

static void	move_player(t_mlx_data *data)
{
	char	next_case;

	next_case = data->big_tab[data->next_case_y / CASE_SIZE]
	[data->next_case_x / CASE_SIZE];
	if (next_case == 'M')
		free_everything(data, "YOU DIED");
	if (next_case == '0')
	{
		move_write_upgrade(data);
		update_counter(data);
	}
	if (next_case == 'C')
	{
		data->n_coins_collected++;
		move_write_upgrade(data);
		update_counter(data);
	}
	if (next_case == 'E' && data->n_coins_collected == data->n_coins_to_collect)
		free_everything(data, NULL);
}

static void	handle_input_arrow_key(int keysym, t_mlx_data *data)
{
	if (keysym == XK_w)
	{
		data->next_case_y = data->player_y - CASE_SIZE;
		data->next_case_x = data->player_x;
		move_player(data);
	}
	if (keysym == XK_s)
	{
		data->next_case_y = data->player_y + CASE_SIZE;
		data->next_case_x = data->player_x;
		move_player(data);
	}
	if (keysym == XK_d)
	{
		data->next_case_y = data->player_y;
		data->next_case_x = data->player_x + CASE_SIZE;
		move_player(data);
	}
	if (keysym == XK_a)
	{
		data->next_case_y = data->player_y;
		data->next_case_x = data->player_x - CASE_SIZE;
		move_player(data);
	}
}

int	handle_input(int keysym, t_mlx_data *data)
{
	move_ennemy(data, keysym);
	handle_input_arrow_key(keysym, data);
	if (data->n_coins_to_collect == data->n_coins_collected
		&& data->is_finished == 0)
	{
		data->is_finished = 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.opendoor, data->exit_x, data->exit_y);
	}
	if (keysym == XK_Escape)
		free_everything(data, NULL);
	return (0);
}
