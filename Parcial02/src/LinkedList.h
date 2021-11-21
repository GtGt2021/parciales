/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this); // largo linkedlist
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); //lista a operar y elemnto a guardar al final de la lista
void* ll_get(LinkedList* this, int index);//puntero al elemento (donde se encuentra) el index del que queremos
int ll_set(LinkedList* this, int index,void* pElement); // setea el elemento en el index
int ll_remove(LinkedList* this,int index);// elimina un elemento al final del linkedList
int ll_clear(LinkedList* this); // elimina todos los elementos de la lista pero no los nodos del linkLis
int ll_deleteLinkedList(LinkedList* this);//Elimina el LinkedList completo
int ll_indexOf(LinkedList* this, void* pElement); //busca elemnto en la lista donde encuenta nos retorna el inidice
int ll_isEmpty(LinkedList* this); // nos dice si hay elementos (nodos) en la lista
int ll_push(LinkedList* this, int index, void* pElement); //inserta un elemento en la lista en el index indicado
void* ll_pop(LinkedList* this,int index); // elimina un elemento de la posicion indicada y nos devuelve su puntero ASI PODEMOS HACERLE FREE
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
int ll_map(LinkedList* this, void(*pFunc)(void*));
int ll_filter(LinkedList* this, int(*pFunc)(void*));
