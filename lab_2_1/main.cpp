#include<iostream>
using namespace std;
int main()
{
	cout<<"Введите длину последовательност N: ";
	int N;
	float a,arifm,s=0;
	cin>>N;
	cout<<"Введите элементы последовательности: "<<endl;
	for(int i=0; i<N; i++) {
		cin>>a;
		s+=a;
	}
	arifm = s / N;
	cout<<"Среднее арифметическое равно: "<< arifm <<endl;
	return 0;
}
