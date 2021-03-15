#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "teste.h"
#include "UI.h"

void run_app() {
	Lista lista=creazaLista();
	//lista.lungime = 0;
	while (1) {
		printf("\n0 - EXIT\n1 - adauga medicamente\n2 - actualizare medicament\n3 - sterge medicament\n4 - ordonare lista\n5 -  Filtrare\n6 - Afisare stoc\nDati comanda:");
		
		int cmd;
		(void)scanf("%d", &cmd);
		//scanf("%c", &spa);
		if (cmd == 1)
			adauga_medicament(&lista);

		else if (cmd == 2)
			actualizare_medicament(&lista);

		else if (cmd == 3)
			stergere(&lista);

		else if (cmd == 4) {
			ordonare(&lista);
		}

		else if (cmd == 5)
			filtrare(lista);

		else if (cmd == 6)
			afisare(&lista);

		else if (cmd == 0) {
			break;
		}
		else {
			printf("Comanda invalida!\n");
		}

	}
	printf("Exiting...");
	distruge(&lista);
}
int main() {
	
	run_all_tests();
	run_app();
	_CrtDumpMemoryLeaks();
	
	return 0;
}