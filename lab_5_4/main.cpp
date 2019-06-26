#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	ifstream fin1("fail1.txt"); // открыли файл для чтения
	if (!fin1.is_open()) { // проверка на открытие файла
		cout << "error" << endl;
	} else {
		cout << "Файл 1 открылся" << endl;
	}
	ofstream fin2;
	fin2.open("fail2.txt",ofstream::app);
	if (!fin2.is_open()) { // проверка на открытие файла
		cout << "error" << endl;
	} else {
		cout << "Файл 2 открылся" << endl;
	}
	string str;
	while (getline(fin1,str)) {
		if (!fin2.eof()) {
			fin2 << str <<endl;
		}
	}
	fin1.close(); // закрываем файл
	fin2.close (); // закрываем файл

	return 0;
}
