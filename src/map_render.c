/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:30:23 by yhamdan           #+#    #+#             */
/*   Updated: 2024/12/23 18:42:22 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render3(t_mapxy *mapxy, int i)
{
	int	j;

	mapxy->mappp = malloc(sizeof(char *) * (i + 1));
	if (!mapxy->mappp)
		mal_ch(mapxy);
	j = 0;
	while (j < i)
	{
		mapxy->mappp[j] = ft_strdup(mapxy->map[j]);
		j++;
	}
	mapxy->mappp[j] = NULL;
}

void	render2(t_mapxy *mapxy, int i)
{
	int	j;

	mapxy->mapp = malloc(sizeof(char *) * (i + 1));
	if (!mapxy->mapp)
		mal_ch(mapxy);
	j = 0;
	while (j < i)
	{
		mapxy->mapp[j] = ft_strdup(mapxy->map[j]);
		j++;
	}
	mapxy->mapp[j] = NULL;
	render3(mapxy, i);
	border_check(mapxy);
}

void	line_err(t_mapxy *mapxy, char *line, char *tmp, int fd)
{
	if (line && *line == '\n')
	{
		ft_printf("Error: Failed to render map\n");
		close(fd);
		free(line);
		free(tmp);
		free(mapxy);
		exit(1);
	}
}

void	read_map(t_mapxy *mapxy, char *tmp, char *line, int fd)
{
	char	*tmp2;
	int		i;

	i = 0;
	mapxy->err = 0;
	while (line != NULL)
	{
		tmp2 = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		tmp = tmp2;
		line = get_next_line(fd);
		if (i == 0 && !line)
		{
			free(tmp);
			err_ch(mapxy, fd);
		}
		line_err(mapxy, line, tmp, fd);
		i++;
	}
	mapxy->map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	render2(mapxy, i);
}

void	render(t_mapxy *mapxy, char *argv1)
{
	char	*line;
	int		fd;
	char	*tmp;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		err_ch(mapxy, fd);
	line = get_next_line(fd);
	if (!line)
		err_ch(mapxy, fd);
	else if (*line == '\n')
	{
		free(line);
		err_ch(mapxy, fd);
	}
	tmp = ft_strdup("");
	read_map(mapxy, tmp, line, fd);
}
