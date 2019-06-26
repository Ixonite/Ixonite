#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
	char *value;
	int len;
public:
	String():value(new char[1] {}),len(0) { // конструктор по умолчанию
	}
	String(const char* s) {// конструктор инициализации Си-строкой
		len = strlen(s); // функция определения длины строки
		value = new char[len + 1];
		strcpy(value, s); // функция копирования s в value
	}
	String(const String& s) { // конструктор копирования
		len=s.len;
		value = new char[len+1]; // выделить память под новый буфер
		for (int i=0; i<=len; i++) // скопировать строку в новый буфер
			value[i]=s.value[i];
	}
	~String() {
		delete[] value;//деструктор
	}
	String& operator = (const String& s) {
		if (this != &s) { // игнорировать присваивания вида a = a
			delete[] value; // удаляем старое значение
			len = s.len; // длина строки
			value = new char[len+1]; // выделить память под новый буфер
			strcpy(value, s.value);
		}
		return *this;
	}
	/*String operator - () const { // бинарный минус
		String temporary;
		temporary.len = len;
		delete [] temporary.value;
		temporary.value = new char [len +1];
		for (int i=0; i< len; i++)
			temporary.value[i] = value [ len - i-1];
		temporary.value[len] = 0;
		return temporary;
	}*/
	String(int size):value(new char[size+1]), len(size) {}
	String operator-() const { // унарный минус
		String ret(len);
		for (int i=0; i<len; i++) {
			ret.value[i] = value[len-i-1];
		}
		ret.value[len] = 0;
		return ret; //возвращаем временный объект
	}
	String operator + (const String& right) {
		char *s = new char[len + right.len + 1];
		String result(strcat(strcpy(s, value), right.value)); //strcat соединяет в цепочку строки
		delete[] s;
		return result;
	}
	friend istream& operator >> (istream& stream, String& s);// дружественный класс
	friend ostream& operator << (ostream& stream, const String& s);// дружественный класс
};
istream& operator >> (istream& stream, String& s)   //перегруженный оператор ввода
{
	return stream >> s.value;
}
ostream& operator<<(ostream& outputStream, const String & s)   //перегрузка опереатора вывода
{
	return outputStream<< s.value;
}
int main()
{
	String str1, str2, Result;

	str1 = "Hello";
	str1 = - str1;
	cout << str1 <<endl;
	//cout << "Введите 2 строку: ";
	//cin >> str2;
	//cout << str1 << " + " << str2;
	//Result = str1 + str2;
	//cout << " = " << Result << endl;
	return 0;
}
