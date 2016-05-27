/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 08:25:44 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 08:25:52 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_draw_mandelbrot2(t_env *en)
{
	int a;

	en->c_r = (en->x / en->zoom + en->x1) + en->m_x / en->zoom;
	en->c_i = (en->y / en->zoom + en->y1) + en->m_y / en->zoom;
	en->z_r = 0;
	en->z_i = 0;
	en->i = 0;
	while (en->z_r * en->z_r + en->z_i * en->z_i < 4 && en->i < en->max)
	{
		en->tmp = en->z_r;
		en->z_r = en->z_r * en->z_r - en->z_i * en->z_i + en->c_r;
		en->z_i = -2 * en->z_i * en->tmp + en->c_i;
		en->i++;
	}
	a = en->bpl * en->y + en->x * 4;
	if (en->i == en->max)
		en->data[a] = 0;
	else
	{
		en->data[a] = en->i * (15 + en->m_r);
		en->data[a + 1] = en->i * (16 + en->m_v);
		en->data[a + 2] = en->i * (23 + en->m_b);
	}
}

void			ft_init_mandelbrot2(t_env *en)
{
	en->x1 = -2.4;
	en->x2 = 1.2;
	en->y1 = -2;
	en->y2 = 1.8;
	en->zoom = 250;
	en->im_x = (en->x2 - en->x1) * en->zoom + 150;
	en->im_y = (en->y2 - en->y1) * en->zoom;
	en->max = 90;
}

void			ft_mandelbrot2(t_env *en)
{
	en->x = -1;
	while (++en->x < WIN_X)
	{
		en->y = -1;
		while (++en->y < WIN_Y)
			ft_draw_mandelbrot2(en);
	}
	mlx_put_image_to_window(en->mlx, en->win, en->im, 0, 0);
}
