#include "headers.h"

int main() {

	cout << "Ar norite skityti duomenis is failo? (y/n) ";
	char howInput = charApsauga(howInput);

	vector<data> s;

	if (howInput == 'y') { // Skaitymas is failo

		cout << "Ar norite ivesti faila? (y/n) ";
		char gen = charApsauga(gen);

		if (gen == 'y') { // Naudoja generatoriu
			do {
				
			
				string fname; int skiekis;
				cout << "Iveskite failo pavadinima: ";
				cin >> fname;
				cout << "Iveskite studentu kieki: ";
				cin >> skiekis;
				cout << "(Vidurkis/Mediana) - (y/n) ";
				char vm = charApsauga(vm);
				cout << endl;

				s.reserve(skiekis);
			
				auto laikasVisa = hrClock::now();

				string n = "nuskriaustukai.txt", k = "kietiakai.txt";
				vector<data> Kieti;
				vector<data> Vargsai;

				ofstream out_f(fname);

				failoGeneratorius(out_f, skiekis);
				out_f.close();

			
				buffSkaitymas(s, fname);
				skaiciavimai(s, vm);
				std::sort(s.begin(), s.end(), [](data& x, data& y) {return x.vardas < y.vardas; });

				paskirstymas(s, Kieti, Vargsai, vm);
			
				auto laikasKietiakai = hrClock::now();
				buffRasymas(Kieti, k, vm);
				cout << "Kietieku surasymas uztruko: " << durationDouble(hrClock::now() - laikasKietiakai).count() << " s" << endl;

				auto laikasNuskriaustukai = hrClock::now();
				buffRasymas(Vargsai, n, vm);
				cout << "Nuskriaustuku surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;

				cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;
				cout << endl;

				cout << "Ar norite ivesti dar viena faila? (y/n) ";
				char oneMore = charApsauga(oneMore);
				gen = oneMore;
				cout << endl;
				
			} while (gen == 'y');
		}

		else if (gen == 'n') { // Skaito viena faila
			try {
				std::ifstream fr("studentai.txt");
				std::ofstream fp("kursiokai.txt");
				vector<string> head; // virsutines eilutes nuskaitymas
				//failoSkaitymas(fr, s, head);
				buffSkaitymas(s, "studentai.txt");
				skaiciavimai(s, 'abu');
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
		skaiciavimai(s, vm);
		tabletop(vm);
		for (int i = 0; i < s.size(); i++) {
			output(s.at(i), vm);
		}

		s.clear();
	}


	system("pause");
}














