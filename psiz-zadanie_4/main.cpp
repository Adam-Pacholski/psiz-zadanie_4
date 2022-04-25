
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
}

void menu(string wiadomosc) {
	int opcja = {};
	bool wyjscie = false;
	plikLog("- uruchomiono program " + wiadomosc + "argunentow \n");

	do
	{
		system("cls");
		cout << " ------------- Program obliczajacy BER: -------------\n";	
		cout << " ---------------------- MENU ------------------------ \n"
				" [1] - Automatyczny przyklad obliczania BER  \n"
				"       (potrzebne min 800MB wolnego miejsca na dysku)\n"
				" [2] - Podanie przez uzytkownika sciezek do pliku \n"
				" [3] - Zamkniecie programu \n"
				" ---------------------------------------------------- \n";
		cout << " Co chcesz zrobic: ";
		cin >> opcja;
		
		if (opcja) {

			switch (opcja)
			{
			case 1:
			{

				plikLog("- Uzytkownik wybral opcje [1] - automatyczne obliczenia BER\n");
				pliki();
				system("cls");

				cout << "TEST 1 \n";
				dzialaniaNaPlikach("plik1.bin", "plik2.bin");
				cout << "TEST 2\n";
				dzialaniaNaPlikach("plik3.bin", "plik4.bin");
				cout << "TEST 3\n";
				dzialaniaNaPlikach("plik5.bin", "plik6.bin");
				system("pause");
			} break;
			case 2:
			{
				plikLog("- Uzytkownik wybral opcje [2] - podanie sciezek do plikow\n");
				string arg1{}, arg2{};

				cout << " Podaj sciezke do 1 pliku: ";
				cin >> arg1;
				cout << " Podaj sciezke do 2 pliku: ";
				cin >> arg2;

				dzialaniaNaPlikach(arg1, arg2);	
				system("pause");

			} break;
			case 3:
			{
				wyjscie = true;
				plikLog("-uzytkownik zakonczyl dzialanie programu\n");
			} break;
			default:
				break;
			}
		}
		else {
			cout << "Wprowadzono bledna opcje" << endl;
			resetCin();
		}

		resetCin();
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

	plikLog("- program zostal zakonczony\n");
}

void resetCin() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}





