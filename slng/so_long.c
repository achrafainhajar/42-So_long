/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:27:35 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/10 20:13:32 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include "get_next_line.h"

#include <string.h>

void get_pos(t_vars *vars)
{
	int i;
	int j;

	vars->player.coin = 0;
	i = 0;
	while(vars->map[i])
	{
		j = 0;
		while(vars->map[i][j])
		{
			if(vars->map[i][j] == 'P')
			{
				vars->player.pos_x = j;
				vars->player.pos_y = i;
			}
			else if(vars->map[i][j] == 'K')
			{
				vars->enemy.pos_x = j;
				vars->enemy.pos_y = i;
			}
			else if(vars->map[i][j] == 'C')
				vars->player.coin++;
			j++;
		}		
		i++;
	}
}
char	**ft_splitcpy(const char *s, char c, char **str, int alloc)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[cnt][j] = s[i];
			i++;
			j++;
		}
		if (cnt < alloc)
			str[cnt][j] = '\0';
		cnt++;
	}
	if (i != 0 && s[i - 1] == c)
		cnt--;
	str[cnt] = NULL;
	return (str);
}

char	**ft_charcount(const char *s, char c, char **str, int alloc)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (cnt < alloc)
			str[cnt] = malloc(sizeof(char) * j + 1);
		if (str == NULL)
			return (0);
		j = 0;
		cnt++;
	}
	return (ft_splitcpy(s, c, str, alloc));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	**str;

	if (!s)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	str = malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (0);
	return (ft_charcount(s, c, str, cnt));
}


char *matrix(int fd)
{
	char *str;
	char *sret;

	sret = NULL;
	str = get_next_line(fd);
	while(str)
	{
		sret = ft_strjoin(sret, str);
		str = get_next_line(fd);
	}
	return(sret);
}


int	get_width(char **map)
{
	return(strlen(map[0]));
}
int get_height(char **map)
{
	int i;


	i = 0;
	while(map[i])
		i++;
	return(i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	//data->addr[(y * data->line_length) + x] = (char )color;
}

void	draw(int y,int x,t_vars vars, t_texture tex)
{
	int j;
	int i;
	int tex_pixel_pos;

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

void cases(int y, int x, t_vars vars)
{
	if(vars.map[y][x] == '1')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.wal_tex);
	else if(vars.map[y][x] == '0')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.flo_tex);
	else if(vars.map[y][x] == 'E')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.exi_tex);
	else if(vars.map[y][x] == 'C')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.col_tex);
	else if(vars.map[y][x] == 'P')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.pla_tex);
	else if(vars.map[y][x] == 'K')
		draw(y * TILESIZE, x * TILESIZE, vars, vars.ene_tex);
}

void	drawfloor(t_vars vars)
{
	int x;
	int y;

	y = 0;
	while (y <  vars.height)
	{

		x = 0;
		while(x < vars.width)
		{
			if(vars.map[y][x] != '0' && vars.map[y][x] != '1')
				draw(y * TILESIZE, x * TILESIZE, vars, vars.flo_tex);
			x++;
		}
		y++;
	}
}

void	pixelb(t_vars vars)
{
	int x;
	int y;

	y = 0;
	while (y <  vars.height)
	{

		x = 0;
		while(x < vars.width)
		{
			cases(y,x,vars);
			x++;
		}
		y++;
	}
}

void get_textures(t_vars *vars)
{


	int w;
	int h;

	vars->col_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/col.xpm", &w, &h);
	vars->col_tex.addr =(unsigned int *) mlx_get_data_addr(vars->col_tex.img,&vars->col_tex.bits_per_pixel,&vars->col_tex.line_length,&vars->col_tex.endian);
	vars->flo_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/floor.xpm", &w, &h);
	vars->flo_tex.addr =(unsigned int *) mlx_get_data_addr(vars->flo_tex.img,&vars->flo_tex.bits_per_pixel,&vars->flo_tex.line_length,&vars->flo_tex.endian);
	vars->pla_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm", &w, &h);
	vars->pla_tex.addr =(unsigned int *) mlx_get_data_addr(vars->pla_tex.img,&vars->pla_tex.bits_per_pixel,&vars->pla_tex.line_length,&vars->pla_tex.endian);
	vars->exi_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm", &w, &h);
	vars->exi_tex.addr =(unsigned int *) mlx_get_data_addr(vars->exi_tex.img,&vars->exi_tex.bits_per_pixel,&vars->exi_tex.line_length,&vars->exi_tex.endian);
	vars->wal_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/grass.xpm", &w, &h);
	vars->wal_tex.addr =(unsigned int *) mlx_get_data_addr(vars->wal_tex.img,&vars->wal_tex.bits_per_pixel,&vars->wal_tex.line_length,&vars->wal_tex.endian);
	vars->ene_tex.img = (unsigned int *)mlx_xpm_file_to_image(vars->mlx, "textures/enemy.xpm", &w, &h);
	vars->ene_tex.addr =(unsigned int *) mlx_get_data_addr(vars->ene_tex.img,&vars->ene_tex.bits_per_pixel,&vars->ene_tex.line_length,&vars->ene_tex.endian);
}
int check_side(t_vars *vars)
{
	if(vars->player.S == 1)
	{
		if(vars->map[vars->player.pos_y + 1][vars->player.pos_x] != '1')
		{
			if(vars->player.coin == 0 && vars->map[vars->player.pos_y + 1][vars->player.pos_x] == 'E')
				exit(0);
			else if(vars->map[vars->player.pos_y + 1][vars->player.pos_x] != 'E')
			{
				vars->map[vars->player.pos_y + 1][vars->player.pos_x] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else if(vars->player.W == 1)
	{
		if(vars->map[vars->player.pos_y - 1][vars->player.pos_x] != '1')
		{
			if(vars->player.coin == 0 && vars->map[vars->player.pos_y - 1][vars->player.pos_x] == 'E')
				exit(0);
			else if(vars->map[vars->player.pos_y - 1][vars->player.pos_x] != 'E')
			{
				vars->map[vars->player.pos_y - 1][vars->player.pos_x] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else if(vars->player.A == 1)
	{
		if(vars->map[vars->player.pos_y][vars->player.pos_x - 1] != '1')
		{
			if(vars->player.coin == 0 && vars->map[vars->player.pos_y][vars->player.pos_x - 1] == 'E')
				exit(0);
			else if(vars->map[vars->player.pos_y][vars->player.pos_x - 1] != 'E')
			{
				vars->map[vars->player.pos_y][vars->player.pos_x - 1] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	else if(vars->player.D == 1)
	{
		if(vars->map[vars->player.pos_y][vars->player.pos_x + 1] != '1')
		{
			if(vars->player.coin == 0 && vars->map[vars->player.pos_y][vars->player.pos_x + 1] == 'E')
				exit(0);
			else if(vars->map[vars->player.pos_y][vars->player.pos_x + 1] != 'E')
			{
				vars->map[vars->player.pos_y][vars->player.pos_x + 1] = 'P';
				vars->map[vars->player.pos_y][vars->player.pos_x] = '0';
			}
		}
	}
	return(0);
}
void enemy(t_vars *vars)
{
	if(vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != 'C' && vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != 'E'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x + 1] != '1')
	{
		vars->map[vars->player.pos_y][vars->enemy.pos_x + 1] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
	else if(vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != 'C' && vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != 'E'
		&& vars->map[vars->enemy.pos_y][vars->enemy.pos_x - 1] != '1')
	{
		vars->map[vars->player.pos_y][vars->enemy.pos_x - 1] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
	else if(vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != 'C' && vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != 'E'
		&& vars->map[vars->enemy.pos_y + 1][vars->enemy.pos_x] != '1')
	{
		vars->map[vars->player.pos_y + 1][vars->enemy.pos_x] = 'K';
		vars->map[vars->player.pos_y + 1][vars->enemy.pos_x] = '0';
	}
	else if(vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != 'C' && vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != 'E'
		&& vars->map[vars->enemy.pos_y - 1][vars->enemy.pos_x] != '1')
	{
		vars->map[vars->player.pos_y - 1][vars->enemy.pos_x] = 'K';
		vars->map[vars->player.pos_y][vars->enemy.pos_x] = '0';
	}
}
int	key_press(int keycode,t_vars *vars)
{
	if(keycode == S_KEY)
		vars->player.S = 1;
	else if(keycode == A_KEY)
		vars->player.A = 1;
	else if(keycode == W_KEY)
		vars->player.W = 1;
	else if(keycode == D_KEY)
		vars->player.D = 1;
		return(0);
}
int	quit(void)
{
	exit(0);
	return (0);
}
int	key_rel(int keycode,t_vars *vars)
{
		if(keycode == S_KEY)
			vars->player.S = 0;
		else if(keycode == A_KEY)
			vars->player.D = 0;
		else if(keycode == W_KEY)
			vars->player.W = 0;
		else if(keycode == D_KEY)
			vars->player.D = 0;

		return(0);
}
void ft_clean(t_vars *vars)
{
		vars->player.S = 0;
		vars->player.A = 0;
		vars->player.W = 0;
		vars->player.D = 0;
}
int update(t_vars *vars)
{
	get_pos(vars);
	get_textures(vars);
	drawfloor(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->win_img.img, 0, 0);
	pixelb(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->win_img.img, 0, 0);
	mlx_hook(vars->win,2,0,key_press,vars);
	check_side(vars);
	ft_clean(vars);
	return(0);
}

int main()
{
	char	*str;
    int		fd;
	t_vars	vars;

	fd = open("map.ber", O_RDONLY);
	str = matrix(fd);
	vars.map = ft_split(str, '\n');
	if (schecker(vars, str) != 0)
		printf("ss");
	vars.height = get_height(vars.map);
	vars.width = get_width(vars.map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * TILESIZE,
	vars.height * TILESIZE, "Helwwlo world!");
	vars.win_img.img = mlx_new_image(vars.mlx, vars.width * TILESIZE,
										vars.height * TILESIZE);
	vars.win_img.addr = mlx_get_data_addr(vars.win_img.img, &vars.win_img.bits_per_pixel, 
										&vars.win_img.line_length, &vars.win_img.endian);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}