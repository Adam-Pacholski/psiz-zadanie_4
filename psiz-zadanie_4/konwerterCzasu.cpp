#include "konwerterCzasu.h"

string zamianaCzasu(int wartosc) {

	string wynik = "";

	int wszystkie_sec = wartosc;
	int h = wszystkie_sec / 3600; //tyle pelnych godzin jest w wszystkie_sec
	int min = (wszystkie_sec / 60) % 60; //ilosc pelnych minut w wszystkie_sec modulo 60 - daje ilosc pozostalych minut niezawartych w pelnej godzinie
	int s = wszystkie_sec % 60; //ilosc pozostalych sekund niezawartych w pelnych godzinach ani w pelnych minutach

	wynik = to_string(h) + "H:" + to_string(min) + "M:"+ to_string(s) + "s";

	return wynik;
	


}