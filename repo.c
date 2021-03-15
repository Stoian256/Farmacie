#include "repo.h"
void repo_aduga(Lista* ptr, Medicament medicament) {
	/*Functia primeste o lista cu medicamente si caacteristici unui medicament si adauga medicamentul cu caracteristicile date in lista
	Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
					 cod - un intreg ce reprezinta codul medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 nume - un string ce reprezinta numele medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 concentratie - un double ce reprezinta medicamnetului care trebuie creat si adaugat in stocul farmaciei
					 cantitate - un intreg ce reprezinta cantitatea medicamnetului care trebuie creat si adaugat in stocul farmaciei

    */

	int gasit = 0, i;
	if (ptr->lungime != 0) {
		for (i = 0; i < ptr->lungime; i++)
			if ((ptr->vector[i]).cod == medicament.cod) {
				(ptr->vector[i]).cantitate += medicament.cantitate;
				distruge_medicament(&medicament);
				gasit = 1;
			}
		if (gasit == 0) {
			//ptr->lungime++;
			//ptr->vector[ptr->lungime] = medicament;
			add(ptr, medicament);
		}
	}
	else {
		//ptr->vector[1] = medicament;
		//ptr->lungime++;
		add(ptr, medicament);

	}
}

int repo_actualizare(Lista* ptr, Medicament medicament) {
	/*Functia ce primeste o lista cu medicamente si caacteristici ale unui medicament ce se actualizeaza conform cu ele
     Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
				      cod - un intreg ce reprezinta codul medicamnetului care trebuie actualizat din stocul farmaciei
				      nume - un string ce reprezinta numele nou al medicamentului
				      concentratie - un double ce reprezinta concentratia noua a medicamentului

     Returneaza : 1 - daca medicamentul a fost actualizat cu succes
			     -1 - daca nu exista un medicament cu codul dat in stocul farmaciei
*/
	int i, gasit = 0;
	for (i = 0; i < ptr->lungime && gasit == 0; i++)
		if (ptr->vector[i].cod == medicament.cod) {
			gasit = 1;
			medicament.cantitate = ptr->vector[i].cantitate;
			distruge_medicament(&ptr->vector[i]);
			ptr->vector[i] =medicament;
			//copiaza_medicament( &medicament);
			//distruge_medicament(&medicament);
		}
	
	if (gasit == 0) {
		distruge_medicament(&medicament);
		return -1;
	}
	return 1;
}

int repo_stergere(Lista* ptr, int cod) {
	/*Functia primeste o lista de medicamente si codul medicamentului ce trebuie sters si efectueaza stergerea returnand -1 daca nu exista un medicament cu codul dat
	Date de intrare: ptr - pointer la o lista (stocul de medicamente din famacie)
					   cod - un intreg ce reprezinta codul medicamnetului care trebuie sters din stocul farmaciei

	Returneaza : 1 - daca medicamentul a fost sters cu succes
				-1 - daca nu exista un medicament cu codul dat in stocul farmaciei
	*/
	int i, gasit = 0, j;
	for (i = 0; i < ptr->lungime && gasit == 0; i++) {
		if (ptr->vector[i].cod == cod) {
			gasit = 1;
			distruge_medicament(&ptr->vector[i]);
			for (j = i; j < ptr->lungime; j++)
				ptr->vector[j] = ptr->vector[j + 1];
			ptr->lungime--;

		}
	}
	if (gasit == 0)return -1;
	return 1;
}