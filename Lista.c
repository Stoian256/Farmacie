#include "Lista.h"



Lista creazaLista() {
	//alocarea memoriei pentru o lista de medicamente
	//returneaza lista
	Lista rez;
	rez.lungime = 0;
	rez.cap = 2;
	rez.vector = malloc(sizeof(Medicament) * rez.cap);
	return rez;

}

void distruge(Lista* l) {
	//primeste un pointer la o lista si dealoca spatiul 
	for (int i = 0; i < l->lungime; i++) {
		distruge_medicament(&l->vector[i]);
	}
	free(l->vector);
	l->vector = NULL;
	l->lungime = 0;
}

void resize(Lista* l) {
	//in cazul in care lista este plina aloca un spatiu dublu
	if (l->lungime < l->cap ) {
		return;
	}
	int nCap = (l->cap) * 2;
	int i;
	Medicament* nElems = malloc(nCap * sizeof(Medicament));
	//copiez din vectorul existent
	for (i = 0; i < l->lungime; i++) {
		if(nElems)
		   nElems[i] = l->vector[i];
	}
	//dealocam memoria ocupata de vector
	free(l->vector);
	l->vector = nElems;
	l->cap = nCap;
}

void add(Lista* l, Medicament el) {
	//adauga un element la sfarsitul listei
	resize(l);
	l->vector[l->lungime] = el;
	l->lungime++;
}

Lista copiaza_lista(Lista* l) {
	//se copiaza lista data printr-un pointer
	Lista rez = creazaLista();
	for (int i = 0; i < l->lungime; i++) {
		Medicament p = l->vector[i];
		add(&rez, copiaza_medicament(&p));
	}
	return rez;
}