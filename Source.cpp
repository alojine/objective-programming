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
			
			string fname; int skiekis;
			cout << "Iveskite failo pavadinima: ";
			cin >> fname;
			cout << "Iveskite studentu kieki: ";
			cin >> skiekis;
			cout << "Jei norite kad programa isvestu vidurki iveskite 'y', jeigu mediana, iveskite 'n': ";
			char vm = charApsauga(vm);
			cout << endl;
			
			auto laikasVisa = hrClock::now();

			string n = "nuskriaustukai.txt", k = "kietiakai.txt"; std::stringstream nuskriaustukai; std::stringstream kietiakai;
			ofstream out_f(fname);

			failoGeneratorius(out_f, skiekis);
			out_f.close();

			
			buffSkaitymas(s, fname);
			select(s, vm);
			std::sort(s.begin(), s.end(), [](data& x, data& y) {return x.vardas < y.vardas; });

			skirstymas(s, kietiakai, nuskriaustukai, vm);
			
			auto laikasKietiakai = hrClock::now();
			buffFaila(k, kietiakai);
			cout << "Kietieku surasymas uztruko: " << durationDouble(hrClock::now() - laikasKietiakai).count() << " s" << endl;

			auto laikasNuskriaustukai = hrClock::now();
			buffFaila(n, nuskriaustukai);
			cout << "Nuskriaustuku surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;

			cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;

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














