#include "Nave.h"
#include "config.h"
Nave::Nave(SDL_Surface*screen, char*rutaImagen, int x, int y, int module)
{
	nave = new Objeto(screen, rutaImagen, x, y, module);
	for (int i = 0; i < MAXIMO_DE_BALAS; i++)
	{
		bala[i] = new Objeto(screen, "../Data/balas.bmp", 0, 0, MODULO_BALAS_BALA);
		bala[i]->SetVisible(false);
	}
	balaVisible = 0;
	visible = true;
	colision = false;
}
void Nave::crearNuevo()
{
	balaVisible = 0;
	visible = true;
	colision = false;
	for (int i = 0; i < MAXIMO_DE_BALAS; i++)
	{
		bala[i]->SetVisible(false);
	}
	nave->ponerEn(0, 0);
}

void Nave::Disparar(int tipoNave ,int balas){

	if (visible)
	{
		bala[balaVisible]->SetVisible(true);
		switch (tipoNave)
		{
		case NAVE_PROPIA:
			bala[balaVisible]->ponerEn(nave->ObtenerX() + nave->ObtenerW() / 2, nave->ObtenerY());
			break;

		case NAVE_ENEMIGO:
			bala[balaVisible]->ponerEn(nave->ObtenerX() + nave->ObtenerW() / 2, nave->ObtenerY() + nave->ObtenerH());
			break;
		}
		balaVisible++;

		if (balaVisible >= balas)
			balaVisible = 0;
	}
}

void Nave::Pintar(int tipoNave)
{
	if (visible){
		nave->Pintar();
		for (int i = 0; i < MAXIMO_DE_BALAS; i++)
		{
			bala[i]->Pintar();
			switch (tipoNave)
			{
			case NAVE_PROPIA:
				bala[i]->Mover1(-10);
				break;

			case NAVE_ENEMIGO:
				bala[i]->Mover1(10);
				break;
			}
		}
	}
}
void Nave::MoverAbajo(int velocidad)
{
	nave->Mover1(velocidad);
}
void Nave::MoverArriba(int velocidad)
{
	nave->Mover1(-velocidad);
}
void Nave::MoverDerecha(int velocidad)
{
	nave->Mover(velocidad);
}
void Nave::MoverIzquierda(int velocidad)
{
	nave->Mover(-velocidad);
}
Objeto*Nave::GetNaveObjeto()
{
	return nave;
}
void Nave::AutoDisparar(int balas)
{
	if ((rand()%100)<2)
	     Disparar(NAVE_ENEMIGO,balas);
	//aqui
}
void Nave::setVisible(bool visible)
{
	this->visible = visible;
}

bool Nave::estaColisionandoConBala(Nave * nave){
	return this->colision;
}

void Nave::simularColision(bool colision)
{
	this->colision = colision;
}