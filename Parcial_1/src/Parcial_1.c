/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#include "salon.h"
#include "arcade.h"
#include "salonArcade.h"
#define SALON_LEN 5
#define ARCADE_LEN 5
int main(void) {
	setbuf(stdout,NULL);
	int baja;
	Salon salones[SALON_LEN];
	Arcade arcades[ARCADE_LEN];
	sal_InciarLista(salones, SALON_LEN);
	arc_InciarLista(arcades, ARCADE_LEN);
	sal_harcode(salones,0,0,"AAAA","caboto715",SHOPPING,0);
	sal_harcode(salones,1,1,"BBBB","caboto800",LOCAL,0);
	sal_harcode(salones,2,2,"CCCC","caboto900",LOCAL,0);
	sal_ImprimirTodos(salones, SALON_LEN);
	arc_harcode(arcades, 0, 0, "ARG", 4, 2, 3, "ZELDA", 0,0);
	arc_harcode(arcades, 1, 1, "PER", 5, 2, 2, "MARIO", 0,1);
	arc_harcode(arcades, 2, 2, "ALM", 4, 2, 1, "CONTRA", 0,2);
	arc_ImprimirTodos(arcades, ARCADE_LEN);

	arc_Alta(arcades, ARCADE_LEN, salones, SALON_LEN);
	arc_ImprimirTodos(arcades, ARCADE_LEN);
	utn_getInt(&baja, "ingrese id bja", "error", 0, 50, 2);
	sal_DarBajaId(salones, SALON_LEN, baja, ARCADE_LEN, arcades);
	arc_ImprimirTodos(arcades, ARCADE_LEN);
	sal_ImprimirTodos(salones, SALON_LEN);




	return EXIT_SUCCESS;
}
