/*
 ============================================================================
 Name        : cagada.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "ArrayEmployees.h"
#include "ListEmployees.h"

#define EMPLOYEES_LEN 1000
int main(void) {
	setbuf(stdout,NULL);
	int menu=0;
	int auxIsFree;
	int auxModificar;
	int errorRetorno;
	Employee arrayEmployee[EMPLOYEES_LEN];
	init_employees(arrayEmployee, EMPLOYEES_LEN);

/*		gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
		gen_Altaforzada(&arrayEmployee[1], 2, 456, "Alberto", "padron");
		gen_Altaforzada(&arrayEmployee[2], 2, 451, "maximiliano", "mendoza");
		gen_Altaforzada(&arrayEmployee[3], 6, 526, "mariana", "gonzalez");
		gen_Altaforzada(&arrayEmployee[4], 5, 123, "jorg", "labrador");
		gen_Altaforzada(&arrayEmployee[8], 3, 122, "Gust", "vargas");
		gen_Altaforzada(&arrayEmployee[9], 2, 456, "Alber", "padron");
		gen_Altaforzada(&arrayEmployee[45], 1, 451, "maxi", "mendoza");
		gen_Altaforzada(&arrayEmployee[80], 4, 526, "maria", "gonzalez");
		gen_Altaforzada(&arrayEmployee[58], 5, 123, "jorgna", "labrador");
		gen_Altaforzada(&arrayEmployee[85], 3, 122, "Gustvo", "vargas");
		gen_Altaforzada(&arrayEmployee[71], 2, 456, "Alo", "padron");
		gen_Altaforzada(&arrayEmployee[73], 2, 451, "maximo", "mendoza");
		gen_Altaforzada(&arrayEmployee[72], 1, 526, "marian", "gonzalez");
		gen_Altaforzada(&arrayEmployee[98], 2, 123, "jorgina", "labrador");
		gen_Altaforzada(&arrayEmployee[98], 4, 122, "Gustavo", "vargas");
	    gen_Altaforzada(&arrayEmployee[78], 5, 456, "Alberto", "padron");
		gen_Altaforzada(&arrayEmployee[77], 3, 451, "maximiliano", "mendoza");
		gen_Altaforzada(&arrayEmployee[66], 5, 526, "mariana", "gonzalez");
		gen_Altaforzada(&arrayEmployee[55], 6, 123, "jorgina", "labrador");*/
	do{
		if (utn_pedirIntAUsuarioConLimites(&menu, 0, 4, 3, "Ingrese Numero Segun Corresponda\n1.-Alta Empleado\n2.-Modificar datos de Empleado\n3.-Baja de Empleado\n4.-Informes \n0.-Salir de Sistema\n", "Error")==-1)
			{
				printf("Saliendo de Sistema...");
				break;
			}

		switch (menu)
		{
			case 1:
				errorRetorno=loadEmployee(arrayEmployee, EMPLOYEES_LEN);
				switch (errorRetorno)
				{
				case -1:
					printf("Error al ingresar Datos\n");
					break;
				case -2:
					printf("Memoria Llena, No hay espacio para mas Empleados\n");
					break;
				case -3:
					printf("Error en Archivo\n");
					break;
				case 0:
					printf("Empleado Cargado Exitosamente\n");
					break;
				}
				break;
			case 2:
				if (gen_verificarQueTieneDatosLista(arrayEmployee, EMPLOYEES_LEN)==0)
				{
					printEmployees(arrayEmployee, EMPLOYEES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxModificar, 3, "Ingrese el Id del Empleado a Modificar", "Error")==0)
					{
						auxIsFree=findEmployeeById(arrayEmployee, EMPLOYEES_LEN, auxModificar);
						if(auxIsFree>=0)
						{
							gen_modificarLista(&arrayEmployee[auxIsFree]);
						}
						else
						{
							printf("ID NO EXISTE\n");
						}
					}
					else
					{
						printf("Errores Consecutivos al Ingresar Datos, Volviendo al Menu Principal\n");
					}
				}
				else
				{
					printf("No tienes Ningun Empleado Cargado en Sistema");
				}
				break;
			case 3:
				if (gen_verificarQueTieneDatosLista(arrayEmployee, EMPLOYEES_LEN)==0)
				{
					printEmployees(arrayEmployee, EMPLOYEES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxIsFree, 3, "Ingrese Id Empleado a Dar de Baja", "Error")==0)
					{
						if(removeEmployee(arrayEmployee, EMPLOYEES_LEN, auxIsFree)==0)
						{
							printf("BAJA DEL ID %d EXITOSA \n", auxIsFree);;
						}
						else
						{
							printf("ID NO EXISTE\n");
						}
					}
					else
					{
						printf("Errores Consecutivos al Ingresar Datos, Volviendo al Menu Principal\n");
					}
				}
				else
				{
					printf("No tienes Ningun Empleado Cargado en Sistema");
				}
				break;
			case 4:
				if (gen_verificarQueTieneDatosLista(arrayEmployee, EMPLOYEES_LEN)==0)
				{
					menuParaImprimirInformes(arrayEmployee, EMPLOYEES_LEN);
				}
				else
				{
					printf("No tienes Ningun Empleado Cargado en Sistema");
				}
				break;
		}
		}while(menu!=0);



	return EXIT_SUCCESS;
}
