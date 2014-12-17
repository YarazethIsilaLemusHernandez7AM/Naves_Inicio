#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado=estado_iniciado;//ACT2: Mal <--Aqui debes de establecer el estado inicial de tu juego.
	finestado = estado_finalizado;
	tiempoFrameInicial = 0;
	atexit(SDL_Quit);
	

}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete (nave);
	SDL_FreeSurface(screen);
	SDL_Quit();
}
void CGame::iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);
	if (screen == NULL){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("mi primer juego", NULL);
	nave = new Nave(screen, "../Data/MiNave.bmp", (WIDTH_SCREEN / 2), (HEIGHT_SCREEN - 80), MODULO_MINAVE_NAVE);
	menu = new Objeto(screen, "../Data/fondojuego.bmp", 0, 0,MODULO_FONDOJUEGO_FONDO);
	textos = new Objeto(screen,"../Data/textos.bmp",0,0,-1);
	fondo = new Objeto(screen, "../Data/fondo1.bmp", 0, 0, 1);
	for (int i = 0; i < 10; i++)
	{
		enemigoArreglo[i] = new Nave(screen, "../Data/enemigo.bmp", i*60, 0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->GetNaveObjeto()->Setautomovimiento(false);
		enemigoArreglo[i]->GetNaveObjeto()->SetPasosLimite(4);

	}
	tick = 0;
	opcionSelecionada = MODULO_TEXTO_MENU_INICIAR1;
}
bool CGame::Start()
{
	
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;    
	while (salirJuego == false){

            
		//Maquina de estados
		switch(estado){
		case Estado::estado_iniciado:
			printf("1. Estado_Iniciando\n");
			iniciando();
			//estado = estado_jugando;
			inicializandoStage();
			estado =estado_menu;

			break;
		case Estado::estado_menu:
			menu->Pintar();
			textos->Pintar(MODULO_TEXTOS_TITULOS,85,35);
			textos->Pintar(MODULO_TEXTO_MENU_INICIAR1, 200, 125);
			textos->Pintar(MODULO_TEXTO_MENU_SALIR1, 200, 235);
			textos->Pintar(MODULO_TEXTO_NOMBRE, 400, 430);
			Menu();

			break;
		case Estado::estado_pre_jugando:
			nivelActual = 0;
			vida = 1;
			enemigosEliminados = 0;
			estado = estado_jugando;
			break;
		case Estado::estado_jugando:
			for (int i = 0; i < 10;i++)
			{
				enemigoArreglo[i]->GetNaveObjeto()->Actualizar();
			}
			MoverEnemigo();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_DERECHO))
					nave->MoverDerecha(nivel[nivelActual].VelocidadNavePropia);
			}//los 3 casos son el priero aplicado a las demas direcciones
			if (keys[SDLK_LEFT])
			{ 
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_IZQUIERDO))
					nave->MoverIzquierda(nivel[nivelActual].VelocidadNavePropia);
			}
			if (keys[SDLK_UP])
			{ 
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_SUPERIOR))
					nave->MoverArriba(nivel[nivelActual].VelocidadNavePropia);
			}
			if (keys[SDLK_DOWN])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_INFERIOR))
					nave->MoverAbajo(nivel[nivelActual].VelocidadNavePropia);
			}
			if (keys[SDLK_SPACE])
			{
				nave->Disparar(NAVE_PROPIA,nivel[nivelActual].balasMaximas);
			}
			fondo->Pintar();
			nave->Pintar(NAVE_PROPIA);
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Pintar(NAVE_ENEMIGO);
				enemigoArreglo[i]->AutoDisparar(nivel[nivelActual].balasMaximas);
			}
			for (int i = 0; i < 10; i++){
				enemigoArreglo[i]->Pintar(NAVE_ENEMIGO);
			}
			/*if (keys[SDLK_HOME])
			{
				estado = estado_terminado;

				printf("3. Estado_Jugando\n");
			}*/
			if (keys[SDLK_ESCAPE])
			{
				estado = Estado::estado_menu;
			}
			///////////////////////////////////////
			if (keys[SDLK_x]){//bala enemigo / nave nuestra
				nave->simularColision(true);
			}

			if (keys[SDLK_c]){//nuestra bala / nave enemigo
				int enemigoAEliminar = rand() % nivel[nivelActual].NumeroEnemigosVisibles;
				enemigoArreglo[enemigoAEliminar]->simularColision(true);
			}
			if (keys[SDLK_v]){//nuestra nave / nave enemigo

			}

			fondo->Pintar();
			////////////////////////////////////////
			//////// CONTROL DE COLISIONES /////////
			for (int i = 0; i < nivel[nivelActual].NumeroEnemigosVisibles; i++)
			{
				if (enemigoArreglo[i]->estaColisionandoConBala(nave))
					vida--;
				if (nave->estaColisionandoConBala(enemigoArreglo[i])){
					enemigoArreglo[i]->setVisible(false);
					enemigosEliminados++;
					nave->simularColision(false);
					if (enemigosEliminados<nivel[nivelActual].NumeroEnemigosEliminar)
					{
						enemigoArreglo[i]->crearNuevo();
					}
				}
			}
			/////////////////////////////////////////
			if (vida <= 0)
				estado = estado_menu;

			if (enemigosEliminados >= nivel[nivelActual].NumeroEnemigosEliminar)
			{
				nivelActual++;
			}
			nave->Pintar(NAVE_PROPIA);
			for (int i = 0; i < nivel[nivelActual].NumeroEnemigosVisibles; i++)
			{
				enemigoArreglo[i]->Pintar(NAVE_ENEMIGO);
				enemigoArreglo[i]->AutoDisparar(nivel[nivelActual].velocidadBalasEnemigo);
			}
			break;
		case Estado::estado_terminado:
			printf("4. Estado_Terminando\n");
			salirJuego = false;
			estado = estado_menu;
			finestado= estado_menu;
			break;
		case Estado::estado_finalizado:
			printf("5. Estado_Finalizando\n");
			salirJuego = true;
			getchar();
			break;
		};
		//provicionamente
		while (SDL_PollEvent(&event))//aqui sdl creara una lista de eventos ocurridos
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }//si se detecta una salida de sdl o...
			if (event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen);
		tiempoFramefinal = SDL_GetTicks();
		while (tiempoFramefinal < (tiempoFrameInicial + FPS_DELAY)){
			SDL_Delay(1);
			tiempoFramefinal = SDL_GetTicks();
		}
		printf("Frame:%d Tiempo:%d Tiempo promedio:%f Tiempo por frame:%d  FPS:%f\n", tick, SDL_GetTicks(), (float)SDL_GetTicks() / (float)tick, tiempoFramefinal - tiempoFrameInicial, 1000.0f / (float)(tiempoFramefinal - tiempoFrameInicial));
		tiempoFrameInicial = tiempoFramefinal;
		tick++;
    }
	return true;
}
bool CGame::EsLimitePantalla(Objeto * objeto, int bandera){
	/*if (bandera & BORDE_IZQUIERDO)
		if (obejeto->ObtenerX() <= 0)
			return true;
	if (bandera & BORDE_SUPERIOR)
		if (obejeto->ObtenerY() <= 0)
			return true;
	if (bandera & BORDE_DERECHO)
		if (obejeto->ObtenerX() >= WIDTH_SCREEN - obejeto -> ObtenerW())
			return true;
	if (bandera & BORDE_INFERIOR)
	    if (obejeto->ObtenerY() >= HEIGHT_SCREEN - obejeto->ObtenerH())
		return true;
	return false;*/
	if (bandera & BORDE_IZQUIERDO)
		if (objeto->ObtenerX() <= 0)
			return true;
	if (bandera & BORDE_SUPERIOR)
		if (objeto->ObtenerY() <= 0)
			return true;

	if (bandera & BORDE_DERECHO)
		if (objeto->ObtenerX() >= (WIDTH_SCREEN - objeto->ObtenerW()))
			return true;
	if (bandera & BORDE_INFERIOR)
		if (objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH())
			return true;
	return false;
}
void CGame::MoverEnemigo(){



	for (int i = 0; i < 10; i++)
	{
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 0)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_DERECHO))
				enemigoArreglo[i]->GetNaveObjeto()->Mover(nivel[nivelActual].VelocidadNaveEnemigo);
			else
			{
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 1)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_INFERIOR))
				enemigoArreglo[i]->GetNaveObjeto()->Mover1(nivel[nivelActual].VelocidadNaveEnemigo);
			else
			{
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 2)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_IZQUIERDO))
				enemigoArreglo[i]->GetNaveObjeto()->Mover(-nivel[nivelActual].VelocidadNaveEnemigo);
			else
			{
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 3)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_SUPERIOR))
				enemigoArreglo[i]->GetNaveObjeto()->Mover1(-nivel[nivelActual].VelocidadNaveEnemigo);
			else
			{
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}

	}

}
void CGame::Menu()
{

	for (int i = MODULO_TEXTO_MENU_INICIAR1, j = 0; i <= MODULO_TEXTO_MENU_SALIR1; i++, j++)
	{
		keys = SDL_GetKeyState(NULL);
		if (keys[SDLK_UP])
		{
			opcionSelecionada = MODULO_TEXTO_MENU_INICIAR1;
			/*if (i == opcionSelecionada)
				textos->Pintar(i + 2, 200, 125 + (j * 40));
			else
				textos->Pintar(i, 200, 235 + (j * 15));*/

		}
		if (keys[SDLK_DOWN])
		{
			opcionSelecionada = MODULO_TEXTO_MENU_SALIR1;
			/*if (i == opcionSelecionada)
				textos->Pintar(i +2, 200,125 + (j * 60));
			else
				textos->Pintar(i, 200, 235 + (j * 40));
							textos->Pintar(MODULO_TEXTO_MENU_INICIAR1, 200, 125);
			textos->Pintar(MODULO_TEXTO_MENU_SALIR1, 200, 235);*/
		
		}
		if (i == opcionSelecionada)
			textos->Pintar(i + 2, 200, 130 + (j * 60));
		else
			textos->Pintar(i, 200, 175 + (j * 80));

		if (keys[SDLK_SPACE])
		{
			if (opcionSelecionada == MODULO_TEXTO_MENU_INICIAR1)
			{
				estado = Estado::estado_pre_jugando;
			}

			if (opcionSelecionada == MODULO_TEXTO_MENU_SALIR1)
			{
				estado = Estado::estado_finalizado;
			}
		}
	}
}
