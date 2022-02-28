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
	int* p = nullptr; int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

void input(data& s);

double vidurkis(data& s);

double mediana(data& s);

void addmark(data& s);

void select(data& s);

void output(data& s);


int main() {
	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << std::endl;

	int studentai;
	cout << "Iveskite studentu skaiciu: ";
	cin >> studentai;
	while (cin.fail()) { // Apsauga ivedimui
		cin.clear();
		cin.ignore();
		cin >> studentai;
	}

	data* s = new data[studentai];

	for (int i = 0; i < studentai; i++) {
		input(s[i]);
		select(s[i]);
	}
	for (int i = 0; i < studentai; i++) {
		output(s[i]);
	}

	delete[] s;
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

	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	s.p = new int[s.n];
	for (int i = 0; i < s.n; i++) {
		s.p[i] = dist(mt);
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << std::endl;
	}

	s.egz = dist(mt);
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



