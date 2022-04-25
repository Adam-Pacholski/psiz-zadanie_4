#pragma once
#include <iostream>

#include <fstream>
#include<algorithm>
#include <time.h>

#include<string>

#include <vector>
#include <bitset>

#include "konwerterCzasu.h"
#include "hammingDistance.h"
#include "plikLog.h"

using namespace std;

void tworzeniePlikow(const string nazwaPliku, const int licznik, const char wartosci);
void pliki();
void dzialaniaNaPlikach(const string plik1, const string plik2);
void printSize(const string& address);