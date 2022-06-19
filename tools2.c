/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:52:41 by aainhaja          #+#    #+#             */
/*   Updated: 2022/06/19 16:58:53 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char	**map)
{
	return (ft_strlen(map[0]));
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	cases(int y, int x, t_vars	vars)
{
	if (vars.map[y][x] == '1')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.wal_tex);
	else if (vars.map[y][x] == '0')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.flo_tex);
	else if (vars.map[y][x] == 'E')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.exi_tex);
	else if (vars.map[y][x] == 'C')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.col_tex);
	else if (vars.map[y][x] == 'P')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.pla_tex);
}

int	rec(t_vars vars)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(vars.map[0]);
	while (vars.map[j])
		j++;
	if (i <= j)
		return (-1);
	return (0);
}
