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
#define SALON_LEN 5
int main(void) {
	setbuf(stdout,NULL);
	Salon salones[SALON_LEN];
	sal_InciarLista(salones, SALON_LEN);
	sal_harcode(salones,0,0,"AAAA","caboto715",SHOPPING,0);
	sal_harcode(salones,1,1,"BBBB","caboto800",LOCAL,0);
	sal_harcode(salones,2,2,"CCCC","caboto900",LOCAL,0);
	sal_ImprimirTodos(salones, SALON_LEN);


	return EXIT_SUCCESS;
}
