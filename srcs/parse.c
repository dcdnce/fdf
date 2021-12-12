/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:30:02 by pforesti          #+#    #+#             */
/*   Updated: 2021/12/07 17:46:08 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

static void	ft_act_height(int point, t_map *map)
{
	if (point < map->minheight)
		map->minheight = point;
	if (point > map->maxheight)
		map->maxheight = point;
}

static void	ft_get_length(char *path, t_map *map)
{
	int		fd;
	char	**line;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno), 0);
	s = get_next_line(fd);
	line = ft_split(s, ' ');
	if (!line)
		ft_error("file not parsable", 1);
	while (line[map->x] != NULL)
	{
		free(line[map->x]);
		map->x++;
	}
	free(line);
	while (s != NULL)
	{
		free(s);
		map->y++;
		s = get_next_line(fd);
	}
	close(fd);
}

static char	**ft_get_gnl(int fd)
{
	char	*s;
	char	**line;

	s = get_next_line(fd);
	line = ft_split(s, ' ');
	free(s);
	return (line);
}

static int	**ft_get_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	**line;
	int		**lst;

	lst = malloc(map->y * sizeof(int *));
	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < map->y)
	{
		line = ft_get_gnl(fd);
		lst[i] = malloc(map->x * sizeof(int));
		j = -1;
		while (++j < map->x && line[j] && line)
		{
			lst[i][j] = ft_atoi(line[j]);
			ft_act_height(lst[i][j], map);
			free(line[j]);
		}
		free(line);
	}
	close(fd);
	return (lst);
}

int	ft_init(char *path, t_fdf *fdf)
{
	fdf->map.colbool = 0;
	fdf->map.maxheight = 0;
	fdf->map.minheight = 0;
	fdf->map.move.x = 0;
	fdf->map.move.y = 0;
	fdf->map.ang.x = BASE_ANGLE_X;
	fdf->map.ang.y = BASE_ANGLE_Y;
	fdf->map.y = 0;
	fdf->map.x = 0;
	ft_get_length(path, &fdf->map);
	fdf->lst = ft_get_map(path, &fdf->map);
	fdf->map.llen = 50;
	while (fdf->map.x * fdf->map.llen > SCREEN_X * 0.5f)
		fdf->map.llen -= 2;
	if (fdf->map.llen < 1)
		fdf->map.llen = 1;
	return (0);
}
