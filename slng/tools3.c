/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:53:59 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/13 19:02:14 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	checkside3(t_vars	*vars)
{
	if (vars->player.d == 1)
	{
		if (vars->map[vars->player.pos_y][vars->player.pos_x + 1] != '1')
		{
			if (vars->player.coin == 0 && vars->map[vars->player.pos_y]
				[vars->player.pos_x + 1] == 'E')
				exit(0);
			else if (vars->map[vars->player.pos_y]
				[vars->player.pos_x + 1] != 'E')
			{
				vars->map[vars->player.pos_y][vars->player.pos_x + 1] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
}

void	checkside2(t_vars *vars)
{
	if (vars->player.a == 1)
	{
		if (vars->map[vars->player.pos_y][vars->player.pos_x - 1] != '1')
		{
			if (vars->player.coin == 0 && vars->map[vars->player.pos_y]
				[vars->player.pos_x - 1] == 'E')
				exit(0);
			else if (vars->map[vars->player.pos_y]
				[vars->player.pos_x - 1] != 'E')
			{
				vars->map[vars->player.pos_y][vars->player.pos_x - 1] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else
	{
		checkside3(vars);
	}
}

void	checkside1(t_vars *vars)
{
	if (vars->player.w == 1)
	{
		if (vars->map[vars->player.pos_y - 1][vars->player.pos_x] != '1')
		{
			if (vars->player.coin == 0
				&& vars->map[vars->player.pos_y - 1][vars->player.pos_x] == 'E')
				exit(0);
			else if (vars->map[vars->player.pos_y - 1]
				[vars->player.pos_x] != 'E')
			{
				vars->map[vars->player.pos_y - 1][vars->player.pos_x] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else
	{
		checkside2(vars);
	}
}

int	check_side(t_vars *vars)
{
	if (vars->player.s == 1)
	{
		if (vars->map[vars->player.pos_y + 1]
			[vars->player.pos_x] != '1')
		{
			if (vars->player.coin == 0
				&& vars->map[vars->player.pos_y + 1][vars->player.pos_x] == 'E')
				exit(0);
			else if (vars->map[vars->player.pos_y + 1]
				[vars->player.pos_x] != 'E')
			{
				vars->map[vars->player.pos_y + 1][vars->player.pos_x] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else
	{
		checkside1(vars);
	}
	return (0);
}
