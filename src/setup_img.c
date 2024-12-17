/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:59:48 by lorey             #+#    #+#             */
/*   Updated: 2024/11/13 19:22:37 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_part_2(t_mlx_data *data)
{
	int	fifty;

	fifty = 50;
	data->img.img2 = mlx_xpm_file_to_image(
			data->mlx_ptr, "./img/wall.xpm", &fifty, &fifty);
	data->img.img3 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/floor.xpm", &fifty, &fifty);
	data->img.door = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/door.xpm", &fifty, &fifty);
	data->img.opendoor = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/opendoor.xpm", &fifty, &fifty);
	data->img.player = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/player.xpm", &fifty, &fifty);
	data->img.monster = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/ennemy.xpm", &fifty, &fifty);
}

void	setup_img_ptrs(t_mlx_data *data)
{
	int	fifty;

	fifty = 50;
	img_part_2(data);
	data->img.coin1 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin1.xpm", &fifty, &fifty);
	data->img.coin2 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin2.xpm", &fifty, &fifty);
	data->img.coin3 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin3.xpm", &fifty, &fifty);
	data->img.coin4 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin4.xpm", &fifty, &fifty);
	data->img.coin5 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin5.xpm", &fifty, &fifty);
	data->img.coin6 = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/coin6.xpm", &fifty, &fifty);
	if (!data->img.player || !data->img.door
		|| !data->img.img3 || !data->img.img2
		|| !data->img.coin1 ||!data->img.coin2
		|| !data->img.coin3 ||!data->img.coin4
		|| !data->img.coin5 ||!data->img.coin6
		|| !data->img.opendoor)
		free_everything(data, "Error\ncreating_img_pointer_check_file_name");
}
