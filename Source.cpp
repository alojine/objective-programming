#include "headers.h"

int main() {

	cout << "Ar norite skityti duomenis is failo? (y/n) ";
	char howInput = charApsauga(howInput);

	if (howInput == 'y') { // Skaitymas is failo

		cout << "Ar norite ivesti faila? (y/n) ";
		char gen = charApsauga(gen);

		if (gen == 'y') { // Naudoja generatoriu

			cout << "Koki konteinerio tipa norite naudoti? vector - 'v', deque - 'd', list - 'l': ";
			char conType = konteinerioApsauga(conType);

			cout << "Kokia skirtymo strategija norite naudoti? 1 - 'y', 2 - 'n': ";
			char st = charApsauga(st);
			
			if (conType == 'v') {
				vector<data> s;
				do {
					try {
						string fname = "studentai";
						cout << "Iveskite studentu kieki: ";
						int skiekis = sveikojoApsauga(skiekis);
						fname += std::to_string(skiekis) + ".txt";

						cout << "(Vidurkis/Mediana) - (y/n) ";
						char vm = charApsauga(vm);
						
						cout << endl;
						s.reserve(skiekis);
						auto laikasVisa = hrClock::now();
						string n = "nuskriaustukai.txt", k = "kietiakai.txt"; vector<data> Kieti; vector<data> Vargsai;

						generuotifailus(fname, skiekis, 5);
						skaitymas(s, fname);
						sort(s.begin(), s.end(), rikiuotiPazymi);
						skaiciavimai(s, vm);
						paskirstymas(s, Kieti, Vargsai, vm, st);
						std::sort(Kieti.begin(), Kieti.end(), [](data& x, data& y) {return x.vardas < y.vardas; });
						std::sort(Vargsai.begin(), Vargsai.end(), [](data& x, data& y) {return x.vardas < y.vardas; });
						buffRasymas(Kieti, k, vm);
						buffRasymas(Vargsai, n, vm);
						s.clear(); Kieti.clear(); Vargsai.clear();

						cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;
						cout << endl;

						cout << "Ar norite ivesti dar viena faila? (y/n) ";
						char oneMore = charApsauga(oneMore);
						gen = oneMore;
						cout << endl;

					}
					catch (std::exception& e) {
						cout << "Nera tokio failo" << endl;
					}

				} while (gen == 'y');
			}

			else if (conType == 'd') {
				deque<data> s;
				do {
					try {
						string fname = "studentai";
						cout << "Iveskite studentu kieki: ";
						int skiekis = sveikojoApsauga(skiekis);
						fname += std::to_string(skiekis) + ".txt";

						cout << "(Vidurkis/Mediana) - (y/n) ";
						char vm = charApsauga(vm);
						cout << endl;

						auto laikasVisa = hrClock::now();
						string n = "nuskriaustukai.txt", k = "kietiakai.txt"; deque<data> Kieti; deque<data> Vargsai;

						generuotifailus(fname, skiekis, 5);
						skaitymas(s, fname);
						sort(s.begin(), s.end(), rikiuotiPazymi);
						skaiciavimai(s, vm);
						paskirstymas(s, Kieti, Vargsai, vm, st);
						std::sort(Kieti.begin(), Kieti.end(), [](data& x, data& y) {return x.vardas < y.vardas; });
						std::sort(Vargsai.begin(), Vargsai.end(), [](data& x, data& y) {return x.vardas < y.vardas; });
						buffRasymas(Kieti, k, vm);
						buffRasymas(Vargsai, n, vm);
						s.clear(); Kieti.clear(); Vargsai.clear();

						cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;
						cout << endl;

						cout << "Ar norite ivesti dar viena faila? (y/n) ";
						char oneMore = charApsauga(oneMore);
						gen = oneMore;
						cout << endl;

					}
					catch (std::exception& e) {
						cout << "Nera tokio failo" << endl;
					}

				} while (gen == 'y');

			}

			else if (conType == 'l') {
				list<data> s;
				do {
					try {
						string fname = "studentai";
						cout << "Iveskite studentu kieki: ";
						int skiekis = sveikojoApsauga(skiekis);
						fname += std::to_string(skiekis) + ".txt";

						cout << "(Vidurkis/Mediana) - (y/n) ";
						char vm = charApsauga(vm);
						cout << endl;

						auto laikasVisa = hrClock::now();
						string n = "nuskriaustukai.txt", k = "kietiakai.txt"; list<data> Kieti; list<data> Vargsai;

						generuotifailus(fname, skiekis, 5);
						skaitymas(s, fname);
						s.sort(rikiuotiPazymi);
						skaiciavimai(s, vm);
						paskirstymas(s, Kieti, Vargsai, vm, st);
						Vargsai.sort(rikiuoti);
						Kieti.sort(rikiuoti);
						buffRasymas(Kieti, k, vm);
						buffRasymas(Vargsai, n, vm);
						s.clear(); Kieti.clear(); Vargsai.clear();

						cout << "Visa programa uztruko " << durationDouble(hrClock::now() - laikasVisa).count() << " s" << endl;
						cout << endl;

						cout << "Ar norite ivesti dar viena faila? (y/n) ";
						char oneMore = charApsauga(oneMore);
						gen = oneMore;
						cout << endl;

					}
					catch (std::exception& e) {
						cout << "Nera tokio failo" << endl;
					}

				} while (gen == 'y');

			}

			else if (gen == 'n') { // Skaito viena faila
				vector<data> s;
				try {
                    //cout << "(Vidurkis/Mediana) - (y/n) ";
					//char vm = charApsauga(vm);
					//std::ifstream fr("studentai.txt");
					std::ofstream fp("kursiokai.txt");
					vector<string> head; // virsutines eilutes nuskaitymas
					skaitymas(s, "studentai.txt");
					skaiciavimai(s, 'a');
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
			vector<data> s;
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
			antraste(vm);
			for (int i = 0; i < s.size(); i++) {
				output(s.at(i), vm);
			}

			s.clear();
		}


		system("pause");
	}
}














