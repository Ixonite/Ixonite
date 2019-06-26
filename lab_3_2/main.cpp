#include <iostream>
#include <string>
using namespace std;
int main()
{
	string d = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
	string m, y;
	cout<<"Введите слово которое хотите заменять\n";
	cin>> m;
	cout<< "Введите слово на которое хотите заменять\n";
	cin>>y;
	for (int i = 0; i < d.length(); i++) {
		if (d.substr(i, m.length()) == m)
			d.replace(i, m.length(), y);
	}
	cout<< d <<endl;
	return 0;
}
