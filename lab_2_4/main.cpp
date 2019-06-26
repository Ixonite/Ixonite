#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int k,s=0;
	cout<<"Введите число: ";
	cin>>k;
	for(int i=2; i<=sqrt(k); i++) {
		if (k%i==0)
			s+=1;
	}
	if(s<1)
		cout<<"Да";
	else
		cout<<"Нет";
	return 0;
}
