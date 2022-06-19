/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:53:59 by aainhaja          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:11 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	checkside3(t_vars	*vars)
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
				return (1);
			}
		}
	}
	return (0);
}

int	checkside2(t_vars *vars)
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
				return (1);
			}
		}
	}
	return (checkside3(vars));
}

int	checkside1(t_vars *vars)
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
				return (1);
			}
		}
	}
	return (checkside2(vars));
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
				return (1);
			}
		}
	}
	return (checkside1(vars));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
	{
		n = n + 48;
		write(1, &n, 1);
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		ft_putnbr(n *= -1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
