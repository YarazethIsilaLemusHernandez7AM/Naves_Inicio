#pragma once
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"
#include "Stage.h"
class CGame
{
public:
	enum Estado{
		estado_iniciado,
		estado_menu,
		estado_pre_jugando,
		estado_jugando,
		estado_terminado,
		estado_finalizado
	};
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize(); 

private:
	void iniciando();
	void Menu();
	unsigned int x;
	int tick;
	int tiempoFrameInicial;
	int tiempoFramefinal;
	Stage nivel[4];
	void inicializandoStage();
	int nivelActual;

    Objeto*textos;
	Objeto *menu;
	Objeto* fondo;
	int opcionSelecionada;
	Uint8 *keys;//estavariable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;//la ariable event de tipo eventode sdl nos servira para motorizar el
	SDL_Surface* screen;
	Nave * nave;
	Nave *enemigoArreglo [10];
	Estado estado;
	Estado finestado;
	int vida;
	int enemigosEliminados;
	

	bool EsLimitePantalla(Objeto * objeto, int bandera);
	void MoverEnemigo();
	
};