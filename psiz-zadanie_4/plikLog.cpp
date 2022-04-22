#include "plikLog.h"

void plikLog(const string wartoscLoga) {
	const string log = "Log.txt";

	time_t now = time(NULL);
	char* dt = ctime(&now);
	ofstream plik;

	//string log = dt + wartoscLoga + "\n";

	plik.open(log, ios_base::app);
	plik << dt + wartoscLoga + "\n";
	plik.close();
}