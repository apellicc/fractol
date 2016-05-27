/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:24:11 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 07:10:23 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_fractol_init(t_env *en)
{
	en->bj = 1;
	en->m_x = 0;
	en->m_y = 0;
	en->m_r = 0;
	en->m_v = 0;
	en->m_b = 0;
	if (!(ft_strcmp(en->av, "mandel")))
		ft_init_mandelbrot(en);
	if (!(ft_strcmp(en->av, "mandel2")))
		ft_init_mandelbrot2(en);
	if (!(ft_strcmp(en->av, "julia")))
		ft_init_julia(en);
	if (!(ft_strcmp(en->av, "julia2")))
		ft_init_julia2(en);
	if (!(ft_strcmp(en->av, "ship")))
		ft_init_burnship(en);
}

void			ft_print_fractol(t_env *en)
{
	ft_bzero(en->data, WIN_Y * WIN_X * 4);
	if (!(ft_strcmp(en->av, "mandel")))
		ft_mandelbrot(en);
	if (!(ft_strcmp(en->av, "mandel2")))
		ft_mandelbrot2(en);
	if (!(ft_strcmp(en->av, "julia")))
		ft_julia(en);
	if (!(ft_strcmp(en->av, "julia2")))
		ft_julia2(en);
	if (!(ft_strcmp(en->av, "ship")))
		ft_burnship(en);
}

int				main(int argc, char **av)
{
	t_env		en;

	en.av = av[1];
	if (argc == 2 && ((!(ft_strcmp(en.av, "mandel")))
	|| (!(ft_strcmp(en.av, "julia"))) || (!(ft_strcmp(en.av, "ship"))) ||
	(!(ft_strcmp(en.av, "julia2"))) || (!(ft_strcmp(en.av, "mandel2")))))
	{
		en.mlx = mlx_init();
		en.win = mlx_new_window(en.mlx, WIN_X, WIN_Y, "fractol");
		en.im = mlx_new_image(en.mlx, WIN_X, WIN_Y);
		en.data = mlx_get_data_addr(en.im, &en.bpp, &en.bpl, &en.endi);
		ft_fractol_init(&en);
		mlx_hook(en.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_julia_hook, &en);
		mlx_hook(en.win, KEYPRESS, KEYPRESSMASK, ft_key_binding, &en);
		mlx_hook(en.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &en);
		mlx_mouse_hook(en.win, ft_mouse_hook, &en);
		mlx_loop_hook(en.mlx, ft_keycore, &en);
		mlx_loop(en.mlx);
	}
	else
	{
		ft_putendl("Enter 'mandel', 'mandel2', 'julia', 'julia2' or 'ship'");
		exit(1);
	}
	return (0);
}
