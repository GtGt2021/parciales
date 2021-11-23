/*
 * parser.h
 *
 *  Created on: 13 nov. 2021
 *      Author: gt
 */

#ifndef PARSER_H_
#define PARSER_H_

int FileNew(char *path);
int parser_arcadesFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_saveAsText(FILE* pFile , LinkedList* list);
void parser_saveAsTextGames(void*);
int parser_saveAsArcades(FILE* pFile , LinkedList* list);
#endif /* PARSER_H_ */
