#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#define NACIONALIDAD_LEN 128
#define NOMBREJUEGO_LEN 63
#define NOMBRESALON_LEN 128
#define MONO 0
#define STEREO 1

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_addArcade(LinkedList* pArrayListEmployee);
int controller_editArcade(LinkedList* pArrayListEmployee);
int controller_removeArcade(LinkedList* pArrayListEmployee);
int controller_ListArcade(LinkedList* pArrayListEmployee);
int controller_sortArcade(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


#endif
