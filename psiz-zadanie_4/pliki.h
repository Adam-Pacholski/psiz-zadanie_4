#pragma once
#include <iostream>

#include <fstream>
#include<algorithm>
#include <time.h>

#include <vector>
#include <bitset>

#include "konwerterCzasu.h"
#include "hammingDistance.h"
#include "plikLog.h"

using namespace std;

void tworzeniePlikow(const string nazwaPliku, const int licznik, const char wartosci);
void pliki();
void dzialaniaNaPlikach(const char* plik1, const char* plik2);