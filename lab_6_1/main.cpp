#include <iostream>
using namespace std;
template <typename T> T sort (T* arr, int size)
{
	double temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return *arr;
}
int main()
{
	double b[] = {1.0123, 0.9342,3.923};
	int a[] = {0, 35, -9, 10, 23, 7, -94};
	cout << "Массив типа int: ";
	sort <int> (a, 7);
	for (int i = 0; i < 7; i++)
		cout<< a[i]<<" ";
	cout << "\n" ;
	cout << "Массив типа double: ";
	sort <double> (b, 3);
	for (int i = 0; i< 3; i++)
		cout<< b[i]<<" ";
	return 0;
}
