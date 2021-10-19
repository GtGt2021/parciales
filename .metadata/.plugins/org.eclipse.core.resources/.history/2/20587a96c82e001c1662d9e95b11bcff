/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "ArrayEmployees.h"
#define VACIO 0
#define OCUPADO 1
#define LASTNAME_LEN 51
#define NAME_LEN 51

static int getId(void);
static int cantidadEmpleadosMayorMedia(Employee lista[], int len, float promedio);
static int promedioEmpleados(Employee lista[], int len, float *acumulador, float *promedio);

/**brief nos genera un id nuevo consecutivo cuando se invoca ( en este caso comienza a partir del 1000 en adelante)
 * param (no recibe nada)
 * return retorna un entero positivo que se usa como id "SOLO PARA USAR EN ESTA BIBLIOTECA"
 */
static int getId(void)
{
	static int counter=1000;
	return (counter++);
}

/**brief nos inicializa todo el array colocando en la posicion isEmpty un 0 para indicar lugar Libre
 * param recibe el array de la estructura completa y el tamaño del mismo
 * return retorna -1 si por algun error en el array o tamaño no se pudo inicializar y 0 si fue exitoso
 */
int init_employees(Employee* list, int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			list[i].isEmpty_employee=VACIO; // posicion Libre
		}
		retorno=0;
	}
	return retorno;
}

/**brief cargamos la info del empleado a una pocision de la estructura, tomamos una posicion libre en gen_eslibre la guardamos en auxIsFree
 * copiamos los datos en cada uno de los campos sector nombre apellido id salario y colocamos como ocupada la posicion isempty
 *param lista completa tamaño de la lista id, nombre, apellido, salario y sector del empleado a cargar ya previamente validado
 *return 0 si la carga fue ok -1 si por algo hubo un error
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno=-1;
	int auxIsFree;
	if (list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>=1 && sector<=6)
	{
		if (gen_esLibre(list, len, &auxIsFree)==0)
		{
			list[auxIsFree].sector_gen=sector;
			list[auxIsFree].salary_employee=salary;
			strncpy(list[auxIsFree].name_employee, name, sizeof(list[auxIsFree].name_employee));
			strncpy(list[auxIsFree].lastName_employee, lastName, sizeof(list[auxIsFree].lastName_employee));
			list[auxIsFree].isEmpty_employee=OCUPADO;
			list[auxIsFree].id_employee=id;
			retorno=0;
		}

	}
	return retorno;
}
/**brief verificamos si hay espacio (isempty LIBRE) donde escribir en la lista de ser asi llamamos a la funcion getData para cargar la info del empleado nuevo
 * si todo esta bien generamos un id y llamamos a la funcion add para escribir la info del empleado una posicion en la lista
 *param array de employe y el tamaño
 *return -3 si hay fallas en el archivo -2 si la memoria o la lista esta llena -1 si ingreso mal los datos en varias ocasiones y 0 si todo salio ok
 */

int loadEmployee(Employee* list, int len)
{
	int retorno=-3;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	int sector;
	float salary;
	int id;
	if (list!=NULL && len>0)
	{
		if (isFree(list, len)>=0)
		{
			if(getDataEmployee(name, lastName, &sector, &salary)==0)
			{
				id=getId();
				addEmployee(list, len, id, name, lastName, salary, sector);
				retorno = 0; // printf ("Cargado con Exito")
			}
			else
			{
				retorno = -1; //printf("error al ingresar datos");
			}
		}
		else
		{
			retorno= -2; //printf("Memoria Llena, No hay espacio para mas Empleados");
		}

	}

	return retorno;
}
/**brief funcion sencilla que se dedica a pedir la info necesaria para cargar los campos de los empleados nombre apellido sector salario
 *
 * return retorna 0 si todos los datos se cargaron ok y -1 si hubo algun error
 */

int getDataEmployee(char name[], char lastName[], int *sector, float *salary)
{
	int retorno=-1;
	if (name!=NULL && lastName!=NULL && sector!=NULL && salary!=NULL)
	{
		if (utn_pedirIntAUsuarioConLimites(sector, 1, 6, 3, "ingresar numero sector: (Sector 1-2-3-4-5-6):", "Error.\n")==0)
		{
			if(utn_pedirFloatPositivoAUsuario(salary, 3, "Ingrese Salario: \n", "Error.\n")==0)
			{
				if(utn_pedirNombreYApellidoAUsuario(name, NAME_LEN, 3, "Ingrese Nombre: (solo Letras)", "Error.\n")==0)
				{
					if(utn_pedirNombreYApellidoAUsuario(lastName, LASTNAME_LEN, 3, "Ingrese apellido: (solo Letras)", "Error.\n")==0)
					{
						retorno=0;
					}
				}
			}
		}
	}

	return retorno;
}

/**brief recibimos una posicion de la estructura y la llenamos con los datos que nos da el usuario, el sistema completa
 * con 1 el lugar isEmpty para indicar que esta ocupado y invoca la funcion generarId para darnos un Id nuevo
 * param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si por algun error en el array o tamaño no se pudo inicializar y 0 si fue exitosa la carga de "TODOS LOS DATOS"
 */
/*int addEmployee2(Employee list[])
{
	int sector;
	float salario;
	char nombre [NAME_LEN];
	char apellido [LASTNAME_LEN];
	int retorno=-1;
	if (list!=NULL)
	{
		if (utn_pedirIntAUsuarioConLimites(&sector, 1, 6, 3, "ingresar numero sector: (Sector 1-2-3-4-5-6):", "Error.\n")==0)
			{
				if(utn_pedirFloatPositivoAUsuario(&salario, 3, "Ingrese Salario: \n", "Error.\n")==0)
				{
					if(utn_pedirNombreYApellidoAUsuario(nombre, 3, "Ingrese Nombre: (solo Letras)", "Error.\n")==0)
					{
						if(utn_pedirNombreYApellidoAUsuario(apellido, 3, "Ingrese apellido", "Error.\n")==0)
						{
							list->sector_gen=sector;
							list->salary_employee=salario;
							strncpy(list->name_employee, nombre, sizeof(list->name_employee));
							strncpy(list->lastName_employee, apellido, sizeof(list->lastName_employee));
							list->id_employee=disp_nuevoId();
							list->isEmpty_employee=OCUPADO;
							retorno=0;
						}
					}
				}
			}
	}

	return retorno;
}
*/

/**brief recibimos una posicion de la estructura con su informacion
 * verificamos isEmpty=1 si esta ocupada IMPRIME SU INFORMACION
 *  param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int printPosition(Employee *posicion)
{
	int retorno=-1;
	if (posicion!=NULL)
	{
		if(posicion->isEmpty_employee==1)
		{
			printf("\nID: %d\t nombre: %-10s\t apellido: %-5s\t sector: %d\t salario:%.2f\n", posicion->id_employee, posicion->name_employee, posicion->lastName_employee, posicion->sector_gen, posicion->salary_employee);
			retorno = 0;
		}
	}
	return retorno;
}

/**brief recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For todo el array y
 * llamamos a la funcion que imprime por posicion
 *  param Lista completa del array estructura y el tamaño
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int printEmployees(Employee list[], int len)
{
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			printPosition(&list[i]);
		}
		retorno=0;
	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el id buscado sea un int positivo
 * recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For por todo el array y
 * primero comparamos que la posicion este ocupada isempty=1 y luego preguntamos si el id de esa posicion es igual
 * al id buscado y retornamos por puntero la posicion en la que esta el id
 *  param recibo el array de la estructura el tamaño del array el id qu buscamos retornamos por puntero la posicion del id buscado
 * return retorna -1 si la posicion el array de la estructura viene con errores el id o el tamaño del array son menores a 0
 *  y 0 si fue encontrado el id
 */
int findEmployeeById(Employee list[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_employee==OCUPADO && list[i].id_employee==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

/**brief recibimos una pocision del array de la estructura
 * validamos que el puntero este bien y pedimos al usuario mediane un menu que desea modificar vamos al suitch y modificamos
 * lo que el usuario quiere
 *  param recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores o se ingreso mal la opcion del menu
 *  y 0 si fue exitosa la MODIFICACION
 */
int gen_modificarLista(Employee lista[])
{
	int sector;
	float salario;
	char nombre [NAME_LEN];
	char apellido [LASTNAME_LEN];
	int retorno=-1;
	int menu;
	if (lista!=NULL && utn_pedirIntAUsuarioConLimites(&menu, 1, 4, 3, "Ingrese Numero segun lo que desee Modificar: \n 1-sector \n 2-Salario \n 3-Nombre \n 4-apellido", "Error, no es una opcion")==0)
	{

		switch (menu)
			{
			case 1:
				if (utn_pedirIntAUsuarioConLimites(&sector, 1, 6, 3, "Ingrese sector(ingresar numero: (Sector 1-2-3-4-5-6)", "Error")==0)
				{
					lista->sector_gen=sector;
					retorno=0;
				}
				break;
			case 2:
				if(utn_pedirFloatPositivoAUsuario(&salario, 3, "Ingrese Salario Empleado: \n", "Error.\n")==0)
				{
					lista->salary_employee=salario;
					retorno=0;
				}
				break;
			case 3:
				if(utn_pedirNombreYApellidoAUsuario(nombre, NAME_LEN, 3, "Ingrese Nombre: \n", "Error.\n")==0)
				{
					strncpy(lista->name_employee, nombre, sizeof(lista->name_employee));
					retorno=0;
				}
				break;
			case 4:
				if(utn_pedirNombreYApellidoAUsuario(apellido, LASTNAME_LEN, 3, "Ingrese apellido\n", "Error.\n")==0)
				{
					strncpy(lista->lastName_employee, apellido, sizeof(lista->lastName_employee));
					retorno=0;
				}
				break;
			}
	}

	return retorno;
}


int isFree(Employee list[], int len)
{
	// devuelve -2 si la falla es error de array o tamaño del array
	int retorno=-2;
	if (list!=NULL && len>0)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (list[i].isEmpty_employee==VACIO)
			{
				retorno=i; //devuelve el indice de la primera posicion libre
				break;
			}
		}

	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el puntero a la posicion libre sea != NULL tambien
 * recorremos el array en todo su tamaño y en la primera casilla que encontremos desocupada isempty=0  retornamos
 * por puntero la posicion libre y hacemos un break para salir del for y no seguir iterando
 *  param recibo el array de la estructura el tamaño del array y el puntero de la posicion libre
 * return retorna -2 si el array de la estructura  o el puntero posicionLibre viene con errores  o el tamaño del array es menor a 0
 *  -1  si la memoria esta llena y 0 si fue encontrada una casilla libre
 */
int gen_esLibre(Employee lista[], int len, int *posicionLibre)
{
	// devuelve -2 si la falla es error de array o tamaño del array
	int retorno=-2;
	if (lista!=NULL && len>0 && posicionLibre!=NULL)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (lista[i].isEmpty_employee==VACIO)
			{
				*posicionLibre=i; //devuelve el indice de la primera posicion libre
				retorno=0; // 0 si se consiguio
				break;
			}
		}

	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array y el id para dar de baja mayor q 0
 * llamamos a la funcio buscar ID para que nos de la poscion en la que esta el id que queremos borrar
 * en la misma funcion preguntamos si es 0 es priqeu encontro el id y de ser asi cambiamos el estado para esa posicion de
 * isempty a 0 es decir queda libre
 *  param recibo el array de la estructura el tamaño del array y el id que se quiee elimimnar
 * return retorna -2 si el array de la estructura viene con errores, el tamaño del array  o el id para dar baja es menor a 0
 *  0 si fue dado de baja (SI NO SE ENCONTRO EL ID RETORNA -1)
 */
int removeEmployee(Employee lista[], int len, int idParaDarBaja)
{
	int retorno=-2;
	int i;
	if (lista!=NULL && len>0 && idParaDarBaja>0)
	{
		retorno=-1;
		if (findEmployeeById(lista, len, idParaDarBaja, &i)==0)
		{
			lista[i].isEmpty_employee=VACIO;
			retorno=0;
		}

	}
	return retorno;
}
/**
 * brief recorremos el array para ver si tiene informacion cargada es decir si isEmpty= 1 en alguna posicion
 * apenas enccuenta una posicion conrta el for con un break y nos devuelve un mensaje que nos indica que si tiene info el mismo
 * param array estructura y el tamaño del array
 * return -1 si no encontro datos es decir el array esta vacio y retorna 0 si tiene al menos 1 dato cargado
 */
int gen_verificarQueTieneDatosLista(Employee lista[], int len)
{
	int retorno=-1;
	if (lista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (lista[i].isEmpty_employee==OCUPADO)
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}
/*
int gen_verificarIdExiste(Employee list[], int len, int idBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_employee==1 && list[i].id_employee==idBuscado)
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
*/
/**
*\ brief ingresa de manera forzada parametros a una posicion de la lista con el fin de poder
*\ realizar pruebas de manera mas rapida
*\ param lista[] es 1 posicion en el arrayEmployee
*\ return retorna 1 en caso de ser una cadena numerica (entero) y 0 si no lo es
*/
int gen_Altaforzada(Employee lista[], int sector, float salario, char nombre[], char apellido[])
{
	int retorno=-1;
	lista->sector_gen=sector;
	lista->salary_employee=salario;
	strncpy(lista->name_employee, nombre, sizeof(lista->name_employee));
	strncpy(lista->lastName_employee, apellido, sizeof(lista->lastName_employee));
	lista->id_employee=getId();
	lista->isEmpty_employee=1;
	retorno=0;

	return retorno;
}
/*brief recibimo el array de la  estructura y su tamaño adicionalmente nos envian un 1 para ordenar de manera ascendente y un 0 para ordenar de manera descendente
 *realizamos la svalidaciones correspondientes pero antes creamos un buffer del tipo Employee  para poder almacenar en el la info que vamos a mover al ordenar
 *recorremos con un for en la primera pocision y comparamos con las demas validando siempre que isEmpty este lleno  si queremos que sea
 *ascendete hacemos un strncomp donde validamos los apellidos
 *si nos da >0 (esto en el caso de hacerlo de manera Ascendente) movemos la info de la pocision anterior a la que se le comparo usando el auxEmployee para guardar
 *todos sus campos y no perder la info, luego si los apellidos son iguales strncomp==0 ordenamos por sector con una comparacion de si el primero es >que el que sigue
 *pasamos la info de esa posicion al auxEmployee copiamos la info del segundo en el primero y luego la info del auxiliar en el segundo (igual que hicmos antes pero no lo explique)
 *ahora si queremos hacerlo al contrario solo variamos el > de strncomp con un < y luego si el apellido es igual verificamos el sector de manera inversa es decir
 *cambiamos el > por <
 *param lista de Estructura Employee tamaño y el orden que queremos ordenar
 *return -1 si fallo 0 si todo OK
 */
int sortEmployed(Employee lista[], int len, int orden)
{
	int retorno =-1;
	Employee auxEmployee;
	int i; int j;
	if (lista!=NULL && len>0 && orden>=0 && orden<=1)
	{
		if (orden==1)
		{
			for (i=0; i<len-1; i++)
			{
				for (j=i+1; j<len; j++)
				{
					if ((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)>0)
					{
						auxEmployee=lista[i]; //movemos la pposicion i al aux
						lista[i]=lista[j]; // copiamos posicion j en i
						lista[j]=auxEmployee; // copiamos el aux en pocision j
					}
					else
						if((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)==0)
						{
							if(lista[i].sector_gen>lista[j].sector_gen) //validamos que el sector i es mas alto que el sector j
							{
								auxEmployee=lista[i]; //movemos la pposicion i al aux
								lista[i]=lista[j]; // copiamos posicion j en i
 								lista[j]=auxEmployee;// copiamos el aux en pocision j
							}
						}
				}
			}
		}
		else
		{
			if(orden==0)
			{
				for (i=0; i<len-1; i++)
				{
					for (j=i+1; j<len; j++)
					{
						if ((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)<0)
						{
							auxEmployee=lista[i]; //movemos la pposicion i al aux
							lista[i]=lista[j]; // copiamos posicion j en i
							lista[j]=auxEmployee; // copiamos el aux en pocision j
						}
						else
							if((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)==0)
							{
								if(lista[i].sector_gen<lista[j].sector_gen)
								{
									auxEmployee=lista[i];
									lista[i]=lista[j];
									lista[j]=auxEmployee;
								}
							}
					}
				}

			}
		}
		retorno = 0;
	}
	return retorno;
}
/**brief invoca dos funciones que calculan promedio, total de los salarios y otra que busca cuantos nganan sobre el promedio
 * luego imprime la info
 * param lista de la estructura con su tamaño
 * return -1 si hay algun error en el archvio 0 si imprimio todo bien
 */
int calcularsalarios(Employee lista[], int len)
{
	int retorno=-1;
	float acumulador;
	float promedio;
	int contadorPromedio;
	if (lista!=NULL && len>0)
	{
		promedioEmpleados(lista, len, &acumulador, &promedio);
		contadorPromedio=cantidadEmpleadosMayorMedia(lista, len, promedio);
		if (contadorPromedio==0)
		{
			printf("El Total Pagado en Salarios es de %.2f, el salario promedio %.2f, ningun empleado Gana sobre el promedio\n", acumulador, promedio);
		}
		else
		{
			if(contadorPromedio>0)
			{
				printf("El Total Pagado en Salarios es de %.2f, el salario promedio %.2f y %d empleados ganan sobre el promedio \n", acumulador, promedio, contadorPromedio);
			}
			else
			{
				printf("error en el Archivo");
			}
		}
		retorno=0;
	}
	return retorno;
}

/**brief recorremos el array si la casilla esta ocupada vamos acumulando el salario y contando cuantas veces  al final calculamos el promedio y el total lo devolvemos por punteros
 * param lista de la estructutra tamaño punteros a acumulador y promedio
 * return retorna -1 si hubo algun error en el archivo 0 si todo fue ok
 */
static int promedioEmpleados(Employee list[], int len, float *acumulador, float *promedio)
{
	int retorno=-1;
	float total=0;
	int contador=0;
	if (list!=NULL && len>0 && acumulador!=NULL && promedio!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if (list[i].isEmpty_employee==OCUPADO)
			{
				total=total+list[i].salary_employee;
				contador=contador+1;
			}
		}
		*acumulador=total;
		*promedio=total/contador;

	}
	return retorno;
}
/**brief recorremos el array preguntando si algun empleado gana mas del promedio y vamos contando los que superen este numero
 * param lista de la estructutra tamaño y el promedio del sueldo de los empleados
 * return retorna -1 si hubo algun error en el archivo 0 si ningun empleado gana mas de el promedio o el numero de empleados que ganan sobre el promedio
 */
static int cantidadEmpleadosMayorMedia(Employee lista[], int len, float promedio)
{
	int retorno=-1;
	if(lista!=NULL && len>0 && promedio>0)
	{
		retorno=0;
		for(int j=0; j<len; j++)
		{
			if (lista[j].isEmpty_employee==OCUPADO && lista[j].salary_employee>promedio)
			{
				retorno=retorno+1;
			}
		}
	}

	return retorno;
}

/*  gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
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
