
#ifndef UI_H_
#define UI_H_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "service.h"
/*Functia de afisare a medicamentelor din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se vor afisa medicamentele din lista (daca sunt) sub forma: Cod:
*                                                             Nume:
*                                                             Concentratie:
*                                                             Cantitate:
* Daca nu sunt medicamente in functie sa va afisa mesajul: "Nu sunt medicamente in stoc!"
*/
void afisare(Lista* ptr);

/*Functia de stergere a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se va citi de la tastatura codul medicamentului din lista (daca este) care se vrea sters
*
* Daca medicamentul nu este in lista se va afisa mesajul: "Nu exista medicament cu codul dat in stoc!\n"
*                                                 altfel: "Medicamentul a fost sters cu succes!\n"
*/
void stergere(Lista* ptr);

/*Functia de actualizare a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se va citi de la tastatura codul medicamentului din lista (daca este) care se vrea modificat si noile componente
*
* Daca medicamentul nu este in lista se va afisa mesajul: "Nu exista medicament cu codul dat in stoc!\n"
*                                                 altfel: "Medicamentul a fost actualizat cu succes!\n"
* In caz ca datele date (codul,concentratia)sunt invalide se va afisa:"Codul este invalid!\n"
*                                                                      "Concentratia este invalida!\n "
*/
void actualizare_medicament(Lista* ptr);

/*Functia de adaugare a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se vor citi de la tastatura componentele medicamentului care se vrea adaugat
*
* In cazul in care datele date (codul,concentratia,cantitatea)sunt invalide se va afisa:"Codul este invalid!\n"
*                                                                                       "Concentratia este invalida!\n "
*                                                                                       "Cantitatea este invalida!\n "
*/
void adauga_medicament(Lista* ptr);

/*Functia care citeste datele pentru filtrare (tipul filtrarii dorit)
  ->Medicamente unde stocul disponibil este mai mic decat o valoare data;
  ->medicamente cu numele incepand cu o litera data.
*/
void filtrare(Lista lista);

/*Functia care citeste datele pentru ordonare (tipul ordonarii dorit)
  ->crescator
  ->descrescator
*/
void ordonare(Lista* lista);
#endif