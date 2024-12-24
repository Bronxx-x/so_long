/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:58:04 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/21 01:21:37 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	border_check(t_mapxy *mapxy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mapxy->exit = 0;
	mapxy->player = 0;
	mapxy->point = 0;
	while (mapxy->map[0][j])
		if (mapxy->map[0][j++] != '1')
			mapxy->err = 1;
	valid_char(mapxy, j);
	while (mapxy->map[i])
	{
		if (mapxy->map[i][0] != '1' || mapxy->map[i][j - 1] != '1')
			mapxy->err = 1;
		i++;
	}
	j = 0;
	while (mapxy->map[i - 1][j])
		if (mapxy->map[i - 1][j++] != '1')
			mapxy->err = 1;
	if (mapxy->player != 1 || mapxy->exit != 1 || mapxy->point <= 0)
		mapxy->err = 1;
}

void	valid_char(t_mapxy *mapxy, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapxy->map[i])
	{
		j = 0;
		while (mapxy->map[i][j])
		{
			if (mapxy->map[i][j] != '1' && mapxy->map[i][j] != '0'
				&& mapxy->map[i][j] != 'E' && mapxy->map[i][j] != 'P'
				&& mapxy->map[i][j] != 'C')
				mapxy->err = 1;
			if (mapxy->map[i][j] == 'P')
				mapxy->player++;
			if (mapxy->map[i][j] == 'C')
				mapxy->point++;
			if (mapxy->map[i][j++] == 'E')
				mapxy->exit++;
		}
		if (j != len)
			mapxy->err = 1;
		i++;
	}
}

void	map_path(t_mapxy *mapxy, int y, int x)
{
	if (mapxy->mappp[y][x] == '1')
		return ;
	if (mapxy->mappp[y][x] == 'C')
		mapxy->cch++;
	if (mapxy->mappp[y][x] == 'E')
		mapxy->ech = 1;
	mapxy->mappp[y][x] = '1';
	map_path(mapxy, y + 1, x);
	map_path(mapxy, y - 1, x);
	map_path(mapxy, y, x + 1);
	map_path(mapxy, y, x - 1);
}

void	start_point(t_mapxy *mapxy)
{
	int	x;
	int	y;

	y = 0;
	while (mapxy->mappp[y])
	{
		x = 0;
		while (mapxy->mappp[y][x])
		{
			if (mapxy->mappp[y][x] == 'P')
			{
				map_path(mapxy, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	path_ch(t_mapxy *mapxy)
{
	int	x;
	int	y;

	mapxy->cch = 0;
	mapxy->ech = 0;
	mapxy->c = 0;
	y = 0;
	while (mapxy->mappp[y])
	{
		x = 0;
		while (mapxy->mappp[y][x])
		{
			if (mapxy->mappp[y][x] == 'C')
				mapxy->c++;
			x++;
		}
		y++;
	}
	start_point(mapxy);
	if (mapxy->cch != mapxy->c || mapxy->ech != 1)
		mapxy->err = 1;
}
