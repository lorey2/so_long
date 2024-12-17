/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:35:47 by lorey             #+#    #+#             */
/*   Updated: 2024/11/12 16:22:45 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	write_pictures(int i, int j, t_mlx_data *data)
{
	if (data->big_tab[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img2, j * CASE_SIZE, i * CASE_SIZE);
	if (data->big_tab[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img3, j * CASE_SIZE, i * CASE_SIZE);
	if (data->big_tab[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player, j * CASE_SIZE, i * CASE_SIZE);
	if (data->big_tab[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.door, j * CASE_SIZE, i * CASE_SIZE);
	if (data->big_tab[i][j] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.monster, j * CASE_SIZE, i * CASE_SIZE);
}

int	print_basic_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->big_tab[i])
	{
		j = 0;
		while (data->big_tab[i][j])
		{
			write_pictures(i, j, data);
			j++;
		}
		i++;
	}
	return (0);
}
