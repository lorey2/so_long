/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:28:45 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 18:35:38 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image(t_mlx_data *data)
{
	if (data->is_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.coin1);
		mlx_destroy_image(data->mlx_ptr, data->img.coin2);
		mlx_destroy_image(data->mlx_ptr, data->img.coin3);
		mlx_destroy_image(data->mlx_ptr, data->img.coin4);
		mlx_destroy_image(data->mlx_ptr, data->img.coin5);
		mlx_destroy_image(data->mlx_ptr, data->img.coin6);
		mlx_destroy_image(data->mlx_ptr, data->img.door);
		mlx_destroy_image(data->mlx_ptr, data->img.img2);
		mlx_destroy_image(data->mlx_ptr, data->img.img3);
		mlx_destroy_image(data->mlx_ptr, data->img.player);
		mlx_destroy_image(data->mlx_ptr, data->img.opendoor);
		mlx_destroy_image(data->mlx_ptr, data->img.monster);
	}
}

void	free_win_mlx(t_mlx_data *data)
{
	if (data->is_window)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->is_mlx)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

int	free_everything(t_mlx_data *data, char *error_message)
{
	int	i;

	i = -1;
	destroy_image(data);
	if (data->is_big_tab)
	{
		while (++i < 50)
			if (data->big_tab[i])
				free(data->big_tab[i]);
	}
	free_win_mlx(data);
	if (error_message)
	{
		i = write(1, error_message, ft_strlen(error_message));
		exit(1);
	}
	if (i < 0)
		exit(1);
	exit(0);
}
