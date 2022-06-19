/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:59:39 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/13 18:55:19 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_vars	*vars)
{
	int	w;
	int	h;

	vars->col_tex.img = (unsigned int *)
		mlx_xpm_file_to_image(vars->mlx, "textures/col.xpm", &w, &h);
	vars->col_tex.addr = (unsigned int *)
		mlx_get_data_addr(vars->col_tex.img, &vars->col_tex.bits_per_pixel,
			&vars->col_tex.line_length, &vars->col_tex.endian);
	vars->flo_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx,
			"textures/floor.xpm", &w, &h);
	vars->flo_tex.addr = (unsigned int *)
		mlx_get_data_addr(vars->flo_tex.img, &vars->flo_tex.bits_per_pixel,
			&vars->flo_tex.line_length, &vars->flo_tex.endian);
	vars->pla_tex.img = (unsigned int *) mlx_xpm_file_to_image(vars->mlx,
			"textures/player.xpm", &w, &h);
	vars->pla_tex.addr = (unsigned int *)
		mlx_get_data_addr(vars->pla_tex.img, &vars->pla_tex.bits_per_pixel,
			&vars->pla_tex.line_length, &vars->pla_tex.endian);
	norm32(vars, w, h);
}

void	drawfloor(t_vars	vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars.height)
	{
		x = 0;
		while (x < vars.width)
		{
			if (vars.map[y][x] != '0' && vars.map[y][x] != '1')
				draw(y * TILESIZE, x * TILESIZE, vars, vars.flo_tex);
			x++;
		}
		y++;
	}
}

void	pixelb(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars.height)
	{
		x = 0;
		while (x < vars.width)
		{
			cases(y, x, vars);
			x++;
		}
		y++;
	}
}

void	norm32(t_vars *vars, int w, int h)
{
	vars->exi_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx,
			"textures/exit.xpm", &w, &h);
	vars->exi_tex.addr = (unsigned int *)
		mlx_get_data_addr(vars->exi_tex.img, &vars->exi_tex.bits_per_pixel,
			&vars->exi_tex.line_length, &vars->exi_tex.endian);
	vars->wal_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx,
			"textures/grass.xpm", &w, &h);
	vars->wal_tex.addr = (unsigned int *)
		mlx_get_data_addr(vars->wal_tex.img, &vars->wal_tex.bits_per_pixel,
			&vars->wal_tex.line_length, &vars->wal_tex.endian);
	vars->ene_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx,
			"textures/enemy.xpm", &w, &h);
	vars->ene_tex.addr = (unsigned int *) mlx_get_data_addr(vars->ene_tex.img,
			&vars->ene_tex.bits_per_pixel,
			&vars->ene_tex.line_length, &vars->ene_tex.endian);
}

void	draw(int y, int x, t_vars vars, t_texture tex)
{
	int	j;
	int	i;
	int	tex_pixel_pos;

	j = y;
	while (j < y + TILESIZE)
	{
		i = x;
		while (i < x + TILESIZE)
		{
			tex_pixel_pos = (((j - y) * TILESIZE) + (i - x));
			my_mlx_pixel_put(&vars.win_img, i, j, tex.addr[tex_pixel_pos]);
			i++;
		}
		j++;
	}
}
