#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::string;

struct data {
	string vardas = "", pavarde = "";
	int* p = nullptr; 
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

void input(data& s);

double vidurkis(data& s);

double mediana(data& s);

void select(data& s);

void output(data& s);

int genrand();

void addmark(data& s, int& it);


int main() {
	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << std::endl;

	int studentai;
	cout << "Iveskite studentu skaiciu: ";
	cin >> studentai;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> studentai;
	}

	data* mas = new data[studentai];

	for (int i = 0; i < studentai; i++) {
		input(mas[i]);
		select(mas[i]);
	}
	for (int i = 0; i < studentai; i++) {
		output(mas[i]);
	}

	delete[] mas;
	system("pause");
}

void input(data& s) {
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;
	cout << "Iveskite pazymiu kieki: ";

	cin >> s.n;
	while (cin.fail()) {
		cin.ignore();
		cin.clear();
		cin >> s.n;
	}

	s.p = new int[s.n];
	for (int i = 0; i < s.n; i++) {
		s.p[i] = genrand();
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << std::endl;
	}
	
	int it;
	char check;
	do{
		it = s.n;
		cout << "Jei noretumete ivesti dar pazymiu iveskite 'y', jei ne 'n': ";
		do {
			cin >> check;
		} while (check != 'y' && check != 'n');
		if (check == 'y') {
			addmark(s, it);
			for (int i = it; i < s.n; i++) {
				cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << std::endl;
			}
		}
	} while (check != 'n');
	
	s.egz = genrand();
	cout << "Egzamino vertinimas: " << s.egz << std::endl;

};

double vidurkis(data& s) {
	double v = 0;
	for (int i = 0; i < s.n; i++) {
		v += s.p[i];
	}
	v = v / s.n;

	v = v * 0.4 + s.egz * 0.6;

	return v;
}

double mediana(data& s) {
	double m = 0;
	int temp = 0;

	for (int i = 0; i < s.n - 1; i++) {
		for (int j = i + 1; j < s.n; j++) {
			if (s.p[j] < s.p[i]) std::swap(s.p[j], s.p[i]);
		}
	}

	temp = s.n;
	if (temp % 2 != 0) {
		double tem = temp;
		int mazesnis = ((double)(tem / 2) - 0.5);
		int didesnis = ((double)(tem / 2) + 0.5);
		m = ((s.p[mazesnis] + s.p[didesnis]) / 2) * 0.4 + s.egz * 0.6;
	}
	else {
		m = s.p[temp / 2] * 0.4 + s.egz * 0.6;
	}

	return m;
}

void output(data& s) {
	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas";
	if (s.m == 0) cout << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
	else if (s.v == 0) cout << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;

	cout << string(60, '-') << std::endl;

	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (s.m == 0) cout << std::left << std::setw(23) << std::setprecision(3) << s.v << std::endl;
	else if (s.v == 0) cout << std::left << std::setw(20) << std::setprecision(3) << s.m << std::endl;
	cout << std::endl;
};

void select(data& s) {
	char check;
	cout << "Jei norite kad programa isvestu vidurki iveskite 'v', jeigu mediana, iveskite 'm': ";
	do {
		cin >> check;
	} while (check != 'v' && check != 'm');
	if (check == 'v' && s.n != 0) s.v = vidurkis(s);
	else if (check == 'v' && s.n == 0) s.v = 0.6 * s.egz;
	else if (check == 'm' && s.n != 0) s.m = mediana(s);
	else if (check == 'm' && s.n == 0) s.m = 0.6 * s.egz;
};

int genrand() {
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);
	return dist(mt);
};

void addmark(data& s, int &it) {
	int amount;
	cout << "Iveskite pazymiu kieki: "; cin >> amount;
	while (cin.fail()) { // Apsauga ivedimui
		cin.clear();
		cin.ignore();
		cin >> amount;
	}
	int* temp = new int[it];
	for (int i = 0; i < it; i++) temp[i] = s.p[i];
	s.n += amount;
	delete[] s.p;
	s.p = new int[s.n];
	for (int i = 0; i < s.n; i++) {
		if (i < it) s.p[i] = temp[i];
		else s.p[i] = genrand();
	}
	delete[] temp;
};



