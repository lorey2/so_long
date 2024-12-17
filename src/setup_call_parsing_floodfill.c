/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_call_parsing_floodfill.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:36:28 by lorey             #+#    #+#             */
/*   Updated: 2024/11/15 17:18:22 by SET YOUR USER    ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//to put after = 'X' l 31
//	while (big_tab_cpy[++i])
//		write(1, big_tab_cpy[i], ft_strlen(big_tab_cpy[1]));

static void	floodfill(t_mlx_data *data, char *big_tab_cpy[50], int x, int y)
{
	if (big_tab_cpy[x][y] == 'C')
		data->n_coins_fullfill++;
	if (big_tab_cpy[x][y] == 'E')
		data->n_door_fullfill++;
	big_tab_cpy[x][y] = 'X';
	if (big_tab_cpy[x + 1][y] != 'X' && big_tab_cpy[x + 1][y] != '1')
		floodfill(data, big_tab_cpy, x + 1, y);
	if (big_tab_cpy[x - 1][y] != 'X' && big_tab_cpy[x - 1][y] != '1')
		floodfill(data, big_tab_cpy, x - 1, y);
	if (big_tab_cpy[x][y + 1] != 'X' && big_tab_cpy[x][y + 1] != '1')
		floodfill(data, big_tab_cpy, x, y + 1);
	if (big_tab_cpy[x][y - 1] != 'X' && big_tab_cpy[x][y - 1] != '1')
		floodfill(data, big_tab_cpy, x, y - 1);
}

void	some_setup_and_call_parsing(t_mlx_data *data, char **argv)
{
	int			i;
	char		*big_tab_cpy[50];

	i = -1;
	gettimeofday(&data->milis_start, NULL);
	data->n_coins_to_collect = 0;
	data->n_coins_collected = 0;
	data->pos_next_coin_x = 0;
	data->pos_next_coin_y = 0;
	data->img.coin_state = 1;
	data->n_coins_fullfill = 0;
	data->n_door_fullfill = 0;
	parsing(data, argv);
	while (data->big_tab[++i])
		big_tab_cpy[i] = ft_strdup(data->big_tab[i]);
	floodfill(data, big_tab_cpy,
		data->player_y / CASE_SIZE, data->player_x / CASE_SIZE);
	i = -1;
	while (data->big_tab[++i])
		free(big_tab_cpy[i]);
	if (data->n_coins_fullfill != data->n_coins_to_collect
		|| data->n_door_fullfill != 1)
		free_everything(data, "Error\ncoin_and_exit_must_be_accessible");
}
