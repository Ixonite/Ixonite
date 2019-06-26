#include <iostream>
using namespace std;
template <typename T, int size> class Array
{
	T arr[size];
public:
	Array() {};
	Array(T x) {
		for (int i =0; i < size; i++)
			arr[i] = x;
	}
	Array(T * buf, int buf_size) {
		for (int i =0; i < buf_size; i++)
			arr[i] = buf[i];
	}
	T & operator [](const int index) {
		return arr[index];
	}
};
int main ()
{
	double buf[5] = {4.1, 27.2, 0.06, 7, 80};
	Array <double,5> arr(buf, 5);
	cout << arr[0] << " " << arr[1] << " ";
	arr[0] = 0.89;
	arr[2] = buf[4];
	cout << "\n Проверка оператора []: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	Array <int,3> arr1(5);
	arr1[2] = 6;
	int buf1[2] = {1, 76};
	arr1[1]=buf1[1];
	cout << "\nПроверка оператора []: ";
	for (int i = 0; i < 3; i++)
		cout << arr1[i] << " ";
	return 0;
}
