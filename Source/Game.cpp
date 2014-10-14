#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.
	atexit(SDL_Quit);
	

}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete (nave);
	SDL_FreeSurface(screen);
	SDL_Quit();
}
void CGame::iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE);
	if (screen == NULL){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("mi primer juego", NULL);
	nave = new Nave(screen, "../Data/MiNave.bmp");
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
				/*nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg", "rb"));
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
				SDL_BlitSurface(nave, &fuente, screen, &destino);*/
			estado =estado_menu;
			break;
		case Estado::estado_menu:
			//nave->PintarModulo(0, 0, 0, 64, 64);
			//
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT]){ nave->Mover(1); }//los 3 casos son el priero aplicado a las demas direcciones
			if (keys[SDLK_LEFT]){nave->Mover(-1); }
			if (keys[SDLK_UP]){ nave->Mover1(-1); }
			if (keys[SDLK_DOWN]){ nave->Mover1(1); }
			nave->Pintar();
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
		while (SDL_PollEvent(&event))//aqui sdl creara una lista de eventos ocurridos
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }//si se detecta una salida de sdl o...
			if (event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen);
    }
	return true;
}
