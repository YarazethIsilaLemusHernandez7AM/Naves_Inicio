#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"
class  Nave
{
	Sprite*sprite;
	int x;
	int y;
	int w;
	int h;
	bool autoMovimiento;
	int pasoActual;
	int pasoLimite;
	int module;
public:
	void Mover(int posicion);
	void Mover1(int posicion);
	Nave(SDL_Surface*screen, char*rutaImagen,int x,int y,int module);//constructor
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
	bool EstaColicionando(Nave * b);
	int ObtenerX();

};
#endif