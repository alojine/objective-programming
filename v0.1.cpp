#include <iostream>
#include <string>
#include <iomanip>

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
	data s;
	/*
	data* mas = new data[3];
	for (int i = 0; i < 3; i++) {
		input(mas[i]);
	}
	*/
	cout << "Atminkite, kad jeigu ivesite '0' tai nutrauks ivedima, ar tai butu pazymiai, ar studentai." << std::endl;

	input(s);
	select(s);
	output(s);

	/*
	for (int i = 0; i < 3; i++) {
		output(mas[i]);
	}
	*/

	//delete [] mas;
	system("pause");
}

void input(data& s) {
	cout << std::endl;
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;


	for (int i = 0; i < s.n; i++) {
		cout << "Iveskite" << i + 1 << "-aji pazymi: ";
		cin >> s.paz[i];
		if (s.paz[i] == 0) break;
		s.n++;
	}
	s.n = s.n - 2;
	cout << "Iveskite egzamino ivertinima: "; cin >> s.egz;
	cout << std::endl;
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

	for (int i = 0; i < s.n; i++) {
		cout << s.paz[i] << " ";
	}
	cout << std::endl;
	
	
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
	
};

void select(data& s) {
	string kas;
	cout << "Jei norite kad programa isvestu vidurki iveskite 'v', jeigu mediana, iveskite 'm': "; cin >> kas;
	if (kas == "v") s.v = vidurkis(s);
	else if (kas == "m") s.m = mediana(s);
}







