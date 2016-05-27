/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:23:46 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 07:19:05 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_draw_julia(t_env *en)
{
	int a;

	en->z_r = (en->x / en->zoom + en->x1) + en->m_x / en->zoom;
	en->z_i = (en->y / en->zoom + en->y1) + en->m_y / en->zoom;
	en->i = 0;
	while (en->z_r * en->z_r + en->z_i * en->z_i < 4 && en->i < en->max)
	{
		en->tmp = en->z_r;
		en->z_r = en->z_r * en->z_r - en->z_i * en->z_i + en->c_r;
		en->z_i = 2 * en->z_i * en->tmp + en->c_i;
		en->i++;
	}
	a = en->bpl * en->y + en->x * 4;
	if (en->i == en->max)
		en->data[a] = 0;
	else
	{
		en->data[a] = en->i * (110 + en->m_r);
		en->data[a + 1] = en->i * (285 + en->m_v);
		en->data[a + 2] = en->i * (73 + en->m_b);
	}
}

void			ft_init_julia(t_env *en)
{
	en->x1 = -2.4;
	en->x2 = 1.2;
	en->y1 = -2;
	en->y2 = 1.8;
	en->zoom = 250;
	en->im_x = (en->x2 - en->x1) * en->zoom + 150;
	en->im_y = (en->y2 - en->y1) * en->zoom;
	en->max = 90;
	en->c_r = 0.285;
	en->c_i = 0.01;
}

void			ft_julia(t_env *en)
{
	en->x = -1;
	while (++en->x < WIN_X)
	{
		en->y = -1;
		while (++en->y < WIN_Y)
			ft_draw_julia(en);
	}
	mlx_put_image_to_window(en->mlx, en->win, en->im, 0, 0);
}

int				ft_julia_hook(int x, int y, t_env *en)
{
	if ((!(ft_strcmp(en->av, "julia")) || (!(ft_strcmp(en->av, "julia2"))))
		&& x <= WIN_X && y <= WIN_Y && x > 0 && y > 0 && en->bj == 0)
	{
		en->c_r = (float)(x + 400 - WIN_X) / 300;
		en->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}
