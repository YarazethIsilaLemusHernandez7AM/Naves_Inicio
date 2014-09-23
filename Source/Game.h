
#include <SDL_image.h>
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
	SDL_Surface* screen;
	SDL_Surface* nave;
	Estado estado; 
	
};