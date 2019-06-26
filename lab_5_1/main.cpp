#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	string path = "hello.txt";
	ifstream fin(path); // открыли файл для чтения
	if (!fin.is_open()) {
		cout << "error" << endl;
	} else {
		cout << "Файл открылся" << endl;
		string str;
		while (!fin.eof()) {
			fin >> str;// считали первое слово из файла
			if (!fin.eof()) {
				cout << str << endl;
				int value = atoi(str.c_str());//перевод из строки в число
				cout << setw (5) << oct << value << setw (5) << dec << value << setw (5) << hex << value << endl;// перевод в с.с
			}
		}
	}
	fin.close(); // закрываем файл
	return 0;
}

/* #include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i[10];
	for (int v = 0; v < 10; v++) {
		cin >> i[v];
		cout << setw (5) << oct << i[v] << setw (5) << dec << i[v] << setw (5) << hex << i[v] << endl;
	}
	return 0;
}*/
