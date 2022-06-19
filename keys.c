/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:56:37 by aainhaja          #+#    #+#             */
/*   Updated: 2022/06/19 17:02:05 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void)
{
	exit(0);
}

int	update(t_vars *vars)
{
	get_pos(vars);
	get_textures(vars);
	drawfloor(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->win_img.img, 0, 0);
	pixelb(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->win_img.img, 0, 0);
	mlx_hook(vars->win, 2, 0, key_press, vars);
	if (check_side(vars) == 1)
	{
		vars->count++;
		ft_putnbr(vars->count);
		write(1, "\n", 1);
	}
	ft_clean(vars);
	mlx_hook(vars->win, 17, 1L << 0, quit, &vars);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == S_KEY)
		vars->player.s = 1;
	else if (keycode == A_KEY)
		vars->player.a = 1;
	else if (keycode == W_KEY)
		vars->player.w = 1;
	else if (keycode == D_KEY)
		vars->player.d = 1;
	else if (keycode == 53)
		quit();
	else
		return (-1);
	return (0);
}

int	key_rel(int keycode, t_vars *vars)
{
	if (keycode == S_KEY)
		vars->player.s = 0;
	else if (keycode == A_KEY)
		vars->player.a = 0;
	else if (keycode == W_KEY)
		vars->player.w = 0;
	else if (keycode == D_KEY)
		vars->player.d = 0;
	return (0);
}

void	ft_clean(t_vars *vars)
{
		vars->player.s = 0;
		vars->player.a = 0;
		vars->player.w = 0;
		vars->player.d = 0;
}
