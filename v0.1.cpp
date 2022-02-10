#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

struct data {
	string vardas ="", pavarde ="";
	int paz[50] = { 0 }, egz = 0, n = 2;
	double v = 0, m = 0;
};

void input(data& s);

double vidurkis(data& s);

double mediana(data& s);

void output(data& s);


int main() {
	data s;
	/*
	data* mas = new data[3];
	for (int i = 0; i < 3; i++) {
		input(mas[i]);
	}
	*/
	cout << "Atminkite, kad jeigu ivesite 0 tai nutrauks ivedima, ar tai butu pazymiai, ar studentai." << std::endl;
	input(s);

	s.v = vidurkis(s);
	s.m = mediana(s);

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
		temp = s.paz[i];
		for (int j = i + 1; j < s.n; i++) {
			if (s.paz[j] < temp) std::swap(s.paz[j],temp);
		}
	}
	/*
	
	temp = s.n;
	if (temp % 2 != 0) {
		double tem = temp;
		int mazesnis = ((double)(tem / 2) - 0.5) - 1;
		int didesnis = ((double)(tem / 2) + 0.5) - 1;
		m = ((s.paz[mazesnis] + s.paz[didesnis]) / 2) * 0.4 + s.egz * 0.6;
	}
	else {
		m = s.paz[temp / 2] * 0.4 + s.egz * 0.6;
	}
	*/
	return m;
}

void output(data& s) {
	cout << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vardas" << std::left << std::setw(15) << "Galutinis (Vid.)"
		<< std::left << std::setw(3) << " / " << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
	cout << string(83,  '-') << std::endl;
	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde << std::left << std::setw(23) << std::setprecision(3) << s.v
		<< std::left << std::setw(20) << std::setprecision(3) << s.m << std::endl;
	
};







