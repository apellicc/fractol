/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:22:25 by apellicc          #+#    #+#             */
/*   Updated: 2016/05/27 07:15:58 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 1200
# define WIN_Y 1000

# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L<<1)
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*data;
	int				bpl;
	int				bpp;
	int				endi;
	char			*av;
	int				i;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;

	int				m_x;
	int				m_y;
	int				m_r;
	int				m_v;
	int				m_b;
	double			max;
	double			im_x;
	double			im_y;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;

	double			tmp;
	double			zoom;
	int				itm;
	int				res;
	int				bj;

	double			tmpx;
	double			tmpy;
	double			tmpx2;
	double			tmpy2;
	int				check;
}					t_env;

void				ft_put_pixel(t_env *en, int x, int y, int color);
int					ft_keycore(t_env *en);
int					ft_key_binding(int kc, t_env *en);
int					ft_key_release(int kc, t_env *en);
void				ft_key_action(t_env *en);
int					ft_mouse_hook(int kc, int x, int y, t_env *en);
void				ft_fractol_init(t_env *en);
void				ft_print_fractol(t_env *en);
void				ft_init_mandelbrot(t_env *en);
void				ft_mandelbrot(t_env *en);
void				ft_init_julia(t_env *en);
void				ft_julia(t_env *en);
int					ft_julia_hook(int x, int y, t_env *en);
void				ft_init_burnship(t_env *en);
void				ft_burnship(t_env *en);
void				ft_init_mandelbrot2(t_env *en);
void				ft_mandelbrot2(t_env *en);
void				ft_init_julia2(t_env *en);
void				ft_julia2(t_env *en);

#endif
