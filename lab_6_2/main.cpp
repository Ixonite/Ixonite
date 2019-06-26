#include <iostream>
using namespace std;
template <typename T> void sort (T * arr, int size)
{
	for (int i=size - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (arr[j] > arr[j + 1]) {
				T t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
}
template <typename T> class Rectangle
{
	T height = T();
	T width = T();
public:
	Rectangle() {};
	Rectangle(T _height, T _width) {
		height = _height;
		width = _width;
	}
	bool operator >(const Rectangle _height) {
		return (height * width > _height.height * _height.width);
	}
	void get() {
		cout << "Высота: " << height << "\nШирина: " << width << endl;
	}
	void Square() {
		cout << "Square: " << height * width << endl;
	}
	friend ostream& operator <<(ostream& outputStream,Rectangle _height) {
		return outputStream << _height.height * _height.width;
	}
};
int main ()
{
	double _height = 5.5, _width = 4.4;
	Rectangle <double> arr[3];
	for (int i=0; i< 3; i++) {
		Rectangle <double> arr1(_height-2*i, _width+i);
		arr[i] =arr1;
	}
	cout << "Массив до сортировки ";
	for (int i = 0; i< 3; i++)
		cout<< arr[i]<<" ";
	sort (arr, 3);
	cout << "\nСортированный массив: ";
	for (int i=0; i< 3; i++)
		cout << arr[i] << " ";
}
