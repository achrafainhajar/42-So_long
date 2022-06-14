/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:27:35 by aainhaja          #+#    #+#             */
/*   Updated: 2022/06/14 22:39:12 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	enemynorm(t_vars *vars)
{
	if (vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != 'C'
		&& vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != 'E'
		&& vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != '1')
	{
		vars->map[vars->player.pos_y + 1][vars->enemy.pos_x] = 'K';
		vars->map[vars->player.pos_y + 1][vars->enemy.pos_x] = '0';
	}
	else if (vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != 'C' &&
		vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != 'E'
		&& vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != '1')
	{
		vars->map[vars->player.pos_y - 1][vars->enemy.pos_x] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
}

void	enemy(t_vars *vars)
{
	if (vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != 'C'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != 'E'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != '1')
	{
		vars->map[vars->player.pos_y][vars->enemy.pos_x + 1] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
	else if (vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != 'C'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != 'E'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != '1')
	{
		vars->map[vars->player.pos_y][vars->enemy.pos_x - 1] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
	else
		enemynorm(vars);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	t_vars	vars;

	fd = open(argv[1], O_RDONLY);
	str = matrix(fd);
	vars.map = ft_split(str, '\n');
	if ((argc != 2) || schecker(vars, str) != 0 || invalidfile(argv[1]) != 0)
	{
		printf("Error\n");
		exit(1);
	}
	vars.height = get_height(vars.map);
	vars.width = get_width(vars.map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * TILESIZE,
			vars.height * TILESIZE, "Helwwlo world!");
	vars.win_img.img = mlx_new_image(vars.mlx, vars.width * TILESIZE,
			vars.height * TILESIZE);
	vars.win_img.addr = mlx_get_data_addr(vars.win_img.img,
			&vars.win_img.bits_per_pixel, &vars.win_img.line_length,
			&vars.win_img.endian);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}
