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
    string FileName = "D:\Courswork.txt";
    string TimeFileName = "D:\TimeCourswork.txt";
	string Tipe;
	int Nominal;
	int Year;
	int Prise;
    
private:

	
};



class Record : public Collection
{
public:
	void conclution() {
        long long int number;
        Collection a;
        cout << "���������� ������ ��������" << endl << endl;
        cout << "������� ���: " << endl;
        cin >> a.Tipe;
        cout << "������� �������(���� ��� �������� ������� 0): " << endl;
        cin >> a.Nominal;
        cout << "������� ���: " << endl;
        cin >> a.Year;
        cout << "������� ����: " << endl;
        cin >> a.Prise;

        number = Last();

        ofstream F;
        F.open(a.FileName, ios::app);
        F << endl << "���: " << a.Tipe << endl;
        F << "�������: " << a.Nominal << "��." << endl;
        F << "���: " << a.Year << "�." << endl;
        F << "����: " << a.Prise << "���." << endl;
        F << number + 1 << "." << endl;
        F.close();

	}
};