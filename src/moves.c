/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:03:36 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/21 01:08:03 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_vars *vars)
{
	if (vars->mapxy->map[vars->y - 1][vars->x] == '1')
		return ;
	if (vars->mapxy->map[vars->y - 1][vars->x] == 'C')
	{
		vars->points--;
		vars->mapxy->map[vars->y - 1][vars->x] = '0';
	}
	ft_printf("Number of moves %d\n", ++vars->counter);
	vars->y -= 1;
	player(vars, vars->x, vars->y);
	if (vars->mapxy->map[vars->y + 1][vars->x] == 'E')
		exit1(vars, vars->x, vars->y + 1);
	else
		floor1(vars, vars->x, vars->y + 1);
}

void	movedown(t_vars *vars)
{
	if (vars->mapxy->map[vars->y + 1][vars->x] == '1')
		return ;
	if (vars->mapxy->map[vars->y + 1][vars->x] == 'C')
	{
		vars->points--;
		vars->mapxy->map[vars->y + 1][vars->x] = '0';
	}
	ft_printf("Number of moves %d\n", ++vars->counter);
	vars->y += 1;
	player(vars, vars->x, vars->y);
	if (vars->mapxy->map[vars->y - 1][vars->x] == 'E')
		exit1(vars, vars->x, vars->y - 1);
	else
		floor1(vars, vars->x, vars->y - 1);
}

void	moveleft(t_vars *vars)
{
	if (vars->mapxy->map[vars->y][vars->x - 1] == '1')
		return ;
	if (vars->mapxy->map[vars->y][vars->x - 1] == 'C')
	{
		vars->points--;
		vars->mapxy->map[vars->y][vars->x - 1] = '0';
	}
	ft_printf("Number of moves %d\n", ++vars->counter);
	vars->x -= 1;
	player(vars, vars->x, vars->y);
	if (vars->mapxy->map[vars->y][vars->x + 1] == 'E')
		exit1(vars, vars->x + 1, vars->y);
	else
		floor1(vars, vars->x + 1, vars->y);
}

void	moveright(t_vars *vars)
{
	if (vars->mapxy->map[vars->y][vars->x + 1] == '1')
		return ;
	if (vars->mapxy->map[vars->y][vars->x + 1] == 'C')
	{
		vars->points--;
		vars->mapxy->map[vars->y][vars->x + 1] = '0';
	}
	ft_printf("Number of moves %d\n", ++vars->counter);
	vars->x += 1;
	player(vars, vars->x, vars->y);
	if (vars->mapxy->map[vars->y][vars->x - 1] == 'E')
		exit1(vars, vars->x - 1, vars->y);
	else
		floor1(vars, vars->x - 1, vars->y);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		destroy_imgs(vars);
		freevars(vars);
		exit(0);
	}
	if (keycode == XK_w)
		moveup(vars);
	if (keycode == XK_a)
		moveleft(vars);
	if (keycode == XK_d)
		moveright(vars);
	if (keycode == XK_s)
		movedown(vars);
	return (0);
}
