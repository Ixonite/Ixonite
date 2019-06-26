#include <string>
#include <iostream>
#include <codecvt>
#include <locale>
using namespace std;
locale loc("ru_RU.UTF-8");
wstring_convert <codecvt_utf8<wchar_t>,wchar_t> codec;
void encrypt(wstring &text,const int key)
{
	int razmer = text.size();
	for (int i = 0; i < razmer; i++) {
		razmer = text.size();
		if((text[i] >= L'А' && text[i] <= L'п') || (text[i] >= L'р' && text[i] <= L'я')) {
			text[i] = tolower(text[i],loc);
		} else {
			text.erase(i,1);
			i--;
		}
	}
	razmer = text.size();
	for (int i = 0; i < razmer; i++)
		text[i] -= key;
}
int main()
{
	int k;
	string s = "ФЗЧПРНРЕКККОЗФРЖЭСТРЕТВООКТРДВПКБ";
	cout << "Текст для шифровки: " << s << endl;;
	cout << "Введите ключ: ";
	cin >> k;
	wstring ws = codec.from_bytes(s);

	encrypt(ws,k);

	s = codec.to_bytes(ws);
	cout << s << endl;
	return 0;
}
