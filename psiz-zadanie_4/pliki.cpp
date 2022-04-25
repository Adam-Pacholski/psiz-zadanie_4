#include "pliki.h"


void pliki() {
	tworzeniePlikow("plik1.bin", 100, 0x55);
	tworzeniePlikow("plik2.bin", 100, 0x55);
	tworzeniePlikow("plik3.bin", 100, 0x55);
	tworzeniePlikow("plik4.bin", 100, 0x55);
	tworzeniePlikow("plik5.bin", 1024 * 1024 * 400, 0x55);
	tworzeniePlikow("plik6.bin", 1024 * 1024 * 400, 0x50);
}

void tworzeniePlikow(const string nazwaPliku, const int licznik, const char wartosci)
{
	srand(time(NULL));
	ifstream mojPlik;

	const char innyZnak = 0x35;
	int losoweMiejsca[10] = {};
	bool jestOk = false;
	int temp = {};
	int k = 0;
	float procent = licznik / 100;
	float KolejnePrzedzialy = procent;
	int p = 0;

	mojPlik.open(nazwaPliku);
	if (mojPlik)
	{
		//	cout << "Plik:" + nazwaPliku + " juz istnieje\n";
		plikLog("- pominiêto tworzenie pliku: " + nazwaPliku + " | plik ju¿ istnieje.\n");
	}
	else {

		ofstream plik(nazwaPliku);

		if (nazwaPliku == "plik4.bin") {

			for (size_t i = 0; i < 10; i++)
			{
				do
				{
					temp = rand() % licznik + 1;
					for (size_t j = 0; j < 10; j++)
					{
						if (temp == losoweMiejsca[j]) {
							jestOk = true;
						}
						else jestOk = false;
					}

				} while (jestOk);
				losoweMiejsca[i] = temp;

			}
			sort(losoweMiejsca, losoweMiejsca + 10);

			for (size_t i = 0; i < 10; i++)
			{
				cout << losoweMiejsca[i] << ", ";
			}

			for (size_t i = 0; i < 11; i++)
			{
				if (i < 10) {
					for (k; k < losoweMiejsca[i]; k++)
					{
						plik << wartosci;

					}

					plik << innyZnak;

					k++;

				}
				else {
					for (k; k < licznik; k++)
					{

						plik << wartosci;

					}
				}
			}
		}
		else {

			for (size_t i = 0; i < licznik; i++)
			{
				plik << wartosci;

				if (nazwaPliku == "plik5.bin" || nazwaPliku == "plik6.bin")
					if (i == KolejnePrzedzialy) {
						p++;
						KolejnePrzedzialy = KolejnePrzedzialy + procent;
						system("cls");
						cout << nazwaPliku << ": " << p << "%";
					}
			}
		}

		string log = "- utworzono plik: " + nazwaPliku + "\n";

		//string log = dt + " - utworzono plik: " + nazwaPliku;
		plikLog(log);
		system("cls");

	}

}

void dzialaniaNaPlikach(const string _plik1, const string _plik2) {
	clock_t t;
	ifstream plik1(_plik1, ios::binary | ios::in);
	ifstream plik2(_plik2, ios::binary | ios::in);
	long long int iloscBitow = 0, ber = 0;

	char a{};
	char b{};
	
	if(_plik1 == _plik2) {
		plikLog("- uzytkownik podal 2 takie same pliki\n");
		cout << "\n Podaj prosze 2 rozne pliki!!\n";
	}

	else if (!plik1) {

		cout << "Plik: '" + _plik1 + "' prawdopodobnie nie istnieje\n";	
		plikLog("- nie znaleziono pliku: " + _plik1);

	}

	else if (!plik2) {

		cout << "Plik: '" + _plik2 + "' prawdopodobnie nie istnieje\n";	
		plikLog("- nie znaleziono pliku: " + _plik2);

	}

	else {

		cout << " Obliczam, prosze o cierpliwosc...\n\n";

		t = clock();
		while (!plik1.eof())
		{
			plik1 >> a;
			plik2 >> b;
			
			if (plik1.eof()) { break; } // dodatkowe zabezpieczenie przed znakiem konca pliku ;]

			iloscBitow = iloscBitow + 8;
			ber = hammingDistance(a, b) + ber;

		}
		
		t = (clock() - t) / CLOCKS_PER_SEC;

		plik1.close();
		plik2.close();


		cout << " Metoda: 'Hamming Distance'\n ";
		cout << " Wyniki dla plikow: " + _plik1 + " i " + _plik2 + " \n"
			" Wielkosc pliku: " + _plik1 + " = "; printSize(_plik1);
		cout << "\n Wielkosc pliku: " + _plik2 + " = "; printSize(_plik2);
		cout << "\n BER: " << ber << "b"
			"\n Sprawdzonych bitow: " << iloscBitow << "b"
			"\n czas potrzebny na sprawdzenie: " << zamianaCzasu(t) << "\n\n";

		plikLog("- program wykonal obliczenia na plikach: " + _plik1 + " i " + _plik2 + "\n"
				" Metoda: 'Hamming Distance'\n "
				"- wyniki obliczen: \n"
				"BER: " + to_string(ber) + "b\n"
				"Sprawdzonych bitow: " + to_string(iloscBitow) + "\n"
				"Czas obliczen: " + zamianaCzasu(t) + "\n");
		
	}
}
// funkcja sprawdzajaca wielkocs pliku znalezione w internecie https://stackoverflow.com/questions/13648066/determine-the-size-of-a-binary-file
void printSize(const string& address) {
	fstream motd(address.c_str(), ios::binary | ios::in | ios::ate);
	if (motd) {
		fstream::pos_type size = motd.tellg();
		cout << size << "B";
	}
	else {
		perror(address.c_str());
	}
}