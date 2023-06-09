/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:32:02 by jbalahce          #+#    #+#             */
/*   Updated: 2023/05/02 14:46:47 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sqr(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = y;
	size = 15;
	if (color == GREEN)
		size = 6;
	while ((i - y) < size - 1)
	{
		j = x;
		while ((j - x) < size - 1)
		{
			my_put_pixel_to_image(vars->img_ptr, j, i, color);
			j++;
		}
		i++;
	}
}

void	init_grid(t_grid_vars *gr_vrs, t_vars *vars)
{
	gr_vrs->x = ((vars->p.p.x - (GRID_SIZE / 2)) / (double)GRID_SIZE);
	gr_vrs->y = ((vars->p.p.y - (GRID_SIZE / 2)) / (double)GRID_SIZE);
	gr_vrs->i = gr_vrs->y - 5;
	gr_vrs->j = gr_vrs->x - 5;
	while (gr_vrs->i < 0)
		gr_vrs->i++;
	while (gr_vrs->j < 0)
		gr_vrs->j++;
	gr_vrs->start_j = gr_vrs->j;
	gr_vrs->start_i = gr_vrs->i;
}

void	draw_grid(t_vars *vars, t_grid_vars *gr_vrs)
{
	init_grid(gr_vrs, vars);
	while (gr_vrs->i < vars->size_map && gr_vrs->i < gr_vrs->y + 5)
	{
		gr_vrs->j = gr_vrs->start_j;
		while (gr_vrs->j < (int)ft_strlen(vars->map[gr_vrs->i])
			&& gr_vrs->j < gr_vrs->x + 5)
		{
			if (vars->map[gr_vrs->i][gr_vrs->j] == '1')
				draw_sqr(vars, (gr_vrs->j - gr_vrs->start_j) * 15,
					(gr_vrs->i - gr_vrs->start_i)
					* 15, vars->imgs.mapc1);
			else if (vars->map[gr_vrs->i][gr_vrs->j] != ' ')
				draw_sqr(vars, (gr_vrs->j - gr_vrs->start_j) * 15,
					(gr_vrs->i - gr_vrs->start_i)
					* 15, vars->imgs.mapc2);
			gr_vrs->j++;
		}
		gr_vrs->i++;
	}
	draw_sqr(vars, ((gr_vrs->x - gr_vrs->start_j) * 15) + 5,
		((gr_vrs->y - gr_vrs->start_i)
			* 15) + 5, GREEN);
}

void	draw_ray(t_vars *vars, double distance, double ray, t_grid_vars gr_vrs)
{
	int		i;
	double	offset_x;
	double	offset_y;
	double	x;
	double	y;

	i = 0;
	offset_x = cos(-ray);
	offset_y = sin(-ray);
	x = ((((vars->p.p.x - (GRID_SIZE / 2)) / (double)GRID_SIZE)
				- gr_vrs.start_j) * 15) + 7;
	y = ((((vars->p.p.y - (GRID_SIZE / 2)) / (double)GRID_SIZE)
				- gr_vrs.start_i) * 15) + 7;
	while (i < distance)
	{
		my_put_pixel_to_image(vars->img_ptr, x, y, PINK);
		x += offset_x;
		y += offset_y;
		i++;
	}
}
