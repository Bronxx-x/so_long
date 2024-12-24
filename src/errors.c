/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:28 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/23 18:44:00 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_imgs(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img1);
	mlx_destroy_image(vars->mlx, vars->img2);
	mlx_destroy_image(vars->mlx, vars->img3);
	mlx_destroy_image(vars->mlx, vars->img4);
	mlx_destroy_image(vars->mlx, vars->img5);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

void	freevars(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->mapxy->map[i])
	{
		free(vars->mapxy->map[i]);
		free(vars->mapxy->mapp[i]);
		free(vars->mapxy->mappp[i]);
		i++;
	}
	free(vars->mapxy->map);
	free(vars->mapxy->mapp);
	free(vars->mapxy->mappp);
	if (vars->mapxy->err == 0)
		free(vars->mlx);
	free(vars->mapxy);
}

void	err_ch(t_mapxy *mapxy, int fd)
{
	ft_printf("Error: Failed to open file\n");
	free(mapxy);
	if (fd != -1)
		close(fd);
	exit(1);
}

void	mal_ch(t_mapxy *mapxy)
{
	ft_printf("Error: Malloc failed\n");
	free(mapxy);
	exit(1);
}

void	render_err(t_vars *vars)
{
	if (vars->mapxy->err)
	{
		ft_printf("Error: Failed to render map\n");
		freevars(vars);
		exit(1);
	}
}
