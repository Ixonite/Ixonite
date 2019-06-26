#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>
using namespace std;
void findPass(string pass, const string& hash)
{
	static mutex mtx;
	crypt_data *pCryptData = new crypt_data;
	size_t pos = hash.find_last_of('$');
	string hashHead = hash.substr(0,pos);
	do {
		string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
		if (newHash == hash) {
			lock_guard<mutex> lock(mtx);
			cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
			break;
		}
	} while ( next_permutation( pass.begin(), pass.end() ) );
	delete pCryptData;
}
int main(int argc, char *argv[])
{
	int n ;
	cout << "Ведите количество хешей (1,2,4,8): "<< endl;
	cin >> n ;
	ifstream fin("hash.txt");
	string *str = new string [n];
	for (int i= 0 ; i < n; i++) {
		fin>> str[i];
	}
	string s = "123456789";
	for (int i= 0 ; i < n; i++) {
		findPass(s,str[i]);
	}
	return 0;
}
