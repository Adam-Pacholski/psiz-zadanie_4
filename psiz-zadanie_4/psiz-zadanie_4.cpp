#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include<algorithm>

using namespace std;

// time_t now = time(NULL);
// char* dt = ctime(&now);

void createFile(const string nazwaPliku, const int licznik, const char wartosci);
void plikLog(const string wartoscLoga);
void files();

int main(int argc, char* argv[])
{
	time_t now = time(NULL);
	string dt = ctime(&now);
	plikLog(dt + "- uruchomiono program\n");
	srand(time(NULL));
	files();
}

void files() {
	createFile("plik1.bin", 100, 0x55);
	createFile("plik2.bin", 100, 0x55);
	createFile("plik3.bin", 100, 0x55);
	createFile("plik4.bin", 100, 0x55);
	createFile("plik5.bin", 1024 * 1024 * 400, 0x55);
	createFile("plik6.bin", 1024 * 1024 * 400, 0x50);
}

void plikLog(const string wartoscLoga) {
	const string log = "Log.txt";

	ofstream plik;
	plik.open(log, ios_base::app);
	plik << wartoscLoga + "\n";
	plik.close();
}

void createFile(const string nazwaPliku, const int licznik, const char wartosci)
{
	ifstream mojPlik;
	mojPlik.open(nazwaPliku);
	const char innyZnak = 0x44;
	int losoweMiejsca[10] = {};
	bool jestOk = false;
	int temp = {};
	int k = 0;
	double procent = licznik / 100;
	double pp = procent;
	int p = 0;

	if (mojPlik)
	{
		cout << "Plik:" + nazwaPliku + " juz istnieje\n";
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
					if (i == pp) {
						p++;
						pp = pp + procent;
						system("cls");
						cout << nazwaPliku << ": " << p << "%";
					}
			}
		}


		time_t now = time(NULL);
		string dt = ctime(&now);
		string log = dt + "- utworzono plik: " + nazwaPliku + "\n";

		//string log = dt + " - utworzono plik: " + nazwaPliku;
		plikLog(log);
		system("cls");

	}

}




