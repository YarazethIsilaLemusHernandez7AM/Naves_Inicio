#include "Nave.h"
#include "config.h"
Nave::Nave(SDL_Surface*screen,char*rutaImagen,int x,int y, int module){
	this->module = module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(this->module);
	h = sprite->HeightModule(this->module);
	this->x = x;
	this->y = y;
	autoMovimiento = false;
	pasoActual = 0;
	pasoLimite = -1;
}
void Nave::Setautomovimiento(bool autoMovimiento){
	this->autoMovimiento = autoMovimiento;
}
void Nave::Actualizar(){
	if (autoMovimiento)
	{
		Mover(1); 
		Mover1(1);
	}
	if (pasoLimite > 0){
		//pasoActual++;
		if (pasoActual >= pasoLimite)
			pasoActual = 0;
	}
}
void Nave::Pintar(){
	sprite->PintarModulo(module, x, y);
}
void Nave::Pintar(int module, int x, int y){
	sprite->PintarModulo(module, x, y);
}
void Nave::Mover(int posicion){
	x += posicion;
}
void Nave::Mover1(int posicion){
	y += posicion;
}
int Nave::ObtenerX(){
	return x;
}

int Nave::ObtenerY(){
	return y;

}

int Nave::ObtenerW()
{
	return w;
}

int Nave::ObtenerH()
{
	return h;
}
void Nave::SetPasosLimite(int pasos)
{
	this->pasoLimite = pasos;
}
int Nave::ObtenerPasoActual()
{
	return pasoActual;
}
void Nave::IncrementarPasoActual(){
	pasoActual++;
}
bool Nave::EstaColicionando(Nave * b)
{
	return false;
}