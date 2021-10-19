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
	do{
		if (utn_pedirIntAUsuarioConLimites(&menu, 0, 4, 3, "Ingrese Numero Segun Corresponda\n1.-Alta Empleado\n2.-Modificar datos de Empleado\n3.-Baja de Empleado\n4.-Informes \n0.-Salir de Sistema\n\n", "Error")==-1)
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
						if(findEmployeeById(arrayEmployee, EMPLOYEES_LEN, auxModificar, &auxIsFree)==0)
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
