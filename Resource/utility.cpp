#include "utility.h"

void tabletop(char vm) {
	if (vm == 'm') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << endl;
	else if (vm == 'v') cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << endl;
};