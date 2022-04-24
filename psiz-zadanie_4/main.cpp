
#include <iostream>

#include "plikLog.h"
#include "pliki.h"


//testy

using namespace std;

void koniecProgramu();
void menu(string wiadomosc);
void resetCin();

int main(int argc, char* argv[])
{


	

	if (argc == 1) menu("nie podajac ");
	else if (argc < 3) menu("podajac za malo ");
	else if (argc > 3) menu("podajac za duzo ");
	else {
		cout << argc << ": " << argv[1] << ", " << argv[2] << endl;
		dzialaniaNaPlikach(argv[1], argv[2]);
	}

	system("pause");
	//koniecProgramu();

}

void menu(string wiadomosc) {
	int opcja = {};
	bool wyjscie = false;
	plikLog("- uruchomiono program " + wiadomosc + "argunentow \n");
	cout << " -------------------- MENU ---------------------- \n"
		" ------------------------------------------------ \n"
		" [1] - Automatyczny przyklad obliczania BER  \n"
		"       (potrzebne min 800MB wolnego miejsca na dysku)\n"
		" [2] - Podanie przez uzytkownika sciezek do pliku \n"
		" [3] - Zamkniecie programu \n"
		" ------------------------------------------------ \n";


	do
	{
		cout << " Co chcesz zrobic: ";
		//cin >> opcja;
		opcja = 1;
		if (opcja) {

			switch (opcja)
			{
			case 1:
			{
				plikLog("- Uzytkownik wybral opcje [1] - automatyczne obliczenia BER\n");
				pliki();
				//dzialaniaNaPlikach("plik1.bin", "plik2.bin");
				//dzialaniaNaPlikach("plik3.bin", "plik4.bin");
				dzialaniaNaPlikach("plik5.bin", "plik6.bin");
			}
			case 2:
			{

			}
			case 3:
			{
				wyjscie = true;
				plikLog("- program zostal poprawnie zakonczony\n");
			}
			default:
				break;
			}
		}
		else {
			cout << "Wprowadzono bledna opcje" << endl;
			resetCin();
		}
	} while (!wyjscie);


	

}

void koniecProgramu() {
	bool zamknac = false;
	char znak = {};

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

void resetCin() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}





