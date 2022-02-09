#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

struct data {
	string vardas ="", pavarde ="";
	int paz[50] = { 0 }, egz = 0;
	double rezult = 0;
};

void input(data& s);

void output(data& s);

int main() {
	data s;
	data* mas = new data[3];
	for (int i = 0; i < 3; i++) {
		input(mas[i]);
	}
	input(s);
	output(s);
	for (int i = 0; i < 3; i++) {
		output(mas[i]);
	}
	delete [] mas;
	system("pause");
}

void input(data& s) {
	int n = 3;

	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;

	// cout << "Kiek pazymiu turi studentas: "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Iveskite" << i + 1 << "-aji pazymi: ";
		cin >> s.paz[i];
		// jeigu ivedame raide, pazymiai baigiasi
	}
	cout << "Iveskite egzamino ivertinima: "; cin >> s.egz;
};

void output(data& s) {

	cout << "|" << std::left << std::setw(20) << "s.vardas" << std::left << std::setw(20) << s.pavarde << std::right;
	for (int i = 0; i < 3; i++) cout << "|" << std::setw(10) << s.paz[i];
	cout << "|" << std::setw(10) << s.egz << "|" << std::endl;
};

int vidurkis(data& s) {
	
};