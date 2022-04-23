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

	const char innyZnak = 0x44;
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

void dzialaniaNaPlikach(const char* _plik1, const char* _plik2) {
	clock_t t;

	int bity = {}, bity2 = {};
	ifstream plik1, plik2;

	plik1.open(_plik1, ios::binary);

	if (plik1.good()) {
		//plikLog("- otworzono plik 1\n");
		plik1.read((char*)&bity, sizeof(bity));
		plik1.close();
	//	plikLog("- zamknieto plik 1\n");
	}
	else {
		//plikLog("- nie znaleziono pliku 1\n");
	}

	plik2.open(_plik2, ios::binary);

	if (plik2) {
		plikLog("- otworzono plik 2\n");
		plik2.read((char*)&bity2, sizeof(bity2));
		plik2.close();
		plikLog("- zamknieto plik 2\n");
	}
	else {
		plikLog("- nie znaleziono pliku 2\n");
	}
	cout << "bity: " << bity << "\n";
	cout << "bity2: " << bity2 << "\n";

	t = clock();
	uint8_t ber = hammingDistance(bity, bity2);
	t = (clock() - t) / CLOCKS_PER_SEC;

	cout << "Compared bits: " << bity + bity2 << "\n";
	cout << "Different bits : " << static_cast<int>(ber) << "\n";
	cout << "Calc time : " << zamianaCzasu(t) << "\n";
}