#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#define NACIONALIDAD_LEN 128
#define NOMBREJUEGO_LEN 63
#define NOMBRESALON_LEN 128
#define MONO 0
#define STEREO 1

int controller_loadFromText(char* path , LinkedList* pArrayArcades);
int controller_addArcade(LinkedList* pArrayArcades);
int controller_editArcade(LinkedList* List);
int controller_removeArcade(LinkedList* pArrayArcade);
int controller_ListArcade(LinkedList* pArrayArcade);
int controller_saveAsText(char* path , LinkedList* pArrayArcade);
int controller_listJuegos(LinkedList* lista);
int controller_sortArcadeNewList(LinkedList* pArrayArcade);
int controller_savelistJuegos(LinkedList* original);
LinkedList* controller_newListMulti(LinkedList* original);
int controller_actualizacion(LinkedList* lista);
#endif
