/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fllood_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:16:37 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/23 16:22:17 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_vars *vars)
{
	int	width;
	int	height;

	vars->img1 = mlx_xpm_file_to_image(vars->mlx, "images/wall.xpm", &width,
			&height);
	vars->img2 = mlx_xpm_file_to_image(vars->mlx, "images/player.xpm", &width,
			&height);
	vars->img3 = mlx_xpm_file_to_image(vars->mlx, "images/item.xpm", &width,
			&height);
	vars->img4 = mlx_xpm_file_to_image(vars->mlx, "images/floor.xpm", &width,
			&height);
	vars->img5 = mlx_xpm_file_to_image(vars->mlx, "images/exit.xpm", &width,
			&height);
	if (!vars->img1 || !vars->img2 || !vars->img3 || !vars->img4 || !vars->img5)
	{
		freevars(vars);
		destroy_imgs(vars);
	}
}

void	fill(t_vars *vars, int y, int x)
{
	if (x < 0 || y < 0 || x >= vars->mapxy->width || y >= vars->mapxy->height
		|| vars->mapxy->mapp[y][x] == 'V')
		return ;
	if (vars->mapxy->mapp[y][x] == '1')
		wall(vars, x, y);
	if (vars->mapxy->mapp[y][x] == '0')
		floor1(vars, x, y);
	if (vars->mapxy->mapp[y][x] == 'C')
		cherry(vars, x, y);
	if (vars->mapxy->mapp[y][x] == 'P')
		player(vars, x, y);
	if (vars->mapxy->mapp[y][x] == 'E')
		exit1(vars, x, y);
	vars->mapxy->mapp[y][x] = 'V';
	fill(vars, y + 1, x);
	fill(vars, y - 1, x);
	fill(vars, y, x + 1);
	fill(vars, y, x - 1);
}

void	flood_fill(t_vars *vars, char **map)
{
	if (!vars->mlx)
		freevars(vars);
	vars->points = 0;
	vars->y = 1;
	vars->x = 1;
	vars->counter = 0;
	vars->mapxy->height = 0;
	while (map[vars->mapxy->height])
		vars->mapxy->height++;
	vars->mapxy->width = ft_strlen(map[0]);
	vars->mapxy->mapp = map;
	vars->win = mlx_new_window(vars->mlx, (vars->mapxy->width) * 50,
			vars->mapxy->height * 50, "So Long");
	if (!vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		freevars(vars);
	}
	img_init(vars);
	fill(vars, 0, 0);
}

int	close_window(t_vars *vars)
{
	destroy_imgs(vars);
	freevars(vars);
	exit(0);
	return (0);
}

int	main(int arg, char **argv)
{
	t_vars	vars;

	if (arg != 2 || ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1]
			+ ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("invalid arguments\n");
		return (0);
	}
	vars.mapxy = malloc(sizeof(t_mapxy));
	if (!vars.mapxy)
		mal_ch(vars.mapxy);
	render(vars.mapxy, argv[1]);
	if (!vars.mapxy->err)
		path_ch(vars.mapxy);
	render_err(&vars);
	vars.mlx = mlx_init();
	flood_fill(&vars, vars.mapxy->mapp);
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
