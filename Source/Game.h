
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
	unsigned int x;
	Uint8 *keys;//estavariable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;//la ariable event de tipo eventode sdl nos servira para motorizar el
	SDL_Surface* screen;
	Nave* nave;
	Estado estado; 
	
};