#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.
	finestado = estado_finalizado;
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
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2) /*- (sprite->WidthModule(0) / 2)*/,(HEIGHT_SCREEN - 80) /*- (sprite->HeightModule(0))*/);
	enemigo = new Nave(screen, "../Data/enemigo.bmp",0,0);
	enemigo->Setautomovimiento(true);
}
bool CGame::Start()
{
	
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;    
	while (salirJuego == false){

            
		//Maquina de estados
		switch(estado){
		case Estado::estado_iniciado:
			printf("1. Estado_Iniciando\n");
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
					
					if (finestado == estado_menu)
					{
						estado = estado_finalizado;
						printf("2. Estado_Menu\n");
						finestado = estado_terminado;


					}
					 if (estado==estado_menu)
					{
						printf("2. Estado_Menu\n");
						estado = estado_jugando;
					}
					
				
				/*enemigo->Actualizar();
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
				keys = SDL_GetKeyState(NULL);
				if (keys[SDLK_RIGHT]){ nave->Mover(1); }//los 3 casos son el priero aplicado a las demas direcciones
				if (keys[SDLK_LEFT]){ nave->Mover(-1); }
				if (keys[SDLK_UP]){ nave->Mover1(-1); }
				if (keys[SDLK_DOWN]){ nave->Mover1(1); }
				nave->Pintar();
				enemigo->Pintar();*/
				
			break;
		case Estado::estado_jugando:

			enemigo->Actualizar();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT]){ nave->Mover(1); }//los 3 casos son el priero aplicado a las demas direcciones
			if (keys[SDLK_LEFT]){ nave->Mover(-1); }
			if (keys[SDLK_UP]){ nave->Mover1(-1); }
			if (keys[SDLK_DOWN]){ nave->Mover1(1); }
			nave->Pintar();
			enemigo->Pintar();
			if (keys[SDLK_HOME])
			{
				estado = estado_terminado;

				printf("3. Estado_Jugando\n");
			}
			break;
		case Estado::estado_terminado:
			printf("4. Estado_Terminando\n");
			salirJuego = false;
			estado = estado_menu;
			finestado= estado_menu;
			break;
		case Estado::estado_finalizado:
			printf("5. Estado_Finalizando\n");
			salirJuego = true;
			getchar();
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
