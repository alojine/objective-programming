#include "calculations.h"

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

void select(vector<data>& s, char vm) {
	for (auto& el : s) {
		if (vm == 'v') el.v = vidurkis(el.p, el.egz);
		else if (vm == 'm') el.m = mediana(el.p, el.egz);
		else if (vm == 'y') {
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