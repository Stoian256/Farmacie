#ifndef SERVICE_H_
#define SERVICE_H_
#include "repo.h"
int srv_stergere(Lista* ptr, int cod); 
int srv_actualizare(Lista* ptr, int cod, char nume[], double concentratie);
int srv_adaugare(Lista* ptr, int cod, char nume[], double concentratie,int cantitate);
Lista srv_filtrare1(Lista* lista,int valoare);
Lista srv_filtrare2(Lista* l, char c);
void srv_ordonare(Lista* l, char L);
#endif