/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:18:28 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 21:41:24 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_util.h"

float	nml_rand_interval(float min, float max)
{
	float	d;

	d = (float) rand() / ((float) RAND_MAX + 1);
	return (min + d * (max - min));
}

void	np_check(void *ptr)
{
	if (!ptr)
	{
		dprintf(STDERR_FILENO, RED "%s: %d NULL POINTER: %s \n" RESET, \
			__FILE__, __LINE__, ptr);
		exit(-1);
	}
}

void	nml_vlog_info(const char *f_name, unsigned int line, \
	const char *msg)
{
	if (DEBUG_TRUE)
	{
		dprintf(STDOUT_FILENO, "[%s:%d] [%s] %s\n", f_name, line, "INFO", msg);
	}
}

void	nml_vlog_error(const char *f_name, unsigned int line, \
	const char *msg)
{
	if (DEBUG_TRUE)
	{
		dprintf(STDERR_FILENO, "[%s:%d] [%s] %s\n", f_name, line, "INFO", msg);
	}
}
