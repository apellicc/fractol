/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:24:59 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 06:59:24 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_zoom_in(int x, int y, t_env *en)
{
	en->zoom *= 2;
	en->tmpx = en->x1 + x * (en->x2 - en->x1) / (WIN_X - 50);
	en->tmpy = en->y1 + y * (en->y2 - en->y1) / (WIN_Y - 50);
	en->tmpx2 = en->x1;
	en->tmpy2 = en->y1;
	en->x1 = en->tmpx - (en->x2 - en->x1) / 4;
	en->x2 = en->tmpx + (en->x2 - en->tmpx2) / 4;
	en->y1 = en->tmpy - (en->y2 - en->y1) / 4;
	en->y2 = en->tmpy + (en->y2 - en->tmpy2) / 4;
	en->max += 5;
}

void			ft_zoom_out(int x, int y, t_env *en)
{
	if (en->zoom > 125)
	{
		en->zoom /= 2;
		en->tmpx = en->x1 + x * (en->x2 - en->x1) / WIN_X;
		en->tmpy = en->y1 + y * (en->y2 - en->y1) / WIN_Y;
		en->tmpx2 = en->x1;
		en->tmpy2 = en->y1;
		en->x1 = en->tmpx - (en->x2 - en->x1);
		en->x2 = en->tmpx + (en->x2 - en->tmpx2);
		en->y1 = en->tmpy - (en->y2 - en->y1);
		en->y2 = en->tmpy + (en->y2 - en->tmpy2);
		en->max -= 5;
	}
}

int				ft_mouse_hook(int kc, int x, int y, t_env *en)
{
	ft_bzero(en->data, WIN_Y * WIN_X * 4);
	if (y > 0 && en->check)
	{
		if ((kc == 1 || kc == 5) && x <= WIN_X)
			ft_zoom_in(x, y, en);
		if ((kc == 2 || kc == 4) && x <= WIN_X)
			ft_zoom_out(x, y, en);
	}
	en->check = 1;
	return (1);
}
