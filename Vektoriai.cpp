#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct data {
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz = 0, n = 2;
	double v = 0, m = 0;
};

void input(data& s);

double vidurkis(data& s);

double mediana(data& s);

void select(data& s);

void output(data& s);

int main() {
	srand(time(NULL));
	int studentai;
	cout << "Jeigu jusu inputas buvo nepriimtas, vadinasi neteisingai ivedete, bandykite vesti is naujo pagal reikalavimus." << std::endl;
	cout << "Iveskite studentu skaiciu: "; 
	cin >> studentai;
	while (cin.fail()) { // Apsauga ivedimui
		cin.clear();
		cin.ignore();
		cin >> studentai;
	}
	vector<data> s;
	data temp; // Laikina struktura kuri veliau patalpinama i vektoriu
	s.reserve(studentai);
	for (int i = 0; i < studentai; i++) {
		input(temp);
		s.push_back(temp);
	}
	
	for (int i = 0; i < s.size(); i++) {
		output(s.at(i));
	}
	
	s.clear(); // Atlaisvinama vieta

	system("pause");
}

void input(data& s) { // Ivedimo funkcija
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;


	s.paz.resize(100); // Priskiriamas vieta vektoriui
	for (int i = 0; i < s.n; i++) {
		s.paz.push_back(i); // Priskiriama vieta pazymiui
		char check; int p = 0;
		cout << "Jei norite ivesti " << i + 1 << "-aji pazymi iveskite 'y' arba 'n': ";
		do {
			cin >> check;
		} while (check != 'y' && check != 'n'); // Apsauga inputui

		if (check == 'y') { // Jei y - ivedamas pazimys
			p = rand() % 10 + 1;
			s.paz[i] = p;
			
			cout << "Pazimys: " << s.paz[i] << std::endl;
		}
		else if ((check == 'n')) break; // Jei n - baigiamas ivedimas
		s.n++;
	}
	s.paz.shrink_to_fit(); // Apkarpoma vieta
	s.n = s.n - 2;

	cout << "Iveskite egzamino ivertinima: ";
	s.egz = rand() % 10 + 1;
	cout << s.egz << std::endl;
	cout << std::endl;
	select(s); // Pasirinkimo funkcija - mediana ar vidurkis
};

double vidurkis(data& s) { // Vidurkio funkcija
	double v = 0;
	for (int i = 0; i < s.n; i++) {
		v += s.paz[i];
	}
	v = v / s.n;

	v = v * 0.4 + s.egz * 0.6;

	return v;
}

double mediana(data& s) { // Medianos funkcija
	double m = 0;
	int temp = 0;

	for (int i = 0; i < s.n - 1; i++) {
		for (int j = i + 1; j < s.n; j++) {
			if (s.paz[j] < s.paz[i]) std::swap(s.paz[j], s.paz[i]); // Rikivaimas
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

void output(data& s) { // Isvedimo funkcija
	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas";
	if (s.m == 0) cout << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
	else if (s.v == 0) cout << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;

	cout << string(60, '-') << std::endl;

	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (s.m == 0) cout << std::left << std::setw(23) << std::setprecision(3) << s.v << std::endl;
	else if (s.v == 0) cout << std::left << std::setw(20) << std::setprecision(3) << s.m << std::endl;
	cout << std::endl;
};

void select(data& s) { // Pasirinkimo funkcija - vidurkis ar mediana
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


