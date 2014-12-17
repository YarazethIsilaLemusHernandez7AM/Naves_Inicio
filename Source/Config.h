//#pragma once //lo que esta a delante solo lo carga una vez (solo se usa en windows)
#ifndef __CONFIG_H__//PARA DEFINICION
#define __CONFIG_H__//
//codigo de procesamiento 
#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480

#define BORDE_IZQUIERDO 1<<0
#define BORDE_SUPERIOR  1<<1
#define BORDE_DERECHO   1<<2
#define BORDE_INFERIOR  1<<3

#define FPS_LIMIT 30.0f
#define FPS_DELAY 1000.0F/ FPS_LIMIT
/*SPRITES*/
//#TIPO_IMGEN_NOMBRE
#define MODULO_MINAVE_NAVE                       0
#define MODULO_FONDOJUEGO_FONDO                  1
#define MODULO_ENEMIGO_NAVE                      2
#define MODULO_TEXTOS_TITULOS                    3
#define MODULO_TEXTO_NOMBRE                      4
#define MODULO_TEXTO_MENU_INICIAR1               5
#define MODULO_TEXTO_MENU_SALIR1                 6
#define MODULO_TEXTO_MENU_INICIAR2_SELECCIONADO  7
#define MODULO_TEXTO_MENU_SALIR2_SELECCIONADO    8
#define MODULO_BALAS_BALA                        9

#define MAXIMO_DE_BALAS 30

#define NAVE_PROPIA  0
#define NAVE_ENEMIGO 1

#endif 
