/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:36:30 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/21 01:01:49 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor1(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, x * 50, y * 50);
}

void	cherry(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, x * 50, y * 50);
	vars->points++;
}

void	wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, x * 50, y * 50);
}

void	player(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, x * 50, y * 50);
	if (vars->mapxy->map[y][x] == 'E' && vars->points == 0)
		close_window(vars);
	vars->x = x;
	vars->y = y;
}

void	exit1(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img5, x * 50, y * 50);
}
