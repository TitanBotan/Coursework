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

	void Function1 () {
        long long int number;
        Collection a;

        
        cout << "Добавление нового предмета" << endl << endl;
        cout << "Введите тип: " << endl;
        cin >> a.Tipe;
        cout << "Введите номинал(если нет номинала введите 0): " << endl;
        cin >> a.Nominal;
        cout << "Введите год: " << endl;
        cin >> a.Year;
        cout << "Введите цену: " << endl;
        cin >> a.Prise;

        number = Last();

        ofstream F;
        F.open(a.FileName, ios::app);
        F << endl << "Тип: " << a.Tipe << endl;
        F << "Номинал: " << a.Nominal << "ед." << endl;
        F << "Год: " << a.Year << "г." << endl;
        F << "Цена: " << a.Prise << "руб." << endl;
        F << number + 1 << "." << endl;
        F.close();
	}

    void Function2() {
        Collection a;
        long long int number;
        string predmet, input;
        cout << "Введите какой предмет редактировать: " << endl;
        cin >> input;
        cin.get();
        predmet = input + ".";

        int number_of_line = searcher(predmet);

        int number_last = Last();
        stringstream out;
        out << number_last;
        input = out.str();

        string predmet_last = input + ".";
        number_last = searcher(predmet_last);

        ifstream wifs{ a.FileName };
        ofstream wofs{ a.TimeFileName };

        int i = number_of_line + 1;
        while (i < (number_last + 1)) {
            wofs << GetPredNumber(i) << endl;
            i += 1;
        }
        i = number_last;
        while (i != number_of_line - 6) {
            dell(i);
            i -= 1;
        }
        wifs.close();
        wofs.close();

        cout << "Редактирование предмета" << endl << endl;
        cout << "Введите тип: " << endl;
        cin >> a.Tipe;
        cout << "Введите номинал(если нет номинала введите 0): " << endl;
        cin >> a.Nominal;
        cout << "Введите год: " << endl;
        cin >> a.Year;
        cout << "Введите цену: " << endl;
        cin >> a.Prise;

        number = Last();

        ofstream F{ a.FileName, ios::app };
        F << endl << "Тип: " << a.Tipe << endl;
        F << "Номинал: " << a.Nominal << "ед." << endl;
        F << "Год: " << a.Year << "г." << endl;
        F << "Цена: " << a.Prise << "руб." << endl;
        F << number + 1 << "." << endl;
        F.close();

        ofstream F1{ a.FileName, ios::app };
        ifstream F2{ a.TimeFileName };
        string string; //Строка-буфер
        while (getline(F2, string))  //Считываешь из файла строку (пока не EOF)
            F1 << string << std::endl;  //И записываешь эту строку в выходной файл
        F1.close();
        F2.close();
    }

    void Function3() {
        string predmet, input;
        cout << "Введите какой предмет удалить: " << endl;
        cin >> input;
        cin.get();
        predmet = input + ".";

        int number_of_line = searcher(predmet);

        for (int n = number_of_line; n > number_of_line - 6; n--) {
            dell(n);
        }
    }

    void Function4() {
        Collection a;
        int i = 0;
        int k = 3;
        int dl = Last();
        //char vvod[50] = "";
        char search[50] = "";
        string st = "";
        string* mas = new string[dl];
        while (i < dl) {
            mas[i] = GetPredNumber(k);
            i += 1;
            k += 6;
        }

        sort(mas, mas + dl);

        i = 0;

        while (i < dl) {
            //cout << mas[i] << endl;
            if ((i == 0) or (mas[i - 1] != mas[i]))
            {
                st = mas[i];

                const char* vvod = st.c_str();

                for (int ii = 0, j = 0; ii < 50; ii++)
                    if (vvod[ii] != 50)
                        search[j++] = vvod[ii];
                int n = 0;
                string line = "";
                string s = a.FileName;
                ifstream input(s.c_str());
                char buffer[1024];
                while (input.getline(buffer, 1024)) {
                    n += 1;
                    if (strstr(buffer, search)) {
                        cout << buffer << endl;

                        line = GetPredNumber(n + 1);
                        cout << line << endl;
                        line = GetPredNumber(n + 2);
                        cout << line << endl;
                        line = GetPredNumber(n + 3);
                        cout << line << endl;
                        line = GetPredNumber(n + 4);
                        cout << line << endl << endl;
                    }
                }
            }
            i += 1;
        }
    }

    void Function5() {
        string predmet, input;
        cout << "Введите какой предмет найти: " << endl;
        cin >> input;
        cin.get();
        predmet = input + ".";

        int number_of_line = searcher(predmet);

        //cout << number_of_line << endl;

        for (int n = number_of_line - 4; n < number_of_line; n++) {
            string line = GetPredNumber(n);
            cout << line << endl;
        }
    }
private:

	string Tipe;
	int Nominal;
	int Year;
	int Prise;
};