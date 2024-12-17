/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_map_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:31:01 by lorey             #+#    #+#             */
/*   Updated: 2024/11/15 16:15:42 by SET YOUR USER    ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

static void	check_border_and_set_widows_size(t_mlx_data *data)
{
	int	last_line;
	int	line_size;
	int	i;

	i = -1;
	last_line = 0;
	while (data->big_tab[last_line])
		last_line++;
	line_size = ft_strlen(data->big_tab[0]);
	while (++i < line_size - 1)
		if (data->big_tab[0][i] != '1' ||
			data->big_tab[last_line - 1][i] != '1')
			free_everything(data, "Error\ntop_bottom_border_are_not_wall");
	i = -1;
	while (++i < last_line)
		if (data->big_tab[i][0] != '1'
			|| data->big_tab[i][line_size - 2] != '1')
			free_everything(data, "Error\nleft_right_border_are_not_wall");
	data->size_x_window = (ft_strlen(data->big_tab[0]) - 1) * CASE_SIZE;
	data->size_y_window = last_line * CASE_SIZE;
}

static int	set_player_pos_count_coin_check_other_chars(t_mlx_data *data,
	int i, int *exit_nbr, int *player_nbr)
{
	data->j = 0;
	while (data->big_tab[i] && data->big_tab[i][++(data->j)] != '\0'
		&& data->big_tab[i][data->j] != '\n')
	{
		if (data->big_tab[i][data->j] == 'P')
		{
			(*player_nbr)++;
			data->player_x = data->j * CASE_SIZE;
			data->player_y = i * CASE_SIZE;
		}
		if (data->big_tab[i][data->j] == 'C')
			data->n_coins_to_collect++;
		if (data->big_tab[i][data->j] == 'E')
		{
			data->exit_x = data->j * CASE_SIZE;
			data->exit_y = i * CASE_SIZE;
			(*exit_nbr)++;
		}
		if (data->big_tab[i][data->j] != '1' && data->big_tab[i][data->j]
			!= '0' && data->big_tab[i][data->j] != 'P' && data->big_tab[i]
			[data->j] != 'C' && data->big_tab[i][data->j] != 'E'
			&& data->big_tab[i][data->j] != 'M')
			return (1);
	}
	return (0);
}

void	checks(t_mlx_data *data, int problem2, int pl_nbr, int ex_nbr)
{
	if (problem2)
		free_everything(data,
			"Error\nmap_can_only_contain_(1P0CEM) or map must be squared");
	if (ex_nbr != 1)
		free_everything(data, "Error \nmap_has_to_have_one_exit");
	if (pl_nbr != 1)
		free_everything(data, "Error \nmap_has_to_have_one_player");
	if (data->n_coins_to_collect <= 0)
		free_everything(data, "Error\nmaps_has_to_have_at_least_one_coin");
	check_border_and_set_widows_size(data);
}

void	setup_var(int *pl_nbr, int *ex_nbr, int *problem, int *problem2)
{
	*problem = 0;
	*problem2 = 0;
	*pl_nbr = 0;
	*ex_nbr = 0;
}

void	parsing(t_mlx_data *data, char **argv)
{
	int	fd;
	int	i;
	int	ex_nbr;
	int	pl_nbr;
	int	problem[2];

	setup_var(&pl_nbr, &ex_nbr, &problem[0], &problem[1]);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_everything(data, "Error \ncannot_open_file");
	while (++i < 50)
	{
		data->big_tab[i] = get_next_line(fd);
		problem[0] = set_player_pos_count_coin_check_other_chars(
				data, i, &ex_nbr, &pl_nbr);
		if (i > 0 && data->big_tab[i]
			&& ft_strlen(data->big_tab[i]) != ft_strlen(data->big_tab[i - 1]))
			problem[0] = 1;
		if (problem[0])
			problem[1] = 1;
	}
	data->is_big_tab = 1;
	checks(data, problem[1], pl_nbr, ex_nbr);
}
