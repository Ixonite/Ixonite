#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
	string str = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
	int a = 0, c = 0, l = 0, o = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\n')
			continue;
		++a;
		if (str[i] >= '0' && str[i] <= '9') {
			++c;
		} else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			++l;
		} else
			++o;
	}
	cout <<"Всего = " << a << endl;
	cout << "Чисел = " << c << endl;
	cout << "Букв = " << l << endl;
	cout << "Других символов = " << o << endl;
	return 0;
}
