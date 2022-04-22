
#include <iostream>

#include "plikLog.h"
#include "pliki.h"
#include "konwerterCzasu.h"

using namespace std;


int main(int argc, char* argv[])
{
	bool zamknac = false;
	char znak = {};
	plikLog("- uruchomiono program\n");

	cout << zamianaCzasu(1001);

	files();

	do
	{
		cout << "Zamknac program?? [t,T] - Tak, inne - Nie \n"
			"Twoja decyzja: ";

		cin >> znak;
		if (znak == 't' || znak == 'T') zamknac = true;
		else system("cls");

	} while (!zamknac);

	plikLog("- program zostal poprawnie zakonczony\n");

}





