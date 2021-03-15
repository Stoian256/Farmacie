#ifndef DOMENIU_H_
#define DOMENIU_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
typedef struct {
	int cod;
	char* nume;
	double concentratie;
	int cantitate;

} Medicament;



Medicament creeaza_medicament(int cod, char* nume, double concentratie, int cantitate);
void distruge_medicament(Medicament* med);

Medicament copiaza_medicament(Medicament* p);

#endif