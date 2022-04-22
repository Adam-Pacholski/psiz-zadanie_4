#include "pliki.h"

void files() {
	createFile("plik1.bin", 100, 0x55);
	createFile("plik2.bin", 100, 0x55);
	createFile("plik3.bin", 100, 0x55);
	createFile("plik4.bin", 100, 0x55);
	createFile("plik5.bin", 1024 * 1024 * 400, 0x55);
	createFile("plik6.bin", 1024 * 1024 * 400, 0x50);
}

void createFile(const string nazwaPliku, const int licznik, const char wartosci)
{
	srand(time(NULL));
	ifstream mojPlik;
	mojPlik.open(nazwaPliku);
	const char innyZnak = 0x44;
	int losoweMiejsca[10] = {};
	bool jestOk = false;
	int temp = {};
	int k = 0;
	float procent = licznik / 100;
	float KolejnePrzedzialy = procent;
	int p = 0;

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



		string log ="- utworzono plik: " + nazwaPliku + "\n";

		//string log = dt + " - utworzono plik: " + nazwaPliku;
		plikLog(log);
		system("cls");

	}

}
