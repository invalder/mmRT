#ifndef CAPP_H
# define CAPP_H

# include "SDL.h"

typedef struct s_qbImg
{
	void			(*fConstruct)(void);
	void			(*fDeConstruct)(void);
	void			(*fInit)(const int, const int, SDL_Renderer *, struct s_qbImg *);
	void			(*fSetPixel)(const int, const int, const double, const double, const double);
	void			(*fDisplay)(void);
	Uint32			(*fConvColor)(const double, const double, const double);
	void			(*fInitTexture)(void);

	double			**m_rChannel;
	double			**m_gChannel;
	double			**m_bChannel;
	int				m_xSize;
	int				m_ySize;
	SDL_Renderer	*m_pRenderer;
	SDL_Texture		*m_pTexture;
}	t_qbImg;

typedef struct s_capp
{
	t_qbImg			m_image;
	void			(*fConstruct)(void);
	void			(*fDeConstruct)(void);
	int				(*fOnExecute)(void);
	bool			(*fOnInit)(void);
	void			(*fOnEvent)(SDL_Event *);
	void			(*fOnLoop)(void);
	void			(*fOnRender)(void);
	void			(*fOnExit)(void);

	bool			isRunning;
	SDL_Window		*pWindow;
	SDL_Renderer	*pRenderer;
}	t_capp;

void	channel_deallocation(double **ch, struct s_qbImg *qbPtr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < qbPtr->m_xSize)
	{
		y = 0;
		while (y < qbPtr->m_ySize)
		{
			ch[x][y] = 0;
			y++;
		}
		free(ch[x]);
		x++;
	}
	free(ch);
}

double	**channel_allocation(const int xSize, const int ySize, double **ch, struct s_qbImg *qbPtr)
{
	double	**newChannel;

	newChannel = NULL;
	newChannel = (double **)malloc(sizeof(double *) * ySize);
	if (ch) // Duplicate and Dealloc existing channel
	{
		channel_deallocation(ch, qbPtr);
		free(ch);
		ch = NULL;
	}
	ch = ()
}

void	qbImg_Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer, struct s_qbImg *qbPtr)
{
	// qbPtr->m_rChannel = (double **)malloc(sizeof(double *) * ySize);

}

#endif
