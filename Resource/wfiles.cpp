#include "wfiles.h"

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