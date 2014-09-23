#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::estado_iniciado:
			break;
		case Estado::estado_menu:
			break;
		case Estado::estado_jugando:
			break;
		case Estado::estado_finalizado:
				break;
		case Estado::estado_terminado:
			salirJuego = true;
			break;
		};
    }
	return true;
}
