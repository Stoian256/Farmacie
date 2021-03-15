#include "validare.h"
#include <string.h>
int validare_medicament(int cod, double concentratie, int cantitate) {
	/*functie de validare a componentelor medicamentului citite de la tastatur
	* Date de intrare: cod - un intreg
	*                  concentratie - float
	*                  cantitate - intreg
	* Functia returneaza: 1 - daca datele sunt corecte
	*                     un numar negativ altfel{ divizibil cu 3 daca codul este invalid (<=0)
	*                                            {divizibil cu 5 daca concentratia este invalida (<=0)
	*                                            {divizibil cu 7 daca cantitatea este invalida (<=0)
	*/
	int rez = -1;
	if (cod <= 0)rez *= 3;
	if (concentratie <= 0)rez *= 5;
	if (cantitate <= 0)rez *= 7;
	if(rez%3==0||rez%5==0||rez%7==0)
		return rez;
	return 1;

}
