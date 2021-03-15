
#include "UI.h"
/*Functia de afisare a medicamentelor din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se vor afisa medicamentele din lista (daca sunt) sub forma: Cod:
*                                                             Nume:
*                                                             Concentratie:
*                                                             Cantitate:
* Daca nu sunt medicamente in functie sa va afisa mesajul: "Nu sunt medicamente in stoc!"
*/
void afisare(Lista* ptr) {
	int i;
	
	
	if (ptr->lungime != 0) {
		for (i = 0; i < ptr->lungime; i++)
			printf("\nCod:%d\nNume:%s\nConcentratie:%f\nCantitate:%d\n", ptr->vector[i].cod, ptr->vector[i].nume, ptr->vector[i].concentratie, ptr->vector[i].cantitate);
	}

	else {
		printf("Nu sunt medicamente in stoc!");
	}
}

/*Functia de stergere a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se va citi de la tastatura codul medicamentului din lista (daca este) care se vrea sters
*                                                            
* Daca medicamentul nu este in lista se va afisa mesajul: "Nu exista medicament cu codul dat in stoc!\n"
*                                                 altfel: "Medicamentul a fost sters cu succes!\n"
*/
void stergere(Lista* ptr) {
	int cod,rez;
	printf("Dati codul medicamentului:");
	(void)scanf("%d", &cod);

	rez=srv_stergere(ptr, cod);
	if (rez == -1)printf("Nu exista medicament cu codul dat in stoc!\n");
	if (rez == 1)printf("Medicamentul a fost sters cu succes!\n");
	
}
/*Functia de actualizare a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se va citi de la tastatura codul medicamentului din lista (daca este) care se vrea modificat si noile componente
*
* Daca medicamentul nu este in lista se va afisa mesajul: "Nu exista medicament cu codul dat in stoc!\n"
*                                                 altfel: "Medicamentul a fost actualizat cu succes!\n"
* In caz ca datele date (codul,concentratia)sunt invalide se va afisa:"Codul este invalid!\n"
*                                                                      "Concentratia este invalida!\n "
*/
void actualizare_medicament(Lista* ptr) {
	int cod,rez,ok=0;
	double concentratie;
	char nume[20];
	printf("Dati codul medicamentului:");
	(void)scanf("%d", &cod);
	printf("Dati noul numele al medicamentului:");
	(void)scanf("%s", nume);
	printf("Dati noua concentratia a medicamentului:");
	(void)scanf("%lf", &concentratie);
	rez = srv_actualizare(ptr, cod, nume, concentratie);
	if (rez == 1)
		printf("Medicamentul a fost actualizat cu succes!\n");
	else if (rez < 0) {
		if (rez % 3 == 0)printf("Codul este invalid!\n"),ok=1;
		if (rez % 5 == 0)printf("Concentratia este invalida!\n "),ok=1;
		if (ok == 0)printf("Nu exista medicament cu codul dat in stoc!\n");

	}
}
/*Functia de adaugare a unui medicament din lista
* Date de intrare: ptr - un pointer la o lista de Medicamente
* Se vor citi de la tastatura componentele medicamentului care se vrea adaugat
*
* In cazul in care datele date (codul,concentratia,cantitatea)sunt invalide se va afisa:"Codul este invalid!\n"
*                                                                                       "Concentratia este invalida!\n "
*                                                                                       "Cantitatea este invalida!\n "
*/
void adauga_medicament(Lista* ptr) {
	int cod, cantitate,rez;
	double concentratie;
	char nume[20];
	printf("Dati codul medicamentului:");
	(void)scanf("%d", &cod);
	printf("Dati numele medicamentului:");
	(void)scanf("%s", nume);
	printf("Dati concentratia medicamentului:");
	(void)scanf("%lf", &concentratie);
	printf("Dati cantitatea medicamentului:");
	(void)scanf("%d", &cantitate);
	rez=srv_adaugare(ptr, cod, nume, concentratie,cantitate);
	if (rez < 0) {
		if (rez % 3 == 0)printf("Codul este invalid!\n");
		if (rez % 5 == 0)printf("Concentratia este invalida!\n");
		if (rez % 7 == 0)printf("Cantitatea este invalida!\n ");
	}
	if (rez == 1)printf("Medicament adaugat cu succes!\n");
	
}
/*Functia care citeste datele pentru filtrare (tipul filtrarii dorit)
  ->Medicamente unde stocul disponibil este mai mic decat o valoare data;
  ->medicamente cu numele incepand cu o litera data.
*/
void filtrare(Lista lista) {
	int nr; 
	//Lista rez = creazaLista();
	Lista rez;
	printf("\n1 Medicamente cu stoc < valoare data\n2 - Medicamente cu nume ce incepe cu litaera data\nAlegeti:\n");
	(void)scanf("%d", &nr);
	if (nr == 1) {
		int valoare;
		
		printf("Dati valoarea:");
		(void)scanf("%d", &valoare);
		rez = srv_filtrare1(&lista, valoare);
		
		
		
	}
	if (nr == 2) {
		char c;
		printf("Dati litera:");
		(void)scanf("%c", &c);
		(void)scanf("%c", &c);
		
		rez=srv_filtrare2(&lista,c);
		
	}
	afisare(&rez);
	if(rez.lungime>0)
	distruge(&rez);
}
/*Functia care citeste datele pentru ordonare (tipul ordonarii dorit)
  ->crescator
  ->descrescator
*/
void ordonare(Lista* lista) {
	char L;
	Lista rez=copiaza_lista(lista);
	printf("\n C - crescator  | D - descrescator\nAlegeti sensul:");
	(void)scanf("%c", &L);
	(void)scanf("%c", &L);
	//rez = srv_ordonare(&rez, L);
	srv_ordonare(&rez, L);
	afisare(&rez);
	distruge(&rez);
	
}