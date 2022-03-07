#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;
using std::ofstream;

struct data {
	string vardas = "", pavarde = "";
	vector<int> p;
	int n = 0;
	int egz = 0;
	double v = 0, m = 0;
};