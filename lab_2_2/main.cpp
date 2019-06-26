#include <iostream>
using namespace std;
int main()
{
	int x,y;
	cout<<"Введите искомое число: \n";
	cin>>x;
	if (x != 0) {

		cout<<"Введите элементы последовательности: "<<endl;
		do{
			cin>>y;
				if (y==x) {
					cout<<"Найдено"<<endl;
					cout<<y<<endl;
					return 0;
				}
		}while(y!=0);
		cout << "Не найдено" << endl;
		return 0;
	}
}
