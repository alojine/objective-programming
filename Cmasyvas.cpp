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
	int paz[50] = { 0 }, egz = 0, n = 2;
	double v = 0, m = 0;
};

void input(data& s);

double vidurkis(data& s);

double mediana(data& s);

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
	
	data* mas = new data[studentai];

	for (int i = 0; i < studentai; i++) {
		input(mas[i]);
		select(mas[i]);
	}
	for (int i = 0; i < studentai; i++) {
		output(mas[i]);
	}

	delete [] mas;
	system("pause");
}

void input(data& s) {
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;

	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	cout << "Iveskite pazymiu kieki: "; cin >> s.n;
	while (cin.fail()) { // Apsauga ivedimui
		cin.ignore();
		cin >> s.n;
	}
	for (int i = 1; i <= s.n; i++) {
			s.paz[i] = dist(mt);
			cout << i << "-asis pazymys: " << s.paz[i] << std::endl;
	}
		

	s.egz = dist(mt);
	cout << "Egzamino vertinimas: " << s.egz << std::endl;
};

double vidurkis(data& s) {
	double v = 0;
	for (int i = 0; i < s.n; i++) {
		v += s.paz[i];
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
			if (s.paz[j] < s.paz[i]) std::swap(s.paz[j], s.paz[i]);
		}
	}
	
	temp = s.n;
	if (temp % 2 != 0) {
		double tem = temp;
		int mazesnis = ((double)(tem / 2) - 0.5);
		int didesnis = ((double)(tem / 2) + 0.5);
		m = ((s.paz[mazesnis] + s.paz[didesnis]) / 2) * 0.4 + s.egz * 0.6;
	}
	else {
		m = s.paz[temp / 2] * 0.4 + s.egz * 0.6;
	}
	
	return m;
}

void output(data& s) {
	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas";
	if (s.m == 0) cout << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
	else if(s.v == 0) cout << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;

	cout << string(60,  '-') << std::endl;

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
}







