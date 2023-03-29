/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:33:41 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/28 23:11:38 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "nml_matrix.h"

void	mlx_key_close(t_vars *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	data->mlx = NULL;
	exit (0);
}

int	mlx_key_handler(int keycode, t_handle *handy)
{
	if (keycode == KEY_ESC)
		mlx_key_close(handy->data);
	return (0);
}

int	mlx_close(t_handle *handy)
{
	mlx_clear_window(handy->data->mlx, handy->data->win);
	mlx_destroy_window(handy->data->mlx, handy->data->win);
	handy->data->win = NULL;
	handy->data->mlx = NULL;
	exit(0);
}

static void	init_handle(t_handle *handy, t_vars *data, \
	t_draw *draw)
{
	handy->data = data;
	handy->draw = draw;
	handy->mouse = malloc(sizeof(t_mouse) * 1);
	handy->mouse->is_pressed = 0;
	handy->mouse->pos_x = 0;
	handy->mouse->pos_y = 0;
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	ft_printf("Hello World\n");
	t_vars			data;
	t_draw			draw;

	static t_handle	handy;

	// if (argc != 2)
	// 	return (fdf_no_file());
	// fdf_input_check(&meta, argv[1]);
	// fdf_init_map(&meta, argv[1]);

	nml_finfo(__FILE__, __LINE__, "error error error\n");

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "miniRT");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
		&data.img.line_length, &data.img.endian);
	init_handle(&handy, &data, &draw);
	mlx_hook(data.win, ON_DESTROY, 1L << 0, mlx_close, &handy);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, mlx_key_handler, &handy);
	// mlx_mouse_hook(data.win, mlx_mouse_handler, &handy);
	// fdf_draw(&data, &draw, &meta);
	// mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);


	return (0);
}
