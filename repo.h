#ifndef REPO_H_
#define REPO_H_
#include "Lista.h"
void repo_aduga(Lista* ptr, Medicament medicament);
int repo_actualizare(Lista* ptr, Medicament medicament);
int repo_stergere(Lista* ptr, int cod);
#endif