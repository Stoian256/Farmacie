#include "domeniu.h"
Medicament creeaza_medicament(int cod, char nume[], double concentratie, int cantitate) {
/*Functie care primeste componentele unui medicament si il creeaza
* Date de intrare: cod - intreg
*                  nume - sir de caractere
*                  concentrtie - double
*                  cantitate - intreg
* Date de iesire : med - o structura de date "Medicament"
*/
	Medicament med ;
	med.cod = cod;
	med.nume = malloc(sizeof(char) * (strlen(nume) + 1));
	if(*nume!='0')
		strcpy(med.nume, nume);
	med.concentratie = concentratie;
	med.cantitate = cantitate;

	return med;
}
void distruge_medicament(Medicament* med) {
	//dealocarea spatiului pentru numelemedicamentului
	free(med->nume);
}



Medicament copiaza_medicament(Medicament* p) {
	//se face copia unui medicament
	return creeaza_medicament(p->cod, p->nume, p->concentratie,p->cantitate);
}
