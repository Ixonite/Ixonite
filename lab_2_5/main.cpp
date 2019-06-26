#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,s=0;
	do {
		cout<<"Введите очередной элемент: "<<endl;
		cin>>n;
		if (n != 0) {
			for(int j=2; j<=sqrt(n); j++) {
				if(n%j==0)
					s++;
			}
			if(s<1) {
				cout<<n<<" - Простое"<<endl;
			}
			s = 0;
		} else {
			break;
		}
	}while(n!=0);
	return 0;
}
