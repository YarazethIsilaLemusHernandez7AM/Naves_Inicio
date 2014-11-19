#include "SpriteDef.h"
#include "Config.h"
SpriteDef::SpriteDef(){
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_FONDOJUEGO_FONDO;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;


	modulos[2].id = MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTOS_TITULOS;
	modulos[3].x = 49;
	modulos[3].y = 13;
	modulos[3].w = 478;
	modulos[3].h = 45;

	modulos[4].id = MODULO_TEXTO_NOMBRE;
	modulos[4].x = 84;
	modulos[4].y = 83;
	modulos[4].w = 212;
	modulos[4].h = 40;

	modulos[5].id = MODULO_TEXTO_MENU_INICIAR1;
	modulos[5].x = 73;
	modulos[5].y = 185;
	modulos[5].w = 215;
	modulos[5].h = 87;

	modulos[6].id = MODULO_TEXTO_MENU_SALIR1;
	modulos[6].x = 65;
	modulos[6].y = 303;
	modulos[6].w = 188;
	modulos[6].h = 81;

	modulos[7].id = MODULO_TEXTO_MENU_INICIAR2_SELECCIONADO;
	modulos[7].x = 364;
	modulos[7].y = 181;
	modulos[7].w = 219;
	modulos[7].h = 177;

	modulos[8].id = MODULO_TEXTO_MENU_SALIR2_SELECCIONADO;
	modulos[8].x = 360;
	modulos[8].y = 300;
	modulos[8].w = 218;
	modulos[8].h = 104;
}