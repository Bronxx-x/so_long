/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:47:12 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/20 22:45:24 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars	t_vars;

typedef struct s_mapxy
{
	char				**map;
	char				**mapp;
	char				**mappp;
	int					width;
	int					height;
	int					err;
	int					point;
	int					player;
	int					exit;
	int					ech;
	int					cch;
	int					c;
}						t_mapxy;

struct					s_vars
{
	void				*mlx;
	void				*win;
	int					y;
	int					x;
	int					points;
	void				*img1;
	void				*img2;
	void				*img4;
	void				*img3;
	void				*img5;
	int					counter;
	t_mapxy				*mapxy;
};

int						handle_keypress(int keycode, t_vars *vars);
void					fill(t_vars *vars, int y, int x);
void					flood_fill(t_vars *vars, char **map);
int						close_window(t_vars *vars);
void					floor1(t_vars *vars, int x, int y);
void					cherry(t_vars *vars, int x, int y);
void					wall(t_vars *vars, int x, int y);
void					player(t_vars *vars, int x, int y);
void					exit1(t_vars *vars, int x, int y);
void					moveup(t_vars *vars);
void					movedown(t_vars *vars);
void					moveleft(t_vars *vars);
void					moveright(t_vars *vars);
void					img_init(t_vars *vars);
void					render(t_mapxy *mapxy, char *argv1);
void					freevars(t_vars *vars);
void					err_ch(t_mapxy *mapxy, int fd);
void					destroy_imgs(t_vars *vars);
void					border_check(t_mapxy *mapxy);
void					valid_char(t_mapxy *mapxy, int len);
void					render_err(t_vars *vars);
void					mal_ch(t_mapxy *mapxy);
void					map_path(t_mapxy *mapxy, int x, int y);
void					path_ch(t_mapxy *mapxy);

#endif
