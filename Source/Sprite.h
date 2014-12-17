#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
#include "SpriteDef.h"

class Sprite
{
	SDL_Surface * imagen;//imagen a manipular
	SDL_Surface * screen;//pantalla
	SpriteDef spriteDef;//definicion de sprite
public:
	Sprite(SDL_Surface * screen);//constructor que recibe la pantalla
	~Sprite();//destructor de llama con delete
	void CargarImagen(char*path);
	//void PintarModulo(int color, int x, int y, int w, int h);
	void PintarModulo(int nombre, int x, int y);
	int WidthModule(int module);
	int HeightModule(int module);
	
};
#endif 