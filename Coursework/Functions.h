#pragma once
using namespace std;
#include <iostream>
#include <windows.h>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <algorithm>
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
    string FileName = "Courswork.txt";
    string TimeFileName = "TimeCourswork.txt";
	string Tipe;
	int Nominal;
	int Year;
	int Prise;
};

class Record : public Collection
{
public:
	void conclution() {
        long long int number;
        cout << "���������� ������ ��������" << endl << endl;
        cout << "������� ���: " << endl;
        getline(cin,Tipe);
        cout << "������� �������(���� ��� �������� ������� 0): " << endl;
        cin >> Nominal;
        cout << "������� ���: " << endl;
        cin >> Year;
        cout << "������� ����: " << endl;
        cin >> Prise;

        number = Last();

        ofstream F;
        F.open(FileName, ios::app);
        F << endl << "���: " << Tipe << endl;
        F << "�������: " << Nominal << "��." << endl;
        F << "���: " << Year << "�." << endl;
        F << "����: " << Prise << "���." << endl;
        F << number + 1 << "." << endl;
        F.close();
	}
};