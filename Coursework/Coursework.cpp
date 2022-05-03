using namespace std;
#include "Functions.h"

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Collection Fun;
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
            Fun.Function1();

            break;
        }
        case '2':
        {
            Fun.Function2();
            break;
        }
        case '3':
        {
            Fun.Function3();
            break;
        }

        case '4':
        {
            Fun.Function4();
            break;
        }

        case '5':
        {
            Fun.Function5();
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
