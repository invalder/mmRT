/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:34:33 by nnakarac          #+#    #+#             */
/*   Updated: 2023/04/04 11:20:03 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define _GNU_SOURCE

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define WIDTH	1024
# define HEIGHT	768

# define PI		3.14

enum e_key {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_Z = 6,
	KEY_C = 8,
	KEY_R = 15,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_SQBO = 30,
	KEY_O = 31,
	KEY_I = 34,
	KEY_SQBC = 33,
	KEY_P = 35,
	KEY_QUOTE = 39,
	KEY_SEMI = 41,
	KEY_SPACE = 49,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_draw
{
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		color;
}	t_draw;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

typedef struct s_mouse
{
	int		is_pressed;
	int		pos_x;
	int		pos_y;
}	t_mouse;

typedef struct s_handle
{
	t_vars		*data;
	t_draw		*draw;
	t_mouse		*mouse;
}	t_handle;

#endif
