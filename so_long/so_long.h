/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:02 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/29 17:28:10 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <mlx.h>
# include <string.h>

# define TILESIZE 64
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

typedef struct s_texture {
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_texture;

typedef struct s_move {
	int	a;
	int	w;
	int	s;
	int	d;
	int	pos_x;
	int	pos_y;
	int	coin;
}				t_move;
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	char		**map;
	t_data		win_img;
	t_move		player;
	t_move		enemy;
	t_texture	col_tex;
	t_texture	flo_tex;
	t_texture	pla_tex;
	t_texture	exi_tex;
	t_texture	wal_tex;
	t_texture	ene_tex;
}				t_vars;

int		schecker(t_vars	vars, char *str);
int		checkexist(char *str, t_vars vars);
int		checkfl(t_vars vars);
int		checkback(char *str, t_vars vars);
void	norm32(t_vars *vars, int w, int h);
void	pixelb(t_vars vars);
void	drawfloor(t_vars	vars);
int		get_height(char **map);
void	get_textures(t_vars	*vars);
void	get_pos(t_vars *vars);
char	**ft_splitcpy(const char *s, char c, char **str, int alloc);
char	**ft_charcount(const char *s, char c, char **str, int alloc);
char	**ft_split(char const *s, char c);
char	*matrix(int fd);
int		get_width(char	**map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	cases(int y, int x, t_vars	vars);
void	checkside3(t_vars	*vars);
void	checkside2(t_vars *vars);
void	checkside1(t_vars *vars);
int		check_side(t_vars *vars);
int		update(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		quit(void);
int		key_rel(int keycode, t_vars *vars);
void	ft_clean(t_vars *vars);
void	draw(int y, int x, t_vars vars, t_texture tex);
void	enemynorm(t_vars *vars);
void	enemy(t_vars *vars);
int		invalidfile(char *str);
int		rec(t_vars vars);
#endif