/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:54 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 18:59:58 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_next_coin(t_mlx_data *data)
{
	int	line_size;

	line_size = ft_strlen(data->big_tab[0]);
	while (data->big_tab[data->pos_next_coin_y])
	{
		while (data->pos_next_coin_x < line_size)
		{
			if (data->big_tab[data->pos_next_coin_y]
				[data->pos_next_coin_x] == 'C')
				return (1);
			data->pos_next_coin_x++;
		}
		data->pos_next_coin_y++;
		data->pos_next_coin_x = 0;
	}
	return (0);
}

static void	if_for_coin123(t_mlx_data *data)
{
	if (data->img.coin_state == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin1,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
	else if (data->img.coin_state == 2)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin2,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
	else if (data->img.coin_state == 3)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin3,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
}

static void	if_for_coin456(t_mlx_data *data)
{
	if (data->img.coin_state == 4)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin4,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
	else if (data->img.coin_state == 5)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin5,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
	else if (data->img.coin_state == 6)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.coin6,
			data->pos_next_coin_x * CASE_SIZE,
			data->pos_next_coin_y * CASE_SIZE);
}

int	update_sprite(t_mlx_data *data)
{
	int	is_coin;

	is_coin = 0;
	gettimeofday(&data->milis_now, NULL);
	if (time_diff(data) > 200)
	{
		data->milis_start.tv_sec = data->milis_now.tv_sec;
		data->milis_start.tv_usec = data->milis_now.tv_usec;
		data->pos_next_coin_x = 0;
		data->pos_next_coin_y = 0;
		while (get_next_coin(data))
		{
			is_coin = 1;
			if_for_coin123(data);
			if_for_coin456(data);
			if (data->pos_next_coin_x == (int)ft_strlen(data->big_tab[0]))
				data->pos_next_coin_y++;
			else
				data->pos_next_coin_x++;
		}
		if (is_coin)
			data->img.coin_state = (data->img.coin_state % 6) + 1;
	}
	return (0);
}
