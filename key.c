/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:23:58 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 07:18:30 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_key_binding(int kc, t_env *en)
{
	if (kc == 24 || kc == 69)
		en->itm = 1;
	if (kc == 27 || kc == 78)
		en->itm = -1;
	kc == 123 ? en->m_x += 10 : 0;
	kc == 124 ? en->m_x -= 10 : 0;
	kc == 125 ? en->m_y += 10 : 0;
	kc == 126 ? en->m_y -= 10 : 0;
	kc == 49 ? en->res = 1 : 0;
	kc == 4 ? en->bj = 1 : 0;
	kc == 18 ? en->av = "mandel" : 0;
	kc == 19 ? en->av = "mandel2" : 0;
	kc == 20 ? en->av = "julia" : 0;
	kc == 21 ? en->av = "julia2" : 0;
	kc == 23 ? en->av = "ship" : 0;
	kc == 15 ? en->m_r += 10 : 0;
	kc == 5 ? en->m_r += 10 : 0;
	kc == 11 ? en->m_r += 10 : 0;
	if (kc == 18 || kc == 19 || kc == 20 || kc == 21 || kc == 23)
		ft_fractol_init(en);
	en->check = 1;
	return (0);
}

int				ft_key_release(int kc, t_env *en)
{
	if (kc == 53)
		exit(0);
	if (kc == 24)
		en->itm = 0;
	if (kc == 27)
		en->itm = 0;
	if (kc == 5)
		en->bj = 0;
	if (kc == 49)
		en->res = 0;
	return (0);
}

void			ft_key_action(t_env *en)
{
	if (en->itm == -1 && en->max > 10)
		en->max -= 5;
	if (en->itm == 1)
		en->max += 5;
	if (en->res == 1)
		ft_fractol_init(en);
}

int				ft_keycore(t_env *en)
{
	ft_key_action(en);
	ft_print_fractol(en);
	mlx_put_image_to_window(en->mlx, en->win, en->im, 0, 0);
	return (1);
}
