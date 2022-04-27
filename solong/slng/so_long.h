/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:02 by aainhaja          #+#    #+#             */
/*   Updated: 2022/04/23 02:43:04 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include <mlx.h>
#include<string.h>

# define TILESIZE 64
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

typedef struct	s_texture {
	void	*img;
	unsigned int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture;

typedef struct	s_move {
	int A;
	int W;
	int S;
	int D;
	int pos_x;
	int pos_y;
	int coin;
}				t_move;
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char    **map;
	t_data  win_img;
	t_move player;
	t_move enemy;

	t_texture	col_tex;
	t_texture	flo_tex;
	t_texture	pla_tex;
	t_texture	exi_tex;
	t_texture	wal_tex;
	t_texture	ene_tex;
}				t_vars;

int	schecker(t_vars	vars, char *str);
int checkexist(char *str, t_vars vars);
int checkfl(t_vars vars);
int	checkback(char *str,t_vars vars);
#endif