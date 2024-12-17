/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:05:45 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 19:08:18 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_next_ennemy(t_mlx_data *data)
{
	int	line_size;

	line_size = ft_strlen(data->big_tab[0]);
	while (data->big_tab[data->pos_next_en_y])
	{
		while (data->pos_next_en_x < line_size)
		{
			if (data->big_tab[data->pos_next_en_y]
				[data->pos_next_en_x] == 'M')
				return (1);
			data->pos_next_en_x++;
		}
		data->pos_next_en_y++;
		data->pos_next_en_x = 0;
	}
	return (0);
}

void	write_next_en_pos(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.monster,
		data->next_en_x * CASE_SIZE, data->next_en_y * CASE_SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img3,
		data->pos_next_en_x * CASE_SIZE, data->pos_next_en_y * CASE_SIZE);
}

void	update_next_ennemy_pos(t_mlx_data *data)
{
	if (data->img.ennemy_state == 1)
	{
		data->next_en_x = data->pos_next_en_x + 1;
		data->next_en_y = data->pos_next_en_y;
		data->big_tab[data->pos_next_en_y][data->pos_next_en_x] = '0';
		data->big_tab[data->next_en_y][data->next_en_x] = 'E';
	}
	if (data->img.ennemy_state == 2)
	{
		data->next_en_x = data->pos_next_en_x - 1;
		data->next_en_y = data->pos_next_en_y;
	}
	data->big_tab[data->pos_next_en_y][data->pos_next_en_x] = '0';
	data->big_tab[data->next_en_y][data->next_en_x] = 'M';
	write_next_en_pos(data);
}

void	move_ennemy(t_mlx_data *data, int keysym)
{
	int	is_ennemy;

	is_ennemy = 0;
	if (keysym == XK_w || keysym == XK_a
		|| keysym == XK_s || keysym == XK_d)
	{
		data->pos_next_en_x = 0;
		data->pos_next_en_y = 0;
		while (get_next_ennemy(data))
		{
			is_ennemy = 1;
			update_next_ennemy_pos(data);
			if (data->pos_next_en_x >= (int)ft_strlen(data->big_tab[0]))
				data->pos_next_en_y ++;
			else
				data->pos_next_en_x += 2;
		}
		if (is_ennemy)
			data->img.ennemy_state = (data->img.ennemy_state % 2) + 1;
	}
}
