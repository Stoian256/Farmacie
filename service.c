#include "service.h"
#include "validare.h"
#include "UI.h"
#include <string.h>
int srv_stergere(Lista* ptr, int cod) {
/*Functia primeste o lista de medicamente si codul medicamentului ce trebuie sters si efectueaza stergerea returnand -1 daca nu exista un medicament cu codul dat
Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
                   cod - un intreg ce reprezinta codul medicamnetului care trebuie sters din stocul farmaciei

Returneaza : 1 - daca medicamentul a fost sters cu succes
            -1 - daca nu exista un medicament cu codul dat in stocul farmaciei 
*/
	return(repo_stergere(ptr, cod));
}

int srv_actualizare(Lista* ptr, int cod, char nume[], double concentratie) {
/*Functia ce primeste o lista cu medicamente si caacteristici ale unui medicament ce se actualizeaza conform cu ele
Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
                   cod - un intreg ce reprezinta codul medicamnetului care trebuie actualizat din stocul farmaciei
				   nume - un string ce reprezinta numele nou al medicamentului
				   concentratie - un double ce reprezinta concentratia noua a medicamentului

Returneaza : 1 - daca medicamentul a fost actualizat cu succes  
            -1 - daca nu exista un medicament cu codul dat in stocul farmaciei
*/  
	int rez = validare_medicament(cod, concentratie, 1);
	if (rez < 0)return rez;
	Medicament medicament;
	medicament = creeaza_medicament(cod, nume, concentratie, 1);
	//medicament.cod = cod;
	//strcpy(medicament.nume, nume);
	//medicament.concentratie = concentratie;
	//medicament.cantitate = 1;
	return(repo_actualizare(ptr, medicament));
	

}


int srv_adaugare(Lista* ptr, int cod, char nume[], double concentratie, int cantitate) {
	/*Functia primeste o lista cu medicamente si caacteristici unui medicament si adauga medicamentul cu caracteristicile date in lista
	Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
					 cod - un intreg ce reprezinta codul medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 nume - un string ce reprezinta numele medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 concentratie - un double ce reprezinta medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 cantitate - un intreg ce reprezinta cantitatea medicamnetului care trebuie creat si adaugat in stocul farmaciei
    
*/
	int rez = validare_medicament(cod, concentratie, cantitate);
	if (rez < 0)return rez;
	Medicament medicament;
	medicament=creeaza_medicament(cod, nume, concentratie, cantitate);
	repo_aduga(ptr, medicament);
	return 1;
	//distruge_medicament(&medicament);

}
Lista srv_filtrare1(Lista* lista, int valoare) {
	/*Functia primeste un pointer la o lista de medicamente si filtreaza lista  dupa un criteriu: 
	       - medicamente unde stocul disponibil este mai mic decat o valoare dat; 
	Date de intrare: lista -  un pointer la o lista (stocul de medicamente din famacie)
					 valoare - un intreg ce reprezinta cantitatea

	Date de iesire: rez - lista cu medicamentele ce indeplinesc cerinta
	*/
	Lista rez=creazaLista();
	//Lista lista = copiaza_lista(l);
		int i;
		//rez.lungime = 0;
		
		for (i = 0; i < lista->lungime; i++) {
			if (lista->vector[i].cantitate < valoare) {
				//rez.lungime++;
				//rez.vector[rez.lungime] = lista.vector[i];
				add(&rez, copiaza_medicament(&lista->vector[i]));

			}

		}
		
	return rez;
}
Lista srv_filtrare2(Lista* lista, char c) {
	/*Functia primeste un pointer la o lista de medicamente si filtreaza lista dupa un criteriu:
		   - medicamente cu numele incepand cu o litera data;
	Date de intrare: lista -  un pointer la o lista (stocul de medicamente din famacie)
					 c - un caracter ce reprezinta litera cu care trebuie sa inceapa numele medicamentelor

	Date de iesire: rez - lista cu medicamentele ce indeplinesc cerinta
	*/

	Lista rez = creazaLista();
	
		int i;
		//rez.lungime = 0;
	
		for (i = 0; i < lista->lungime; i++) {
			if (lista->vector[i].nume[0] == c) {
				//rez.lungime++;
				//rez.vector[rez.lungime] = lista.vector[i];
				add(&rez, copiaza_medicament(&lista->vector[i]));
			}

		}

		return rez;
}
int comparator(const void* p, const void* q) {
//functie omparator folosita in qsort pentru ordonarea crescatoare dupa cantitate medicamentului
//Date de intrare : pointeri catre structura data in qsort
	int l = ((Medicament*)p)->cantitate;
	int r = ((Medicament*)q)->cantitate;

	return(l - r);

}
int comparator1(const void* p, const void* q) {
//functie comparator folosita in qsort pentru ordonarea descrescatoare dupa cantitate medicamentului
//Date de intrare : pointeri catre structura data in qsort
	int l = ((Medicament*)p)->cantitate;
	int r = ((Medicament*)q)->cantitate;

	return(r - l);
}
int cmpstr1(const void* a, const void* b) {
//functie comparator folosita in qsort pentru ordonarea crescatoare dupa nume a medicamentului
//Date de intrare : pointeri catre structura data in qsort
	const char* aa = ((Medicament*)a)->nume;
	const char* bb = ((Medicament*)b)->nume;
	return strcmp(bb, aa);
}

void srv_ordonare(Lista* lista, char L) {
	/*Functia primeste un pointer la o lista de medicamente si ordoneaza lista avad cantitatea drep criteriu principal si numele drept criteriu secundar:
			   - crescator (daca L=='C');
			   - medicamente cu numele incepand cu o litera data(daca L=='D');
		Date de intrare: lista - un pointer la  o lista (stocul de medicamente din famacie)
						   L - un caracter ce reprezinta modul de ordonare dorit
	*/
	qsort(&lista->vector[0], lista->lungime, sizeof(Medicament), cmpstr1);
	if (L == 'C')
		qsort(&lista->vector[0], lista->lungime, sizeof(Medicament), comparator);
	else if (L == 'D')
		qsort(&lista->vector[0], lista->lungime, sizeof(Medicament), comparator1);
	
	//return lista;
}