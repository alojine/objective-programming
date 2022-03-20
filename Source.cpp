#include "headers.h"

int main() {

	cout << "Jei norite skaityti duomenis is failo iveskite 'y', jei generuoti atsitiktinai 'n': ";
	char howInput = charApsauga(howInput);

	vector<data> s;

	if (howInput == 'y') { // Skaitymas is failo
		// Exeption handling

		cout << "Jei norite naudoti failu generatoriu iveskite 'y', jei ne 'n': ";
		char gen = charApsauga(gen);

		if (gen == 'y') { // Naudoja generatoriu
			/*
			for (int i = 1000; i <= 10000000; i = i * 10) {
				string failas = "studentai";
				failas += std::to_string(i);
				ofstream out_f(failas);
				failoGeneratorius(out_f, i);
				
			}
			*/

			ofstream out_f("studentai1000.txt");
			failoGeneratorius(out_f, 1000);
			out_f.close();

			vector<string> head;
			ifstream fr("studentai1000.txt");
			failoSkaitymas(fr, s, head);
			fr.close();
			ofstream fp("kursiokai.txt");
			cout << s.size() << endl;
			select(s, 'abu');
			failoAntraste(fp);
			std::sort(s.begin(), s.end(), [](data& x, data& y) {return x.vardas < y.vardas; });
			for (auto& el : s) {
				failoIsvedimas(fp, el);
			}
		}

		else if (gen == 'n') { // Skaito viena faila
			try {
				std::ifstream fr("studentai.txt");
				std::ofstream fp("kursiokai.txt");
				vector<string> head; // virsutines eilutes nuskaitymas
				failoSkaitymas(fr, s, head);
				select(s, 'abu');
				failoAntraste(fp);
				std::sort(s.begin(), s.end(), [](data& x, data& y) {return x.vardas < y.vardas; }); // rikiavimas pagal varda
				for (auto& el : s) {
					failoIsvedimas(fp, el);
				}
			}
			catch (std::exception& e) {
				cout << "Neteisingas failo pavadinimas" << endl;
			}
		}
		
	}

	else if (howInput == 'n') { // Generavimas / rasymas

		cout << "Jei norite kad programa isvestu vidurki iveskite 'y', jeigu mediana, iveskite 'n': ";
		char vm = charApsauga(vm);

		cout << "Iveskite studentu skaiciu: ";
		int studentai = sveikojoApsauga(studentai);

		s.reserve(studentai);
		for (int i = 0; i < studentai; i++) {
			data temp;
			input(temp);
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














