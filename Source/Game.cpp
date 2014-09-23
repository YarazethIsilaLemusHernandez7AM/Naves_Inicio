#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.

}


// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}
void CGame::iniciando(){
	screen = SDL_SetVideoMode(324, 19, 24, SDL_HWSURFACE);
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
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Descargas/cuadro.jpg", "rb"));
				SDL_Rect fuente;
				fuente.x = 90;
				fuente.y = 152;
				fuente.w = 324;
				fuente.h = 19;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = 100;
				destino.h = fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);

			}
		
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
    }
	return true;
}
