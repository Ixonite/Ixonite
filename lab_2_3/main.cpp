#include <iostream>
using namespace std;
int main()
{
	int n,s=0;
	cout<<"Введите элементы последовательности: \n";
	do {
		cin>>n;
		if (n > 0) {
			s += n;
		} else if (n < 0)
			break;
	}while(n!=0);
	cout<<"Сумма: "<<s;
	return 0;
}
