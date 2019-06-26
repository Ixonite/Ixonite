#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int k = 0;
	long double s =0;
	long double N = 0;
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	string path = "data_v26.txt";
	ifstream fin(path); // открыли файл для чтения
	if (!fin.is_open()) { // проверка на открытие файла
		cout << "error" << endl;
	} else {
		cout << "Файл открылся" << endl;
		string str;
		while (!fin.eof()) { //проверка на конец файла
			fin >> str;// считали первое слово из файла
			if (!fin.eof()) { // проверка на конец файла
				long double value = atof(str.c_str());//перевод из строки в число float
				s = value + s;
				k++;
			}
		}
		N= s / k;
		cout <<"Среднее арифметическое значение = "<< N <<endl;
	}
	fin.close(); // закрываем файл
	return 0;
}
