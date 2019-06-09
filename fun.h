#ifndef fun_H_INCLUDED
#define fun_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <sstream>
#include <chrono>
#include <vector>
#include <random>
#include <map>
#include <codecvt>
#include <regex>


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::setprecision;
using std::left;
using std::fixed;
using std::ifstream;
using std::ofstream;
using std::map;

struct Words
{
    vector<string> w;
    map<string,int> word_map;
    map<string,vector<int>> where_map;
    vector<string> url;
};

void fix(string &wor);
bool ifurl(string wor);
void read(Words &word);
void write(Words &word);


#endif // 2F_H_INCLUDED
