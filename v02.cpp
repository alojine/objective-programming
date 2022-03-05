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

double vidurkis(data& s);

double mediana(data& s);

void select(data& s);

void output(data& s, char vm);

void tabletop(char vm);

int genrand();

void addmark(data& s, int& it);


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
		data temp; // Laikina struktura kuri veliau patalpinama i vektoriu
		s.reserve(studentai);
		for (int i = 0; i < studentai; i++) {
			input(temp, vm);
			s.push_back(temp);
		}
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

	cin >> s.n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> s.n;
	}
	s.p.resize(s.n);
	for (int i = 0; i < s.n; i++) {
		s.p[i] = genrand();
		s.p.push_back(s.p[i]);
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << endl;
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
			addmark(s, it);
			for (int i = it; i < s.n; i++) {
				cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << endl;
			}
		}
	} while (check != 'n');

	s.egz = genrand();
	cout << "Egzamino vertinimas: " << s.egz << endl;
	
	if (vm == 'v') s.v = vidurkis(s);
	else if (vm == 'm') s.m = mediana(s);
};

double vidurkis(data& s) {
	double v = 0;
	for (auto& el : s.p) {
		v += el;
	}

	if (s.p.size() != 0) v = v / (s.p.size() * 1.0) * 0.4 + s.egz * 0.6;
	else v = s.egz * 0.6;

	return v;
}

double mediana(data& s) {
	/*
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
	*/
	double m;
	sort(s.p.begin(), s.p.end());
	for (int i = 0; i < s.p.size(); i++) {
		cout << s.p[i] << " ";
	}
	cout << endl;
	if (s.p.size() % 2 == 0 && s.p.size() != 0) {
		m = (s.p[s.p.size() / 2] + s.p[(s.p.size() / 2) - 1] * 1.0 / 2) * 0.4 + s.egz * 0.6; // lyginis
	}
	else if (s.p.size() % 2 != 0 && s.p.size() != 0) {
		 m = s.p[s.p.size() / 2] * 0.4 + s.egz * 0.6;
	}
	else m = s.egz * 0.6;

	return m;
}

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
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(0, 10);
	return dist(mt);
};

void addmark(data& s, int& it) {
	s.n += 1;
	s.p.reserve(s.n);
	
	for (int i = it; i < s.n; i++) {
		s.p[i] = genrand();
		s.p.push_back(s.p[i]);
	}
	s.p.shrink_to_fit();
};


/*
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
using std::endl;

struct data {
	string vardas = "", pavarde = "";
	int* p = nullptr;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};

void input(data& s, char howMethod);

double vidurkis(data& s);

double mediana(data& s);

void tabletop(char howMethod);

void output(data& s);

int genrand();

void addmark(data& s, int& it);


int main() {
	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << endl;
	cout << endl;

	char howInput, howMethod; int studentai;

	cout << "Jei norite skaityti duomenis is failo iveskite 'y', jei generuoti atsitiktinai 'n': ";
	do {
		cin >> howInput;
	} while (howInput != 'y' && howInput != 'n');

	cout << "Jei norite kad programa isvestu vidurki iveskite 'v', jeigu mediana, iveskite 'm': ";
	do {
		cin >> howMethod;
	} while (howMethod != 'v' && howMethod != 'm');

	if (howInput == 'y') {

	}

	else if (howInput == 'n') { // Generavimo ivedimas
		cout << "Iveskite studentu skaiciu: ";
		cin >> studentai;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> studentai;
		}

		data* mas = new data[studentai];

		for (int i = 0; i < studentai; i++) {
			input(mas[i], howMethod);
		}
		tabletop(howMethod);
		for (int i = 0; i < studentai; i++) {
			output(mas[i]);
		}

		delete[] mas;
	}


	system("pause");
}

void input(data& s, char howMethod) {
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;
	cout << "Iveskite pazymiu kieki: ";

	cin >> s.n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> s.n;
	}

	s.p = new int[s.n];
	for (int i = 0; i < s.n; i++) {
		s.p[i] = genrand();
		cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << endl;
	}

	int it;
	char check;
	do {
		it = s.n;
		cout << "Jei noretumete ivesti dar viena pazymi iveskite 'y', jei ne 'n': ";
		do {
			cin >> check;
		} while (check != 'y' && check != 'n');

		if (check == 'y') {
			addmark(s, it);
			for (int i = it; i < s.n; i++) {
				cout << "Ivestas " << i + 1 << "-asis pazimys: " << s.p[i] << endl;
			}
		}
	} while (check != 'n');

	s.egz = genrand();
	cout << "Egzamino vertinimas: " << s.egz << endl;

	if (howMethod == 'v' && s.n != 0) s.v = vidurkis(s);
	else if (howMethod == 'v' && s.n == 0) s.v = 0.6 * s.egz;
	else if (howMethod == 'm' && s.n != 0) s.m = mediana(s);
	else if (howMethod == 'm' && s.n == 0) s.m = 0.6 * s.egz;

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

void tabletop(char howMethod) {
	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas";
	if (howMethod == 'v') cout << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (howMethod == 'm') cout << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
};

void output(data& s) {

	cout << string(60, '-') << std::endl;

	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (s.m == 0) cout << std::left << std::setw(23) << std::setprecision(3) << s.v << endl;
	else if (s.v == 0) cout << std::left << std::setw(20) << std::setprecision(3) << s.m << endl;

	/*
	* C++ funkcijos
	Mano_failas << "|" << setw(20) << left << "Vardas" << setw(1) << "|" << setw(20) << left << "Pavarde" << setw(1) << "|" <<
	sewtw(10) << right << 55 << "|" << sewtw(10) << 54 << "|" << sewtw(10)<< 11;

	C isvedimas
	printf("|%-20s|%-20s|%10s|%10s|%10s|\n","Vardas", Pavarde, "ND1", "ND2", "ND3" );
	fprintf(Mano_failas, "|%-20s|%-20s|%10d|%10d|%10d|\n","Vardas", Pavarde, 55, 54, 11 );
	.c_str(), metodas jeigu yra variable vietoj stringo
	
};

int genrand() {
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);
	return dist(mt);
};

void addmark(data& s, int& it) {
	/*
	int amount;
	cout << "Iveskite pazymiu kieki: "; cin >> amount;
	while (cin.fail()) { // Apsauga ivedimui
		cin.clear();
		cin.ignore();
		cin >> amount;
	}
	
	int* temp = new int[it];
	for (int i = 0; i < it; i++) temp[i] = s.p[i];
	s.n += 1;
	delete[] s.p;
	s.p = new int[s.n];
	for (int i = 0; i < s.n; i++) {
		if (i < it) s.p[i] = temp[i];
		else s.p[i] = genrand();
	}
	delete[] temp;
}; */




