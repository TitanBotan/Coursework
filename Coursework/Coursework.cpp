using namespace std;
#include "Functions.h"

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
                << "(4) ПОКАЗАТЬ ВСЮ КОЛЛЕКЦИЮ (ОТСОРТИРОВАНА ПО АЛФАВИТУ)" << endl << "(5) ПОКАЗАТЬ ОДИН ПРЕДМЕТ" << endl << "(6) НАЙТИ ПРЕДМЕТЫ ПО ПАРАМЕТРУ" <<
                endl << "(7) ВЫХОД" << endl << endl;
            MenuChoise = _getch();
        } while (MenuChoise != '1' && MenuChoise != '2' && MenuChoise != '3' && MenuChoise != '4'
            && MenuChoise != '5' && MenuChoise != '6' && MenuChoise != '7' && MenuChoise != '8' && MenuChoise != '9');
        
        switch (MenuChoise)
        {
        case '1':
        {
            Record fun;
            fun.conclution();

            break;
        }
        case '2':
        {
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

            Record fun;
            fun.conclution();

            ofstream F1{ a.FileName, ios::app };
            ifstream F2{ a.TimeFileName };
            string string; //Строка-буфер
            while (getline(F2, string))  //Считываешь из файла строку (пока не EOF)
                F1 << string << std::endl;  //И записываешь эту строку в выходной файл
            F1.close();
            F2.close();
            break;
        }
        case '3':
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
            delete mas;
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
        //cin >> Exit;
        Exit = _getch();
    } while (Exit != '0');
    
}
