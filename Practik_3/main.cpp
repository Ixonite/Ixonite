#include <iostream>
#include <limits>
using namespace std;
double* norm (int const size, double * mas)
{
	double max = numeric_limits<double>::min(), min = numeric_limits<double>::max();
	for (int i=0; i<size; i++) {
		if (max < mas[i])
			max = mas[i];
		else if (min > mas[i])
			min = mas[i];
	}
	double *d = new double [size];
	for (int i=0; i<size; i++) {
		mas[i]=(mas[i]- min)/(max-min);
		d[i]=mas[i];
	}
	return d;
	delete[]d;
	
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
	m = norm(N,m);
		for (int i=N - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (m[j] > m[j + 1]) {
				double k = m[j];
				m[j] = m[j + 1];
				m[j + 1] = k;
			}
		}
	for(int i=0;i<N;i++) {
		cout<< *(m+i)<<endl;
	}
	delete[]m;
	return 0;
}
