#include <iostream>
#include <fstream>

using namespace std;

void createFile(const string nazwaPliku, const int licznik, const char wartosci);
void plikLog(const string wartoscLoga);

int main(int argc, char* argv[])
{
	createFile("plik_1_0x55_100.bin", 100, 0x55);
	createFile("plik_2_0x55_100.bin", 100, 0x55);
	createFile("plik_3_0x55_100.bin", 100, 0x55);
	createFile("plik_4_0x50_100.bin.bin", 100, 0x50);
	plikLog("1");
	plikLog("2");
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
	int iLicznik = 0;
	ifstream mojPlik;
	mojPlik.open(nazwaPliku);
	
	if (mojPlik)
	{
		cout << "Plik:" + nazwaPliku + " juz istnieje\n";
	}
	else {

		ofstream plik(nazwaPliku);

		for (size_t iLicznik = 0; iLicznik < licznik; iLicznik++)
		{
			plik << wartosci;
		}
	}

	
	
	
}




