#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList)); //creo un espacio en memoria para el linkedlist le retorno la posicion
    if(this!=NULL)
    {
    	this->size=0; //inicializo TAMAÑO EN 0
    	this->pFirstNode=NULL; // la primera posicion la defino en NULL (NO APUNTA A NADIE)
    }
    return this; //devuelvo el puntero a la lista linked
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) // recibo la lista ll
{
    int returnAux = -1; // retorno -1 si no existe la lista
    if(this!=NULL) //valido
    {
    	returnAux=this->size; // leo en el LL el campo SIZE y retorno el Valor ASI DE FACIL  (si regresa 0 es porque no tiene ni 1 noodo)
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeaux=NULL; // creo un puntero a nodo a obtener
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)) // valido (el nodeIndex no puede ser ni mayor ni igual al tamaño de la lista)
	{
		pNodeaux=this->pFirstNode; //tomo el primer valor del campo queesta en el LinkedL la cabesera y lo guardo en el nodoaux
		for (int i=0; i<nodeIndex; i++) // recorro la lista hasta la posicion menor al nodoindex
		{
			pNodeaux=pNodeaux->pNextNode; //encontre el nodo guarde su posicion en memoria y la retorno
		}

	}
    return pNodeaux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) //recibo un elemento a guardar en el nodo de la lista (mas lista y el index donde crearemos el nodo)
{
    int returnAux = -1; //-1 si la validacion requerida falla o no se creo el espacio en memoria para el nodo

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))// VALIDOOOOOOOOOOOOOOO
    {
    	Node* pNodeauxNew=(Node*)malloc(sizeof(Node)); //creo un espacio en memoria para el nuevo nodo
    	Node* nodeAuxAnt; // creo otro nodo Auxiliar para almacenar
    	if(pNodeauxNew!=NULL) // solo si se pudo crear el espacio en memoria para el NUEVO NODO CONTINUO
    	{

    		if(nodeIndex==0) // si me piden ingresarlo en la posicion 0 tengo que modificar la cabesera LinkedL
    		{
    			nodeAuxAnt=this->pFirstNode; //guardamos en el nodeauxant la direccion de memoria que estaba en la cabeza del LinkedL
    			this->pFirstNode=pNodeauxNew; // en la cabezara guardamos la direccion del nuevo nodo
    			pNodeauxNew->pNextNode=nodeAuxAnt; // al nuevo nodo le cargamos lo que tenia la cabezera para apuntar al nodo que sigue la lista
    		}
    		else // el nodo index es mayor a 0
    		{
    				nodeAuxAnt=getNode(this, nodeIndex-1); // pido el nodo anterior al index
    				pNodeauxNew->pNextNode=nodeAuxAnt->pNextNode;  // el nuevo nodo apuntara al que apuntaba antes el nodeAuxAnt
    				nodeAuxAnt->pNextNode=pNodeauxNew; // y el nodeAuxAnt apunta al nuevo nodo
    		}
    		pNodeauxNew->pElement=pElement; // guardamos el elemento en el nuevo nodo creado
    		this->size++; // aumentamos tamaño de la lista
    		returnAux=0; // chaolin retorno EXITOSO
    	}

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) // recibo elemento a guardar en el nuevo nodo
{
    int returnAux = -1; // retorno error
    if(this!=NULL) // valido lista
    {
    	returnAux=addNode(this, this->size, pElement); // agrego nuevo nodo al final de la lista  this->size si retorna 0 esa funcion es exitosa
    }
    return returnAux; // retorno 0 si lo agrego o -1 si fallo
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) // pido un elemento en una possicion index de la Linked
{
    void* returnAux = NULL; // creo puntero para retornar el elemento lo inicializo en NULL porque si falla regreso un NULL
    Node* nodeAux=getNode(this, index); // creo un nodoAux para sacar la info de la lista y asi poder accesar al elemento

    if(this!=NULL && index>=0 && index<ll_len(this)) //valido
    {

    	if(nodeAux!=NULL) // si el nodo Auxiliar es distinto de null es decir se consiguio
    	{
    		returnAux=nodeAux->pElement; // guardo el puntero a su elemento y lo  retorno
    	}

    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) // recibimos el elemento a setear la lista y el index
{
    int returnAux = -1; // si falla la validacion
    if(this!=NULL && index>=0 && index<ll_len(this)) //validamos
    {

    	Node *nodeASetear=getNode(this, index); //llamamos el nodo a setear el elemento
    	if(nodeASetear!=NULL) // si el get nodo nos devuelve NULL no seteamos
    	{
    		nodeASetear->pElement=pElement; // seteamos el elemento
    	}
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) // eliminamos un nodo de la lista recibimos lista e index
{
    int returnAux = -1; //si falla la validacion
    Node* nodePost; //pountero a nodos auxiliares
    Node* nodeAnt;//pountero a nodos auxiliares
    if(this!=NULL && index>=0 && index<this->size) // validamos parametros
    {
    	if(index==0) // en caso de estar en la posicion 0 modificamos el pfirsnode del LinkedL
    	{
    		nodePost=this->pFirstNode; // en el aux de nodo cargamos el valor del pfirsnode(que esta en la cabecera) al que apunta el linkedL
    		this->pFirstNode=nodePost->pNextNode; //en la cabecera cargamos el pNexmode del nodo a eliminar asi la cabecera apuntaria al segundo
    		free(nodePost); //liberamos en memoria este nodo
    	}
    	else
    	{
    		nodePost=getNode(this, index); //en caso de querer eliminar de la posicion 1 en adelante nos traemos la posicion a elminar
    		nodeAnt=getNode(this, index-1);  // tambien traemos la posicion anterior ambos en dos punteros a nodosaux
    		nodeAnt->pNextNode=nodePost->pNextNode; //al nodo anterior le cargamos el PNEXTNODE del nodo a eliminar y LISTO
    		free(nodePost); // liberamos espacio en memoria
    	}
    	this->size--; // decrementamos el tamaño de la lista
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1; // si la lista es NULL

    if(this!=NULL) // validacion
    {
    	int len=this->size; //tamaño de la lista para poder iterar y eliminar todos sus nodos
    	for(int i=len-1; i<=0; i++) // recorremos la lista de manera inversa asi eliminamos los nodos
    	{
    		ll_remove(this, i); // remuevo uno a uno hasta llegar a la posicion 0 y el PNEXTNODE le pone NULL al pfirsnode
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)  // elimina ll
{
    int returnAux = -1; // valor de error
    if(this!=NULL) //validacion requerida
    {
    	if(ll_clear(this)==0) //primero eliminamso todos los elementos de la lista para asi poder eliminar el LL
    	{
    		free(this); // si me devuelve 0 es porque elimino la lista y asi podemos hacer un free del LinkedL
			returnAux=0;
    	}

    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) // busca un elemento en la lista donde lo consigue por primera vez corta y devuelve el indice
{
    int returnAux = -1; // valor de retrono de errror
    if(this!=NULL) //validacion
    {
    	for(int i=0; i<this->size; i++) //recorro la lista desde 0 hasta el tamaño de la lista
    	{
    		if(ll_get(this, i)==pElement) //le pido al llGet el elemento en el index  i y lo comparon con pElement
    		{
    			returnAux=i; //si son iguales regreso el index y corto salgo del bucle
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) // verificamos si tiene al menos 1 nodo la lista
{
    int returnAux = -1; // error si el ll no exite
    if(this!=NULL) // vañlidacion
    {
    	if(this->size>0) // si this size > 0 devolvemos 0 porque la lista NO ESTA VACIA PORQUE SI TIENE nodos
    	{
    		returnAux=0; // si tiene nodos
     	}
    	else
    	{
    		returnAux=1; // =0 no tiene nodos retornamos 1, es decir esta vacia sin nodos
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) /// insertamos un elemento en una posicion especifica
{
    int returnAux = -1;

    if(this!=NULL && index<=this->size && index>=0) //validamos index sea menor igual al size porque podemos meter uno al final por eso se hace igual
    {										// y igual index mayor igual a 0
    	returnAux=addNode(this, index, pElement); //llamamos addnode y nos devuelve 0 o -1 si fue exitoso o no y eso lo retornamos
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) //recibo la lista y el index que quiero eliminar
{
    void* returnAux = NULL; //puntero void que retornaremos
    if(this!=NULL && index>=0 && index<ll_len(this)) // validaciones requeridas
    {
    	returnAux=ll_get(this, index); // llamo a ll_get para obtener el elemento y la guardo en el retrono en un puntero void
     	if(returnAux!=NULL) // si el retorno de ll_get fue distinto de NULL llamo a la funcion remove y borramos
    	{
    		ll_remove(this, index); // borro el nodo que contenia el elemento
    	}

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) //le mando la lista a comparar y el elemento
{
    int returnAux = -1;
    if(this!=NULL) // validacion pedida
    {
    	returnAux=0; // cambio el estado de retorno
		for(int i=0; i<this->size; i++) // recorro la lista
		{
			if(ll_get(this, i)==pElement) //valido elemnto por elemento hasta el final, apenas consigo uno hago break y retorno que consegui
			{
				returnAux=1;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement1; // declaro puntero a void para guardar el elemento a comparar
   // int flagEncontrado;

    if(this!=NULL && this2!=NULL)//validacion pedida
    {
    	returnAux=0; // cambio el retorno a que no consegui elementos
        for (int i=0; i<this2->size; i++) // recorro la lista de this2
        {
        	pElement1=ll_get(this2, i);//tomo el valor del elemento de this2 en cada posicion
        	if(ll_contains(this, pElement1)==1)// comparo llamando a ll contains elemento por elemento si me regresa 1 sigo con el siguiente
        	{
        		returnAux=1;//pongo el estado en positivo consiguio 1
           	}
        	else
        	{
        		returnAux=0;// cambio el estado a que este elemento de this2 no esta en this 1 hago break y mando un 0 en el retorno fallo un elemento
        		break;
        	}

        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; // creo un nuevo puntero tipo ll para retornarlo lo inicializo en NULL por si acaso falla
    void* pElement; // creo un puntero al elemento tipo VOID para copiar
    if(this!=NULL && from<to && from>=0 && to<=ll_len(this)) //validacionesss from debe ser menor a to y ambos estar entre 0 y len lista
    {
    	cloneArray = ll_newLinkedList(); // creamos una nueva LL y cargamos el puntero a la nueva lista en CLoneArray
		for(int i=from; i<=to; i++) //recorremos la lista original empezando por "from" y terminando en "to" los dos parametros de la lista
		{
				pElement=ll_get(this, i); // le pedimos el elemento en esta posicion del array original
				ll_add(cloneArray, pElement); //agregamos un nuevo nodo a la lista con el elemento copiado en el paso anterior
		}

    }

    return cloneArray; // retornamos la nueva lista
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL; // declaramos puntero tipo LL y inicializamos en NULL por si no pasa la validacion
    void* pElement; // puntero auxiliar al elemento que se valla duplicando
    if(this!=NULL) // validacion
    {
    	cloneArray = ll_newLinkedList(); // creamos lista tipo linkedl y guardamos su puntero en Clonearray
    	for(int i=0; i<ll_len(this); i++) // recorremos toda la lista original para copiar TODOS sus elementos
    	{
			pElement=ll_get(this, i); // obtenemos todos los elementos contenidos en cada nodo del 0 al LENTHIS UNO A UNO
			ll_add(cloneArray, pElement); // AGREGAMOS TODOS LOS ELEMENTOS EN LA NUEVA LISTA UNO A UNO
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1; // variable para retorno
    int flagSwap; // swap
    void* pElement1; // puntero al elemento para copiar en la otra posicion
    void* pElement2;// puntero al elemento para copiar en la otra posicion
    int i;
    int criterio; // valor que me devuvlevo el puntero a la funcion y asi sabemos si swapeamos o no
    if(this!=NULL && (order==1 || order==0) && pFunc!=NULL)
    {
    	do
    	{
    		flagSwap=0; // INICIALIZAMOS EN CADA NUEVA ITERACION en 0 SI NO HAY SWAP SALE DEL BUCLE EN EL WHILE
    		for(i=0; i<(this->size)-1; i++) //recorremos la lista hasta len-1
    		{
    			pElement1=ll_get(this, i); // obtenemos el elemento en la lista posicion i (primera vuelta es el 0)
    			pElement2=ll_get(this,i+1); // obtemenos el elemento en la lista posicion i +1 (primera vuelta es el 1)
    			criterio=pFunc(pElement1, pElement2); // llamo  ala funcion criterio y le paso ambos pteros elementos
				if(order) // valido el orden en el que se quiere ordenar si es 1 es ascendente
				{
					if(criterio==1) // si criterio me retorno 1 es porque tengo que swapear
					{
						ll_set(this, i, pElement2); // llamo mi funcion ll set y sobreEscribo el element en la posicion  Anterior con la Siguiente
						ll_set(this, i+1, pElement1); //  llamo mi funcion ll set y sobreEscribo el element en la posicion Siguiente con el Anterior
						flagSwap=1; // marco que hubo cambio y asi puedo seguir swapeando
					}
				}
				else // si el orden es desendente
				{
					if(criterio==-1) // si criterio nos da -1
					{
						ll_set(this, i, pElement2); // llamo mi funcion ll set y sobreEscribo el element en la posicion  Anterior con la Siguiente
						ll_set(this, i+1, pElement1); // llamo mi funcion ll set y sobreEscribo el element en la posicion Siguiente con el Anterior
						flagSwap=1; //swapeo ON
					}
				}

    		}

    	}while(flagSwap); // si flagswap=0 se sale y finaliza
    	returnAux = 0;
    }
    return returnAux;

}

/** \brief envia los elementos de la lista uno a uno a una funcion que se encarga de ir trabajando con ellos de 1 a la vez
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion que trabajaremos
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL o el puntero a la Funcion es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, void(*pFunc)(void*))
{
	int returnAux=-1;
	void* pElement;
	if(this!=NULL && pFunc!=NULL) // validaciones requeridas
	{
		for(int i=0; i<ll_len(this); i++) // recorro la lista para ir sacando uno a uno sus elementos y enviandolos a mapear
		{
			pElement=ll_get(this, i); // toomo el elemento posicion i
			pFunc(pElement); // comienza el mapeo
		}
		returnAux=0;
	}
	return returnAux;
}

/** \brief Recibe un clon de la Lista Original y Filtra lo requerido Eliminando lo que no quiere guardar
 * \param pList LinkedList* Puntero a la lista clonada
 * \param pFunc (*pFunc) Puntero a la funcion que trabajaremos
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL o el puntero a la Funcion es NULL
                                ( 0) Si ok
 */
int ll_filter(LinkedList* this, int(*pFunc)(void*))
{
	int returnAux=-1;
	void* pElement; // puntero al elemento
	int criterio; // resultado de la funcion criterio
	if(this!=NULL && pFunc!=NULL) // validamos
	{
		for(int i=ll_len(this)-1; i<=0; i--) // recorremos la lista de atras para adelante
		{
			pElement=ll_get(this, i); // obtenemos el elemento d ela lista en la posicion i
			criterio=pFunc(pElement); // obtenemos el resultado de la funcion criterio si es 0 borramos -1 dejamos
			if(criterio==0) // preguntamos si nos dio 0 la funcion
			{
				ll_remove(this, i); // ELIMINAMOS DE LA LISTA
			}
		}

	}
	return returnAux;
}
