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

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

struct data {
	string vardas = "", pavarde = "";
	vector<int> p;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

void input(data& s, char vm);

void select(vector<data>& s, char vm);

double vidurkis(vector<int> p, int egz);

double mediana(vector<int> p, int egz);

void output(data& s, char vm);

void tabletop(char vm);

int genrand();

void addmark(data& s, int& it, int &kiek);

bool fist_name(data x, data y);

bool last_name(data x, data y);


int main() {

	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << endl;
	cout << endl;

	char howInput, vm; int studentai;

	cout << "Jei norite skaityti duomenis is failo iveskite 'y', jei generuoti atsitiktinai 'n': ";
	do {
		cin >> howInput;
	} while (howInput != 'y' && howInput != 'n');

	cout << "Jei norite kad programa isvestu vidurki iveskite 'v', jeigu mediana, iveskite 'm': ";
	do {
		cin >> vm;
	} while (vm != 'v' && vm != 'm');

	if (howInput == 'y') {

	}

	else if (howInput == 'n') {
		int studentai;
		cout << "Iveskite studentu skaiciu: ";
		cin >> studentai;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> studentai;
		}

		vector<data> s;
		 // Laikina struktura kuri veliau patalpinama i vektoriu
		s.reserve(studentai);
		for (int i = 0; i < studentai; i++) {
			data temp;
			input(temp, vm);
			s.push_back(temp);
		}
		select(s, vm);
		tabletop(vm);
		for (int i = 0; i < s.size(); i++) {
			output(s.at(i), vm);
		}

		s.clear(); // Atlaisvinama vieta
	}
	

	system("pause");
}

void input(data& s, char vm) {
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;
	cout << "Iveskite pazymiu kieki: ";
	int pazimys;
	int kiek;
	cin >> kiek;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> kiek;
	}
	//s.p.resize(kiek);
	for (int i = 0; i < kiek; i++) {
		pazimys = genrand();
		cout << "pazimys: " << pazimys << endl;
		s.p.push_back(pazimys);
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << pazimys << endl;
	}
	s.p.shrink_to_fit();
	
	int it;
	char check;
	do {
		it = s.n;
		cout << "Jei noretumete ivesti dar pazymiu iveskite 'y', jei ne 'n': ";
		do {
			cin >> check;
		} while (check != 'y' && check != 'n');

		if (check == 'y') {
			addmark(s, it, kiek);
			for (int i = it; i < kiek; i++) {
				cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << endl;
			}
		}
	} while (check != 'n');

	s.egz = genrand();
	cout << "Egzamino vertinimas: " << s.egz << endl;
	
};

void select(vector<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'v') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'm') el.m = mediana(el.p, el.egz);
	}
};

double vidurkis(vector<int> p, int egz) {
	double v = 0;
	for (auto& el : p) {
		v += el;
	}

	if (p.size() != 0) v = v / (p.size() * 1.0) * 0.4 + egz * 0.6;
	else v = egz * 0.6;

	return v;
};

double mediana(vector<int> p, int egz) {

	double m;
	sort(p.begin(), p.end());
	
	if (p.size() % 2 == 0 && p.size() != 0) {
		m = (p[p.size() / 2] + p[(p.size() / 2) - 1] * 1.0 / 2) * 0.4 + egz * 0.6; // lyginis
		cout << "lyginis ima abu" << endl;
	}
	else if (p.size() % 2 != 0 && p.size() != 0) {
		m = p[p.size() / 2] * 0.4 + egz * 0.6;
		cout << "NEEEEEEEEelyginis ima abu" << endl;
	}
	else m = egz * 0.6;

	return m;
};

void tabletop(char vm) {

	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas";
	if (vm == 'v') cout << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (vm == 'm') cout << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
};

void output(data& s, char vm) {

	cout << string(60, '-') << std::endl;
	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (vm == 'v') cout << std::left << std::setw(23) << std::setprecision(3) << s.v << endl;
	else if (vm == 'm') cout << std::left << std::setw(20) << std::setprecision(3) << s.m << endl;
};

int genrand() {

	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	std::uniform_int_distribution<int> dist(1, 10);
	int sk = dist(generator);

	return sk;
};
void addmark(data& s, int& it, int& kiek) {
	kiek += 1;
	int pazimys;
	s.p.reserve(s.n);
	
	for (int i = it; i < kiek; i++) {
		pazimys = genrand();
		s.p.push_back(pazimys);
	}
	s.p.shrink_to_fit();
};

bool fist_name(data x, data y) {
	return x.vardas < y.vardas;
};

bool last_name(data x, data y) {
	return x.pavarde < y.pavarde;
};



