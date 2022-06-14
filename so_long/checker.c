/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:02:08 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/29 18:23:45 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfl(t_vars vars)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (!vars.map)
		return (-1);
	while (vars.map[0][j])
	{
		if (vars.map[0][j] != '1')
			return (-1);
		j++;
	}
	while (vars.map[i + 1])
		i++;
	j = 0;
	while (vars.map[i][j])
	{
		if (vars.map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	checkback(char *str, t_vars vars)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i - 1] != '1' || str[i + 1] != '1')
				return (-1);
			k++;
		}
		i++;
	}
	i = 0;
	while (vars.map[i])
		i++;
	if (i - 1 != k)
		return (-1);
	return (0);
}

int	invalidfile(char *str)
{
	int	i;

	i = 0;
	i = ft_strlen(str) - 1;
	if (str[i--] != 'r')
		return (-1);
	if (str[i--] != 'e')
		return (-1);
	if (str[i--] != 'b')
		return (-1);
	if (str[i--] != '.')
		return (-1);
	return (0);
}

int	checkexist(char *str, t_vars vars)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (rec(vars))
		return (-1);
	if (strchr(str, '0') == NULL || strchr(str, 'C') == NULL
		|| strchr(str, 'E') == 0 || strchr(str, 'P') == 0)
		return (-1);
	l = ft_strlen(vars.map[0]);
	while (vars.map[i])
	{
		if (ft_strlen(vars.map[i]) != l)
			return (-1);
		if (vars.map[i][0] != '1' && vars.map[i][l - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	schecker(t_vars	vars, char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	if (checkfl(vars) != 0 || checkexist(str, vars) || checkback(str, vars))
		return (-1);
	while (vars.map[++i])
	{
		j = 0;
		while (vars.map[i][j])
		{
			if (vars.map[i][j] != 'C' &&
				vars.map[i][j] != 'P' && vars.map[i][j] != 'E'
					&& vars.map[i][j] != '1' && vars.map[i][j] != '0')
				return (-1);
			if (vars.map[i][j] == 'P')
				k++;
			j++;
		}
	}
	if (k != 1)
		return (-1);
	return (0);
}
