/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CApp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:04:12 by nnakarac          #+#    #+#             */
/*   Updated: 2023/04/04 11:05:17 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ***********************************************************
	CApp.h

	The application class definition.

	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.

	This code corresponds specifically to Episode 1 of the series,
	which may be found here:
	https://youtu.be/JN5yUrJPThI

	The whole series may be found on the QuantitativeBytes
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes

	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett

***********************************************************/

#ifndef CAPP_HPP
# define CAPP_HPP

# include "SDL.h"
# include "./qbRayTrace/qbImage.hpp"

class CApp
{
	public:
	CApp(void);

	int	OnExecute(void);
	bool	OnInit(void);
	void	OnEvent(SDL_Event *event);
	void	OnLoop(void);
	void	OnRender(void);
	void	OnExit(void);

	private:
		// An instance of qbImage to store the image.
		qbImage			m_image;

		// SDL2 stuff.
		bool			isRunning;
		SDL_Window 		*pWindow;
		SDL_Renderer	*pRenderer;

};

#endif
