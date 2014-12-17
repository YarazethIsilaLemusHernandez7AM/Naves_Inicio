#include "Game.h"

void CGame::inicializandoStage(){
	nivel[0].fondoNivel = 0;
	nivel[0].balasMaximas = 3;
	nivel[0].NumeroEnemigosEliminar = 10;
	nivel[0].NumeroEnemigosVisibles = 2;
	nivel[0].velocidadBalasEnemigo = 5;
	nivel[0].velocidadBalasPropias = 10;
	nivel[0].VelocidadNavePropia = 5;
	nivel[0].VelocidadNaveEnemigo = 10;
	nivel[0].vidaEnemigo = 1;

	nivel[1].fondoNivel = 1;
	nivel[1].balasMaximas = 6;
	nivel[1].NumeroEnemigosEliminar = 20;
	nivel[1].NumeroEnemigosVisibles = 4;
	nivel[1].velocidadBalasEnemigo = 15;
	nivel[1].velocidadBalasPropias = 13;
	nivel[1].VelocidadNavePropia = 8;
	nivel[1].VelocidadNaveEnemigo = 18;
	nivel[1].vidaEnemigo = 2;
}