
#include <SDL_image.h>
#include "Nave.h"
class CGame
{
public:
	enum Estado{
		estado_iniciado,
		estado_menu,
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
	Nave*textos;
	Nave *menu;
	Nave* fondo;
	int opcionSelecionada;
	Uint8 *keys;//estavariable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;//la ariable event de tipo eventode sdl nos servira para motorizar el
	SDL_Surface* screen;
	Nave* nave;
	Nave *enemigoArreglo [10];
	Estado estado;
	Estado finestado;
	bool EsLimitePantalla(Nave * obejto, int bandera);
	void MoverEnemigo();
	
};