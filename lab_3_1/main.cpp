#include<string>
#include<iostream>
#include<codecvt>
#include<locale>
using namespace std;
int main()
{
	int x;
	cout<<"Число в диапазоне от 1 до 100"<<endl;
	cin>>x;
	if(x > 0 && x<=100) {
		locale loc("ru_RU.UTF-8");
		wstring_convert <codecvt_utf8<wchar_t>,wchar_t> codec;
		string s = "В караване было  верблюдов";
		wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 в UTF-32
		if((x%10==0)||(x % 10 >= 5 && x % 10 <= 9)||(x % 100 >=11 && x%100 <=14)) {
			ws.insert(16,to_wstring(x));
		} else {
			if(x % 10 == 1) {
				ws.erase(14,1);
				ws.erase(23,2);
				ws.insert(15,to_wstring(x));
			} else {
				ws.erase(24,2);
				ws.push_back(L'a');
				ws.insert(16,to_wstring(x));
			}
		}
		s = codec.to_bytes(ws);// перекодируем из UTF-32 в UTF-8
		cout<< s <<endl;
	} else
		return 0;
}
