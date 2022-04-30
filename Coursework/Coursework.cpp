#include <iostream>
using namespace std;
#include "Functions.h"
#include <fstream>

void main()
{
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    char MenuChoise, Exit, del;


    do
    {
        do
        {
            system("cls");
            cout << "******** КОЛЛЕКЦИЯ ********" << endl << endl;
            cout << "(1) ДОБАВИТЬ НОВЫЙ ПРЕДМЕТ" << endl << "(2) РЕДАКТИРОВАТЬ ПРЕДМЕТ" << endl << "(3) УДАЛИТЬ ПРЕДМЕТ" << endl
                << "(4)?? ПОКАЗАТЬ ВСЮ КОЛЛЕКЦИЮ" << endl << "(5) ПОКАЗАТЬ ОДИН ПРЕДМЕТ" << endl << "(6) НАЙТИ ПРЕДМЕТЫ ПО ПАРАМЕТРУ" <<
                endl << "(7) ВЫХОД" << endl << endl;
            MenuChoise = _getch();
        } while (MenuChoise != '1' && MenuChoise != '2' && MenuChoise != '3' && MenuChoise != '4'
            && MenuChoise != '5' && MenuChoise != '6' && MenuChoise != '7' && MenuChoise != '8' && MenuChoise != '9');
        
        
        
        switch (MenuChoise)
        {
        case '1':
        {
            long long int number;
            Collection a;
            cout << "Добавление нового предмета" << endl << endl;
            cout << "Введите тип: " << endl;
            cin >> a.Tipe;
            cout << "Введите номинал: " << endl;
            cin >> a.Nominal;
            cout << "Введите год: " << endl;
            cin >> a.Year;
            cout << "Введите цену: " << endl;
            cin >> a.Prise;

            number = Last();

            ofstream F;
            F.open("D:\Courswork.txt", ios::app);
            F << endl << "Тип: " << a.Tipe << endl;
            F << "Номинал: " << a.Nominal << "ед." << endl;
            F << "Год: " << a.Year << "г." << endl;
            F << "Цена: " << a.Prise << "руб." << endl;
            F << number + 1 << "." << endl;
            F.close();

            break;
        }
        case '2':
        {
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

            ifstream wifs{ "D:\Courswork.txt" };
            ofstream wofs{ "D:\TimeCourswork.txt" };

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

            Collection a;
            cout << "Редактирование предмета" << endl << endl;
            cout << "Введите тип: " << endl;
            cin >> a.Tipe;
            cout << "Введите номинал: " << endl;
            cin >> a.Nominal;
            cout << "Введите год: " << endl;
            cin >> a.Year;
            cout << "Введите цену: " << endl;
            cin >> a.Prise;

            number = Last();

            ofstream F{ "D:\Courswork.txt", ios::app };
            F << endl << "Тип: " << a.Tipe << endl;
            F << "Номинал: " << a.Nominal << "ед." << endl;
            F << "Год: " << a.Year << "г." << endl;
            F << "Цена: " << a.Prise << "руб." << endl;
            F << number + 1 << "." << endl;
            F.close();

            ofstream F1{ "D:\Courswork.txt", ios::app };
            ifstream F2{ "D:\TimeCourswork.txt" };
            string string; //Строка-буфер
            while (getline(F2, string))  //Считываешь из файла строку (пока не EOF)
                F1 << string << std::endl;  //И записываешь эту строку в выходной файл
            F1.close();
            F2.close();
            break;
        }
        case '3': //Придумать как изменять нумерацию
        {
            string predmet, input;
            cout << "Введите какой предмет удалить: " << endl;
            cin >> input;
            cin.get();
            predmet = input + ".";

            int number_of_line = searcher(predmet);

            for (int n = number_of_line; n > number_of_line - 6; n--) {
                dell(n);
            }
            break;
        }

        case '4':
        {
            break;
        }

        case '5':
        {
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
            break;
        }

        case '6':
        {
            find_parametr();
            break;
        }
        case '7':
        {
            return;
        }
        }
    
        cout << endl << "Хотите выполнить другое действие? (1 - да, 0 - нет)" << endl;
        cin >> Exit;
    } while (Exit != '0');
    
}
