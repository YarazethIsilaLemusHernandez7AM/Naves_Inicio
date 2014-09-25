#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.
	atexit(SDL_Quit);
}


// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	SDL_Quit();
}
void CGame::iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	if (screen == NULL){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("mi primer juego", NULL);
}
bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::estado_iniciado:
			iniciando();
			{
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg", "rb"));
				SDL_Rect fuente;
				fuente.x = 90;
				fuente.y = 152;
				fuente.w = 241;
				fuente.h = 76;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = fuente.w;
				destino.h = fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);

			}
			estado = Estado::estado_menu;
			break;
		case Estado::estado_menu:
			break;
		case Estado::estado_jugando:
			break;
		case Estado::estado_terminado:
			salirJuego = true;
			break;
		case Estado::estado_finalizado:
				break;
		};
		//provicionamente
		SDL_Flip(screen);
    }
	return true;
}
