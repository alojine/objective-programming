#include "headers.h"

void input(data& s) {
	cout << "Iveskite studento varda: "; cin >> s.vardas;
	cout << "Iveskite studento pavarde: "; cin >> s.pavarde;
	cout << "Iveskite pazymiu kieki: ";
	int pazimys;
	int kiek = sveikojoApsauga(kiek);
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
		check = charApsauga(check);

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

void output(data& s, char vm) {

	cout << string(60, '-') << std::endl;
	cout << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde;
	if (vm == 'y') cout << std::left << std::setw(23) << std::setprecision(2) << s.v << endl;
	else if (vm == 'n') cout << std::left << std::setw(20) << std::setprecision(2) << s.m << endl;
};

//-------------------------------------------------------------------------------------------------------------------



void generuotifailus(string& failopavadinimas, int kiek, int nd) {

	ofstream rf(failopavadinimas);

	string ndskaicius = "ND";
	string vardas = "Vardas";
	string pavarde = "Pavarde";

	auto start = hrClock::now();    // pradedamas skaiciavimas

	rf << std::left << std::setw(15) << "Vardas" << std::right << std::setw(15) << "Pavarde";
	for (int i = 0; i < nd; i++) {
		rf << std::right << std::setw(15) << ndskaicius + std::to_string(i + 1);
	}
	rf << std::right << std::setw(15) << "Egz." << endl;

	for (int i = 0; i < kiek; i++) {
		rf << std::left << std::setw(15) << vardas + std::to_string(i + 1) << std::right << std::setw(15) << pavarde + std::to_string(i + 1);
		for (int j = 0; j < nd; j++) {
			rf << std::right << std::setw(15) << genrand();
		}
		rf << std::right << std::setw(15) << genrand(); if (i + 1 != kiek) rf << endl;    // if sakinys, kad isvengti papildomo nuskaitymo kai pabaigoje failo endline ideda
	}

	cout << "Failo sudarymas uztruko: " << durationDouble(hrClock::now() - start).count() << endl;

	rf.close();
}

void skaitymas(vector<data>& s, string fname) {
	auto laikasSkaitymas = hrClock::now();
	ifstream fd(fname);
	if (fd.is_open()) {
		int nd, egz;
		int st = 0, mk = 0;
		string line;
		std::stringstream buffer;
		std::getline(fd, line);
		

		// Nustatomas mokiniu kiekis
		buffer << line;
		string reiksme;
		while (buffer >> reiksme) st++;
		for (int l = 0; std::getline(fd, line); l++) mk++;
		fd.clear();
		fd.seekg(0);
		std::getline(fd, line);

		data temp;
		for (int i = 0; i < mk; i++) {
			fd >> temp.vardas >> temp.pavarde;
			temp.p.reserve(st - 3);
			for (int j = 0; j < st - 3; j++) {
				fd >> nd;
				temp.p.push_back(nd);
			}
			fd >> temp.egz;
			temp.p.clear();
			s.push_back(temp);
		}
	}
	fd.close();
	cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - laikasSkaitymas).count() << " s" << endl;
}

void skaitymas(deque<data>& s, string fname) {
	auto laikasSkaitymas = hrClock::now();
	ifstream fd(fname);
	if (fd.is_open()) {
		int nd, egz;
		int st = 0, mk = 0;
		string line;
		std::stringstream buffer;
		std::getline(fd, line);


		// Nustatomas mokiniu kiekis
		buffer << line;
		string reiksme;
		while (buffer >> reiksme) st++;
		for (int l = 0; std::getline(fd, line); l++) mk++;
		fd.clear();
		fd.seekg(0);
		std::getline(fd, line);

		data temp;
		for (int i = 0; i < mk; i++) {
			fd >> temp.vardas >> temp.pavarde;
			temp.p.reserve(st - 3);
			for (int j = 0; j < st - 3; j++) {
				fd >> nd;
				temp.p.push_back(nd);
			}
			fd >> temp.egz;
			temp.p.clear();
			s.push_back(temp);
		}
	}
	fd.close();
	cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - laikasSkaitymas).count() << " s" << endl;
}

void skaitymas(list<data>& s, string fname) {
	auto laikasSkaitymas = hrClock::now();
	ifstream fd(fname);
	if (fd.is_open()) {
		int nd, egz;
		int st = 0, mk = 0;
		string line;
		std::stringstream buffer;
		std::getline(fd, line);


		// Nustatomas mokiniu kiekis
		buffer << line;
		string reiksme;
		while (buffer >> reiksme) st++;
		for (int l = 0; std::getline(fd, line); l++) mk++;
		fd.clear();
		fd.seekg(0);
		std::getline(fd, line);

		data temp;
		for (int i = 0; i < mk; i++) {
			fd >> temp.vardas >> temp.pavarde;
			temp.p.reserve(st - 3);
			for (int j = 0; j < st - 3; j++) {
				fd >> nd;
				temp.p.push_back(nd);
			}
			fd >> temp.egz;
			temp.p.clear();
			s.push_back(temp);
		}
	}
	fd.close();
	cout << "Failo nuskaitymas uztruko: " << durationDouble(hrClock::now() - laikasSkaitymas).count() << " s" << endl;
}

void rp(vector<int> p) {
	for (auto& a : p) {
		cout << a << " ";
	}
}

void buffRasymas(vector<data>& s, string fname, char vm) {
	auto laikasNuskriaustukai = hrClock::now();

	std::stringstream buffer;
	buffer << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
	if (vm == 'y') buffer << std::left << std::setw(20) << "Galutinis(Vid.)";
	else if(vm == 'n') buffer << std::left << std::setw(20) << "Galutinis(Med.)";
	buffer << endl;

	if (vm == 'y') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.v << endl;
		}
	}

	else if (vm == 'n') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.m << endl;
		}
	}

	buffer.clear();

	buffFaila(fname, buffer);
	cout << fname << " surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;

};

void buffRasymas(deque<data>& s, string fname, char vm) {
	auto laikasNuskriaustukai = hrClock::now();

	std::stringstream buffer;
	buffer << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
	if (vm == 'y') buffer << std::left << std::setw(20) << "Galutinis(Vid.)";
	else if (vm == 'n') buffer << std::left << std::setw(20) << "Galutinis(Med.)";
	buffer << endl;

	if (vm == 'y') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.v << endl;
		}
	}

	else if (vm == 'n') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.m << endl;
		}
	}

	buffer.clear();

	buffFaila(fname, buffer);
	cout << fname << " surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;

};

void buffRasymas(list<data>& s, string fname, char vm) {
	auto laikasNuskriaustukai = hrClock::now();

	std::stringstream buffer;
	buffer << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
	if (vm == 'y') buffer << std::left << std::setw(20) << "Galutinis(Vid.)";
	else if (vm == 'n') buffer << std::left << std::setw(20) << "Galutinis(Med.)";
	buffer << endl;

	if (vm == 'y') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.v << endl;
		}
	}

	else if (vm == 'n') {
		for (auto& el : s) {
			buffer << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.m << endl;
		}
	}

	buffer.clear();

	buffFaila(fname, buffer);
	cout << fname << " surasymas uztruko: " << durationDouble(hrClock::now() - laikasNuskriaustukai).count() << " s" << endl;

};

void buffFaila(string fname, std::stringstream& buffer) {
	ofstream fp(fname);
	fp << buffer.rdbuf();
	fp.close();
};


void paskirstymas(vector<data>& s, vector<data>& Kieti, vector<data>& Vargsai, char vm, char stratType) {

	auto laikasSkirstymas = hrClock::now();

	if (stratType == 'n') {
		vector<data>::iterator it = s.end();
		it--;

		if (vm == 'y') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->v < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}

		if (vm == 'n') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->m < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}
		Kieti = s;
		s.clear();
	}
	
	else if (stratType == 'y') {
		if (vm == 'y') {
			for (auto& el : s) {
				if (el.v >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

		else if (vm == 'n') {
			for (auto& el : s) {
				if (el.m >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

	}
	
	cout << "Failo skirstymas i grupes uztruko: " << durationDouble(hrClock::now() - laikasSkirstymas).count() << " s" << endl;
}

void paskirstymas(deque<data>& s, deque<data>& Kieti, deque<data>& Vargsai, char vm, char stratType) {

	auto laikasSkirstymas = hrClock::now();

	if (stratType == 'n') {
		deque<data>::iterator it = s.end();
		it--;

		if (vm == 'y') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->v < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}

		if (vm == 'n') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->m < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}
		Kieti = s;
		s.clear();
	}

	else if (stratType == 'y') {
		if (vm == 'y') {
			for (auto& el : s) {
				if (el.v >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

		else if (vm == 'n') {
			for (auto& el : s) {
				if (el.m >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

	}

	cout << "Failo skirstymas i grupes uztruko: " << durationDouble(hrClock::now() - laikasSkirstymas).count() << " s" << endl;
}

void paskirstymas(list<data>& s, list<data>& Kieti, list<data>& Vargsai, char vm, char stratType) {

	auto laikasSkirstymas = hrClock::now();

	if (stratType == 'n') {
		list<data>::iterator it = s.end();
		it--;

		if (vm == 'y') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->v < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}

		if (vm == 'n') {
			for (auto i = s.size() - 1; i > 0; i--) {
				if (it->m < 5) {
					Vargsai.push_back(*it);
					s.resize(s.size() - 1);
				}
				it--;
			}
		}
		Kieti = s;
		s.clear();
	}

	else if (stratType == 'y') {
		if (vm == 'y') {
			for (auto& el : s) {
				if (el.v >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

		else if (vm == 'n') {
			for (auto& el : s) {
				if (el.m >= 5) Kieti.push_back(el);
				else Vargsai.push_back(el);
			}
		}

	}

	cout << "Failo skirstymas i grupes uztruko: " << durationDouble(hrClock::now() - laikasSkirstymas).count() << " s" << endl;
}

//----------------------------------------------------------------------------------

void failoSkaitymas(ifstream& fr, vector<data>& s, vector<string>& l) {

	string length;

	while ((fr.peek() != '\n') && (fr >> length)) {
		l.push_back(length);
	}
	l.resize(l.size() - 3);

	int pazimys;
	while (!fr.eof()) {
		data temp;
		fr >> temp.vardas >> temp.pavarde;
		for (auto& el : l) {
			fr >> pazimys;
			temp.p.push_back(pazimys);
		}
		fr >> temp.egz;
		temp.n = temp.p.size();
		s.push_back(temp);
	}

};

void failoIsvedimas(ofstream& fp, data& s) {
	fp << std::left << std::setw(20) << s.vardas << std::left << std::setw(20) << s.pavarde << std::left << std::setw(20) << std::setprecision(3) << s.v << std::left << std::setw(20) << std::setprecision(3) << s.m << endl;
};


void failoAntraste(ofstream& fp) {

	fp << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	fp << string(80, '-') << std::endl;
};

//-------------------------------------------------------------------------------------------------------------------

int sveikojoApsauga(int& a) {
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> a;
	}
	return a;
};

char charApsauga(char& a) {
	do {
		cin >> a;
	} while (a != 'y' && a != 'n');
	return a;
};

char konteinerioApsauga(char& a) {
	do {
		cin >> a;

	} while (a != 'v' && a != 'd' && a != 'l');
	return a;
}
//-------------------------------------------------------------------------------------------------------------------

void skaiciavimai(vector<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'y') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'n') el.m = mediana(el.p, el.egz);
		else if (vm == 'a') {
			el.m = mediana(el.p, el.egz);
			el.v = vidurkis(el.p, el.egz);
		}
	}
};

void skaiciavimai(deque<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'y') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'n') el.m = mediana(el.p, el.egz);
		else if (vm == 'a') {
			el.m = mediana(el.p, el.egz);
			el.v = vidurkis(el.p, el.egz);
		}
	}
};

void skaiciavimai(list<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'y') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'n') el.m = mediana(el.p, el.egz);
		else if (vm == 'a') {
			el.m = mediana(el.p, el.egz);
			el.v = vidurkis(el.p, el.egz);
		}
	}
};

double vidurkis(vector<int> p, int egz) {
	double v = 0;
	for (auto& el : p) {
		v += el;
	}

	if (p.size() != 0) v = v / (p.size() * 1.0) * 0.4 + egz * 0.6;
	else v = egz * 0.6;

	return v;
};

double mediana(vector<int> p, int egz) {

	double m, s;
	sort(p.begin(), p.end());
	if (p.size() % 2 == 0 && p.size() != 0) {
		m = (double)((p[p.size() / 2] + p[p.size() / 2 - 1]) / 2);
		s = (m * 4 / 10) + (egz * 0.6);
	}
	else if (p.size() % 2 != 0 && p.size() != 0) {
		s = p[p.size() / 2] * 0.4 + egz * 0.6;
	}
	else s = egz * 0.6;

	return s;
};



void antraste(char vm) {
	if (vm == 'n') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	else if (vm == 'y') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
};

bool rikiuoti(data a, data b){
	return a.vardas < b.vardas;
}

bool rikiuotiPazymi(data a, data b) {
	return a.egz > b.egz;
}






