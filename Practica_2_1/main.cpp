#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	time_t t = time(NULL);
	tm * ptm;
	char buffer [80];  // строка, в которой будет храниться текущее время
	ptm = localtime(&t);
	strftime (buffer,80,"%c",ptm); // форматируем строку време
	cout<< buffer << endl;
	return 0;
}
