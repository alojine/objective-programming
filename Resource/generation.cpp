#include "generation.h"

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

int genrand() {

	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	std::uniform_int_distribution<int> dist(1, 10);
	int sk = dist(generator);

	return sk;
};

void output(data& s, char vm) {

	cout << string(60, '-') << std::endl;
	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (vm == 'v') cout << std::left << std::setw(23) << std::setprecision(2) << s.v << endl;
	else if (vm == 'm') cout << std::left << std::setw(20) << std::setprecision(2) << s.m << endl;
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

