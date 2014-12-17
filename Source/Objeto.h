#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "Sprite.h"
#include <SDL.h>
class  Objeto
{
	Sprite *sprite;
	int x;
	int y;
	int w;
	int h;
	bool autoMovimiento;
	int pasoActual;
	int pasoLimite;
	int module;
	bool isVisible;
public:
	void SetVisible(bool isVisible);
	void Mover(int posicion);
	void Mover1(int posicion);
	Objeto(SDL_Surface*screen, char*rutaImagen,int x,int y,int module);//constructor
	void Setautomovimiento(bool autoMovimiento);
	void SetPasosLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoActual();
	void Pintar();
	void Pintar(int module,int x, int y);
	void Actualizar();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
	bool EstaColicionando(Objeto * b);
	int ObtenerX();
	void ponerEn(int x, int y);

};
#endif