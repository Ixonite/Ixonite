#include <iostream>
using namespace std;
/* функция преобразует символы строки к верхнему регистру
 * * Параметры:
 * *     s - указатель на строку с нулевым окончанием
 * * Результат:
 * *     преобразует строку "на месте" */
void toUpperCase(char * s)
{
	int i = 0;
	while(s[i] != 0) {
		if(('a' <=  s[i] && s[i] <= 'z')) s[i] = s[i] - 32; // проверка регистра ,если нижний ,то переводит в верхний 
		i++;
	}
}
// главная функция программы
// проверяем работу функции toUpperCase()
int main()
{
	char test[] = "test";
	toUpperCase(test);
	cout << test << endl;
	char hello[] = "Hello! World";
	toUpperCase(hello);
	cout << hello << endl;
	return 0;
}
