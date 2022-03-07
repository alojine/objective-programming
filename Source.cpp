#include "headers.h"
#include "generation.h"
#include "calculations.h"
#include "utility.h"
#include "wfiles.h"

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
		// Exeption handling
		try {
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
		catch (std::exception& e) {
			cout << e.what() << endl;
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












