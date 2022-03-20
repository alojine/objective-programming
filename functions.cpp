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

void failoGeneratorius(ofstream& fr, int a) {
	auto laikasFailoKurimas = hrClock::now();
	vector<string> splitted;
	string eil;
	std::stringstream buffer; // buferis
	int b = 5;

	auto st = hrClock::now();

	buffer << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
	for (int i = 0; i < b; i++) {
		buffer << std::left << "ND" << std::setw(5) << i + 1;
	}
	buffer << std::left << std::setw(5) << "Egz" << endl;

	for (int i = 0; i < a; i++) {
		buffer << studentoGeneratorius(b, i).str();
	}

	fr << buffer.rdbuf();
	cout << "Failo kurimas ir jo uzdarymas uztruko: " << durationDouble(hrClock::now() - laikasFailoKurimas).count() << " s" << endl;
};

std::stringstream studentoGeneratorius(int b, int nr) {
	std::stringstream studentas;
	studentas << "Vardas" << std::left << std::setw(14) << nr + 1 << "Pavarde" << std::left << std::setw(13) << nr + 1;
	for (int i = 0; i <= b; i++) {
		studentas << std::left << std::setw(7) << genrand() << "";
	}
	studentas << endl;
	return studentas;
};

void buffSkaitymas(vector<data>& s, string fname) {
	auto laikasSkaitymas = hrClock::now();
	std::stringstream buffer;
	string l;
	ifstream open_f;
	open_f.open(fname);

	typedef std::chrono::high_resolution_clock Clock;
	auto start = Clock::now();

	buffer << open_f.rdbuf();
	open_f.close();
	std::getline(buffer, l);

	int t = 0;
	while (buffer) {
		std::getline(buffer, l);
		if (l.length() == 0) break;
		data temp;
		std::istringstream lStream(l);
		lStream >> temp.vardas >> temp.pavarde;
		int paz;
		while (lStream >> paz) {
			temp.p.push_back(paz);
		}
		temp.egz = temp.p.back();
		temp.p.pop_back();
		s.push_back(temp);
	}

	cout << "Failo skaitymas uztruko: " << durationDouble(hrClock::now() - laikasSkaitymas).count() << " s" << endl;
};

void buffRasymas(vector<data>& s, string fname, char vm) {
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

};

void buffFaila(string fname, std::stringstream& buffer) {
	ofstream fp(fname);
	fp << buffer.rdbuf();
	fp.close();
}

void skirstymas(vector<data> &s, std::stringstream& kietiakai, std::stringstream& nuskriaustukai, char vm) {
	auto laikasSkirstymas = hrClock::now();
	for (auto& el : s) {
		if (vm == 'y') {
			if (el.v >= 5) kietiakai << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.v << endl;
			else nuskriaustukai << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.v << endl;
		}
		else {
			if (el.m >= 5) kietiakai << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.m << endl;
			else nuskriaustukai << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.m << endl;
		}
	}
	s.clear();

	cout << "Failo skirstymas i grupes uztruko: " << durationDouble(hrClock::now() - laikasSkirstymas).count() << " s" << endl;
}

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

//-------------------------------------------------------------------------------------------------------------------

void select(vector<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'y') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'n') el.m = mediana(el.p, el.egz);
		else if (vm == 'abu') {
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

void tabletop(char vm) {
	if (vm == 'n') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	else if (vm == 'y') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
};



