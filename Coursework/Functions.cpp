#include "Functions.h"
#include <string>
using namespace std;

string str = "";
int Last() {
    int counter = 0;
    ofstream outClientFile("D:\Courswork.txt", ios::app);
    if (!outClientFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    outClientFile.close();
    last_line();
    const char* c_str = str.c_str();
    int number = atoi(c_str);
    return number;
}

void last_line()
{
    ifstream inClientFile("D:\Courswork.txt", ios::in);
    if (!inClientFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    string buf;
    while (getline(inClientFile, buf))
        str = buf;
}

int searcher(string word)
{

    string filename = "D:\Courswork.txt";

    ifstream File;
    File.open(filename); //������� �������� �����
    if (!File.is_open()) //� ������ �������� ��������
        exit(EXIT_FAILURE); //������ ��������� ���������

    int number_of_lines = 0; //����� ������
    string line;
    while (getline(File, line))
    {
        number_of_lines += 1;
        if ((line.find(word) != string::npos) && (line.find(word) != (-1)))
        {
            return number_of_lines; //(���� ����� ����� - ������� �� �������)
        }
        //����� ���������� while
    }
    cout << "����� ������� �� ������. �� �� ��� ������� ��� ��� ������. "  << endl;
    File.close(); //��������� �������� ����
}

string GetPredNumber(int n)
{
    string strr;
    ifstream fs("D:\Courswork.txt");
    int i = 1;

    while (getline(fs, strr))
    {
        if (i == n)
        {
            break;
        }

        i++;
    }

    fs.close();

    return strr;
}

void dell(int n) {
    ifstream file_in;

    file_in.open("D:\Courswork.txt");

    if (!file_in)
    {
        cerr << "������, ���������� ������� ���� : text.txt" << std::endl;
    }

    int i_number_line_delete = 0; //��� �������� ������ ������ ������� ����� �������
    i_number_line_delete = n;

    int i_number_line_now = 0; //������� �����
    string line; //��� �������� ������
    string line_file_text; //��� �������� ������ �����

    while (getline(file_in, line))
    {
        i_number_line_now++;

        if (!(i_number_line_now == i_number_line_delete))
        {
            line_file_text.insert(line_file_text.size(), line); /*�������� ������*/
            /*�������� ������� �� ��������� ������*/
            line_file_text.insert(line_file_text.size(), "\r\n");

        }
    }

    file_in.close();

    //������ � line_file_text ����� ����������� ���������� ����� �����, ������ ����� ������������ ����

    ofstream file_out;

    file_out.open("D:\Courswork.txt", std::ios::trunc | std::ios::binary); //������� � ��������

    //��������

    file_out.write(line_file_text.c_str(), line_file_text.size());
    file_out.clear();
}

void find_parametr() {
    char search[255], vvod[255], base[9] = { 0 }, * c; //search - ��� ����; answer - �����; base - ���� � ����;
    bool dialog = true;
    string line = "";
    int n = 0;
    int vibor;
    int k = 255;
    int kon = 0;

    cout << "������� ���, �� �������� ����� ��������� ����� (1-���, 2-�������, 3-���, 4-����)" << endl;
    cin >> vibor;
    //vibor = _getch();
    cout << endl << "������� ��������: ";
    cin >> vvod;
    if (vibor == 1) {
        for (int i = 0, j = 0; i < 255; i++)
            if (vvod[i] != k)
                search[j++] = vvod[i];
    }
    else if (vibor == 2) {
        int i = 0;
        while (vvod[i] == '0' or vvod[i] == '1' or vvod[i] == '2' or vvod[i] == '3' or vvod[i] == '4' or vvod[i] == '5' or vvod[i] == '6' or vvod[i] == '7' or vvod[i] == '8' or vvod[i] == '9') {
            i += 1;
            kon += 1;
        }
        vvod[kon] = '�';
        vvod[kon + 1] = '�';
        vvod[kon + 2] = '.';
        vvod[kon + 3] = 0;

        for (int i = 0, j = 0; i < 255; i++)
            if (vvod[i] != k)
                search[j++] = vvod[i];
    }
    else if (vibor == 3) {
        int i = 0;
        while (vvod[i] == '0' or vvod[i] == '1' or vvod[i] == '2' or vvod[i] == '3' or vvod[i] == '4' or vvod[i] == '5' or vvod[i] == '6' or vvod[i] == '7' or vvod[i] == '8' or vvod[i] == '9') {
            i += 1;
            kon += 1;
        }
        vvod[kon] = '�';
        vvod[kon + 1] = '.';
        vvod[kon + 2] = 0;

        for (int i = 0, j = 0; i < 255; i++)
            if (vvod[i] != k)
                search[j++] = vvod[i];
    }
    else if (vibor == 4) {
        int i = 0;
        while (vvod[i] == '0' or vvod[i] == '1' or vvod[i] == '2' or vvod[i] == '3' or vvod[i] == '4' or vvod[i] == '5' or vvod[i] == '6' or vvod[i] == '7' or vvod[i] == '8' or vvod[i] == '9') {
            i += 1;
            kon += 1;
        }
        vvod[kon] = '�';
        vvod[kon + 1] = '�';
        vvod[kon + 2] = '�';
        vvod[kon + 3] = '.';
        vvod[kon + 4] = 0;

        for (int i = 0, j = 0; i < 255; i++)
            if (vvod[i] != k)
                search[j++] = vvod[i];
    }
    else cout << "������!!!";

    string s = "D:\Courswork.txt";
    ifstream input(s.c_str());
    if (!input)
    {
        cout << "������ ��� �������� �����.\n";
    }
    else
    {
        char buffer[1024];
        while (input.getline(buffer, 1024)) {
            n += 1;
            if (strstr(buffer, search)) {
                if (vibor == 1) {
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
                else if (vibor == 2) {
                    line = GetPredNumber(n - 1);
                    cout << line << endl;

                    cout << buffer << endl;

                    line = GetPredNumber(n + 1);
                    cout << line << endl;
                    line = GetPredNumber(n + 2);
                    cout << line << endl;
                    line = GetPredNumber(n + 3);
                    cout << line << endl;
                }
                else if (vibor == 3) {
                    line = GetPredNumber(n - 2);
                    cout << line << endl;
                    line = GetPredNumber(n - 1);
                    cout << line << endl;

                    cout << buffer << endl;

                    line = GetPredNumber(n + 1);
                    cout << line << endl;
                    line = GetPredNumber(n + 2);
                    cout << line << endl;
                }
                else if (vibor == 4) {
                    line = GetPredNumber(n - 3);
                    cout << line << endl;
                    line = GetPredNumber(n - 2);
                    cout << line << endl;
                    line = GetPredNumber(n - 1);
                    cout << line << endl;

                    cout << buffer << endl;

                    line = GetPredNumber(n + 1);
                    cout << line << endl;
                }
            }
        }
    }
}