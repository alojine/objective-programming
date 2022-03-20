#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>
#include <fstream>
#include <ratio>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;
using std::ofstream;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;

struct data {
	string vardas = "", pavarde = "";
	vector<int> p;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

double vidurkis(vector<int> p, int egz);
double mediana(vector<int> p, int egz);
void select(vector<data>& s, char vm);

void input(data& s);
void output(data& s, char vm);
void addmark(data& s, int& it, int& kiek);
int genrand();
int sveikojoApsauga(int& a);
char charApsauga(char& a);

void tabletop(char vm);

void failoSkaitymas(ifstream& fd, vector<data>& s, vector<string>& l);
void failoIsvedimas(ofstream& fp, data& s);
void failoAntraste(ofstream& fp);

void failoGeneratorius(ofstream& fr, int a);
std::stringstream studentoGeneratorius(int b, int nr);
void buffSkaitymas(vector<data>& s, string fname);
void buffRasymas(vector<data>& s, string fname, char vm);
void buffFaila(string fname, std::stringstream& buffer);
void skirstymas(vector<data>& s, std::stringstream& kietiakai, std::stringstream& nuskriaustukai, char vm);