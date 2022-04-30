#pragma once
using namespace std;
#include <iostream>
#include <windows.h>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;

int Last();
void last_line();


int searcher(string word);

string GetPredNumber(int n);

void dell(int n);

void find_parametr();

class Collection
{
public:
	string Tipe;
	int Nominal;
	int Year;
	int Prise;
};