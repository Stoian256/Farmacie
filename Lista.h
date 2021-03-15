#ifndef LISTA_H_
#define LISTA_H_
#include "domeniu.h"
#include <stdlib.h>
/*typedef struct {
	Medicament vector[100];
	int lungime;

} Lista;
*/

typedef struct {
	Medicament* vector;
	int lungime;
	int cap;
} Lista;

Lista creazaLista();
void distruge(Lista* l);
void add(Lista* l, Medicament el);
void resize(Lista* l);
Lista copiaza_lista(Lista* l);



#endif