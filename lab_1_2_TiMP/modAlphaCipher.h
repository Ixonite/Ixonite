#pragma once
#include <string>
using namespace std;

class Cipher
{
	char** value;
	int m, n; // строки и столбцы
public:
	Cipher() = delete;
	Cipher(int key, const string& s);
	string encrypt(const std::string& open_text);  //зашифрование
	string decrypt(const std::string& cipher_text);//расшифрование
	~Cipher();
};
