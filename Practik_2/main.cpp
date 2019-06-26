#include <iostream>
#include <limits>
using namespace std;
void norm (int const size, double * mas)
{
	double max = numeric_limits<double>::min(), min = numeric_limits<double>::max();
	for (int i=0; i<size; i++) {
		if (max < mas[i])
			max = mas[i];
		else if (min > mas[i])
			min = mas[i];
	}
	for (int i=0; i<size; i++) {
		mas[i]=(mas[i]- min)/(max-min);
	}

	for (int i=size - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (mas[j] > mas[j + 1]) {
				double k = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = k;
			}
		}
}
int main()
{
	int N;
	cout<<"Введите размер: "<<endl;
	cin>>N;
	double *m = new double [N];
	cout<<"Введите значения: "<<endl;
	for(int i=0; i < N ; i++) {
		cin>>m[i];
	}
	norm (N,m);
	for(int i=0; i < N ; i++) {
		cout<<"Результат нормировки: "<< m[i]<<endl;
	}
	delete[]m;
	return 0;
}
