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

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;
using std::ofstream;

struct data {
	string vardas = "", pavarde = "";
	vector<int> p;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

// Generavimas
void input(data& s, char vm);
void output(data& s, char vm);
void addmark(data& s, int& it, int& kiek);

// Skaiciavimai
double vidurkis(vector<int> p, int egz);
double mediana(vector<int> p, int egz);
void select(vector<data>& s, char vm);

// Pagalbiniai irankiai
void tabletop(char vm);
int genrand();

// Darbui su failu
void failoSkaitymas(ifstream& fd, vector<data>& s, vector<string>& l);
void failoIsvedimas(ofstream& fp, data& s);
void failoAntraste(ofstream& fp);

int main() {

	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << endl;
	cout << endl;

	char howInput, vm; int studentai;

	cout << "Jei norite skaityti duomenis is failo iveskite 'y', jei generuoti atsitiktinai 'n': ";
	do {
		cin >> howInput;
	} while (howInput != 'y' && howInput != 'n');

	vector<data> s;

	if (howInput == 'y') { // Skaitymas is failo

		std::ifstream fr("studentai.txt");
		std::ofstream fp("kursiokai.txt");
		vector<string> head; // virsutines eilutes nuskaitymas
		failoSkaitymas(fr, s, head);
		select(s, howInput);
		failoAntraste(fp);
		std::sort(s.begin(), s.end(), [](data& x, data& y) {return x.vardas < y.vardas; }); // rikiavimas pagal varda
		for (auto& el : s) {
			failoIsvedimas(fp, el);
		}

	}

	else if (howInput == 'n') { // Generavimas / rasymas

		cout << "Jei norite kad programa isvestu vidurki iveskite 'v', jeigu mediana, iveskite 'm': ";
		do {
			cin >> vm;
		} while (vm != 'v' && vm != 'm');

		int studentai;
		cout << "Iveskite studentu skaiciu: ";
		cin >> studentai;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> studentai;
		}

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

		s.clear(); 
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
	for (int i = 0; i < kiek; i++) {
		pazimys = genrand();
		s.p.push_back(pazimys);
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << pazimys << endl;
	}
	s.p.shrink_to_fit();
	
	int it;
	char check;
	do {
		it = kiek;
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

void failoSkaitymas(ifstream& fr, vector<data>& s, vector<string>& l) {
	
	string length;
	
	while ((fr.peek() != '\n') && (fr >> length)) {
		l.push_back(length);
	}
	l.resize(l.size() - 3);

	int pazimys;
	while (!fr.eof()) {
		data temp;
		fr >> temp.vardas >> temp.pavarde;
		for (auto& el : l) {
			fr >> pazimys;
			temp.p.push_back(pazimys);
		}
		fr >> temp.egz;
		temp.n = temp.p.size();
		s.push_back(temp);
	}
	
};

void failoIsvedimas(ofstream& fp, data& s) {
	fp << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde << std::left << std::setw(20) << std::setprecision(3) << s.v << std::left << std::setw(20) << std::setprecision(3) << s.m << endl;
};

void select(vector<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'v') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'm') el.m = mediana(el.p, el.egz);
		else if (vm == 'y') {
			el.m = mediana(el.p, el.egz);
			el.v = vidurkis(el.p, el.egz);
		}
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

	double m, s;
	sort(p.begin(), p.end());
	if (p.size() % 2 == 0 && p.size() != 0) {
		m = (double)((p[p.size() / 2] + p[p.size() / 2 - 1]) / 2);
		s = (m * 4 / 10) + (egz * 0.6);
	}
	else if (p.size() % 2 != 0 && p.size() != 0) {
		s = p[p.size() / 2] * 0.4 + egz * 0.6;
	}
	else s = egz * 0.6;

	return s;
};

void failoAntraste(ofstream& fp) {

	fp << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	fp << string(80, '-') << std::endl;
};

void tabletop(char vm) {
	if (vm == 'm') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	else if (vm == 'v') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
};

void output(data& s, char vm) {

	cout << string(60, '-') << std::endl;
	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (vm == 'v') cout << std::left << std::setw(23) << std::setprecision(2) << s.v << endl;
	else if (vm == 'm') cout << std::left << std::setw(20) << std::setprecision(2) << s.m << endl;
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
	s.p.reserve(kiek);
	
	for (int i = it; i < kiek; i++) {
		pazimys = genrand();
		s.p.push_back(pazimys);
	}
	s.p.shrink_to_fit();
};




