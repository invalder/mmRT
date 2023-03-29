/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:58:30 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/28 23:08:59 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "nml_matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum keys
{
	MLX_KEY_SPACE			= 32,
	MLX_KEY_APOSTROPHE		= 39,
	MLX_KEY_COMMA			= 44,
	MLX_KEY_MINUS			= 45,
	MLX_KEY_PERIOD			= 46,
	MLX_KEY_SLASH			= 47,
	MLX_KEY_0				= 48,
	MLX_KEY_1				= 49,
	MLX_KEY_2				= 50,
	MLX_KEY_3				= 51,
	MLX_KEY_4				= 52,
	MLX_KEY_5				= 53,
	MLX_KEY_6				= 54,
	MLX_KEY_7				= 55,
	MLX_KEY_8				= 56,
	MLX_KEY_9				= 57,
	MLX_KEY_SEMICOLON		= 59,
	MLX_KEY_EQUAL			= 61,
	MLX_KEY_A				= 65,
	MLX_KEY_B				= 66,
	MLX_KEY_C				= 67,
	MLX_KEY_D				= 68,
	MLX_KEY_E				= 69,
	MLX_KEY_F				= 70,
	MLX_KEY_G				= 71,
	MLX_KEY_H				= 72,
	MLX_KEY_I				= 73,
	MLX_KEY_J				= 74,
	MLX_KEY_K				= 75,
	MLX_KEY_L				= 76,
	MLX_KEY_M				= 77,
	MLX_KEY_N				= 78,
	MLX_KEY_O				= 79,
	MLX_KEY_P				= 80,
	MLX_KEY_Q				= 81,
	MLX_KEY_R				= 82,
	MLX_KEY_S				= 83,
	MLX_KEY_T				= 84,
	MLX_KEY_U				= 85,
	MLX_KEY_V				= 86,
	MLX_KEY_W				= 87,
	MLX_KEY_X				= 88,
	MLX_KEY_Y				= 89,
	MLX_KEY_Z				= 90,
	MLX_KEY_LEFT_BRACKET	= 91,
	MLX_KEY_BACKSLASH		= 92,
	MLX_KEY_RIGHT_BRACKET	= 93,
	MLX_KEY_GRAVE_ACCENT	= 96,
	MLX_KEY_ESCAPE			= 256,
	MLX_KEY_ENTER			= 257,
	MLX_KEY_TAB				= 258,
	MLX_KEY_BACKSPACE		= 259,
	MLX_KEY_INSERT			= 260,
	MLX_KEY_DELETE			= 261,
	MLX_KEY_RIGHT			= 262,
	MLX_KEY_LEFT			= 263,
	MLX_KEY_DOWN			= 264,
	MLX_KEY_UP				= 265,
	MLX_KEY_PAGE_UP			= 266,
	MLX_KEY_PAGE_DOWN		= 267,
	MLX_KEY_HOME			= 268,
	MLX_KEY_END				= 269,
	MLX_KEY_CAPS_LOCK		= 280,
	MLX_KEY_SCROLL_LOCK		= 281,
	MLX_KEY_NUM_LOCK		= 282,
	MLX_KEY_PRINT_SCREEN	= 283,
	MLX_KEY_PAUSE			= 284,
	MLX_KEY_F1				= 290,
	MLX_KEY_F2				= 291,
	MLX_KEY_F3				= 292,
	MLX_KEY_F4				= 293,
	MLX_KEY_F5				= 294,
	MLX_KEY_F6				= 295,
	MLX_KEY_F7				= 296,
	MLX_KEY_F8				= 297,
	MLX_KEY_F9				= 298,
	MLX_KEY_F10				= 299,
	MLX_KEY_F11				= 300,
	MLX_KEY_F12				= 301,
	MLX_KEY_F13				= 302,
	MLX_KEY_F14				= 303,
	MLX_KEY_F15				= 304,
	MLX_KEY_F16				= 305,
	MLX_KEY_F17				= 306,
	MLX_KEY_F18				= 307,
	MLX_KEY_F19				= 308,
	MLX_KEY_F20				= 309,
	MLX_KEY_F21				= 310,
	MLX_KEY_F22				= 311,
	MLX_KEY_F23				= 312,
	MLX_KEY_F24				= 313,
	MLX_KEY_F25				= 314,
	MLX_KEY_KP_0			= 320,
	MLX_KEY_KP_1			= 321,
	MLX_KEY_KP_2			= 322,
	MLX_KEY_KP_3			= 323,
	MLX_KEY_KP_4			= 324,
	MLX_KEY_KP_5			= 325,
	MLX_KEY_KP_6			= 326,
	MLX_KEY_KP_7			= 327,
	MLX_KEY_KP_8			= 328,
	MLX_KEY_KP_9			= 329,
	MLX_KEY_KP_DECIMAL		= 330,
	MLX_KEY_KP_DIVIDE		= 331,
	MLX_KEY_KP_MULTIPLY		= 332,
	MLX_KEY_KP_SUBTRACT		= 333,
	MLX_KEY_KP_ADD			= 334,
	MLX_KEY_KP_ENTER		= 335,
	MLX_KEY_KP_EQUAL		= 336,
	MLX_KEY_LEFT_SHIFT		= 340,
	MLX_KEY_LEFT_CONTROL	= 341,
	MLX_KEY_LEFT_ALT		= 342,
	MLX_KEY_LEFT_SUPER		= 343,
	MLX_KEY_RIGHT_SHIFT		= 344,
	MLX_KEY_RIGHT_CONTROL	= 345,
	MLX_KEY_RIGHT_ALT		= 346,
	MLX_KEY_RIGHT_SUPER		= 347,
	MLX_KEY_MENU			= 348,
}	keys_t;

typedef enum mlx_errno
{
	MLX_SUCCESS = 0,	// No Errors
	MLX_INVEXT,			// File has an invalid extension
	MLX_INVFILE,		// File was invalid / does not exist.
	MLX_INVPNG,			// Something is wrong with the given PNG file.
	MLX_INVXPM,			// Something is wrong with the given XPM file.
	MLX_INVPOS,			// The specified X/Y positions are out of bounds.
	MLX_INVDIM,			// The specified W/H dimensions are out of bounds.
	MLX_INVIMG,			// The provided image is invalid, might indicate mismanagement of images.
	MLX_VERTFAIL,		// Failed to compile the vertex shader.
	MLX_FRAGFAIL,		// Failed to compile the fragment shader.
	MLX_SHDRFAIL,		// Failed to compile the shaders.
	MLX_MEMFAIL,		// Dynamic memory allocation has failed.
	MLX_GLADFAIL,		// OpenGL loader has failed.
	MLX_GLFWFAIL,		// GLFW failed to initialize.
	MLX_WINFAIL,		// Failed to create a window.
	MLX_STRTOOBIG,		// The string is too big to be drawn.
	MLX_ERRMAX,			// Error count
}	mlx_errno_t;

typedef struct mlx_instance
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
	bool	enabled;
}	mlx_instance_t;

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	(void) argc;
	(void) argv;
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(-1));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(-1));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(-1));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
