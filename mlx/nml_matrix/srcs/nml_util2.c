/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:58:40 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 21:05:23 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_util.h"

void	nml_flog(const char *f_name, unsigned int line, const char *msg)
{
	if (DEBUG_TRUE)
	{
		nml_vlog_info(f_name, line, msg);
	}
}

void	nml_finfo(const char *f_name, unsigned int line, const char *msg)
{
	if (DEBUG_TRUE)
	{
		nml_vlog_info(f_name, line, msg);
	}
}

void	nml_ferror(const char *f_name, unsigned int line, const char *msg)
{
	if (DEBUG_TRUE)
	{
		nml_vlog_error(f_name, line, msg);
	}
}

void	nml_error(const char *f_name, unsigned int line, const char *msg)
{
	if (DEBUG_TRUE)
		nml_vlog_error(f_name, line, msg);
}
