#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	char d[] = "0123456789ABCDEF";
	int n, m, r;
	string s;
	cout << "base (2 - 16): ";
	cin >> n;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			s.clear();
			m = i * j;
			while (m > 0) {
				r = m % n;
				s.insert(s.begin(), d[r]);
				m = m / n;
			}
			cout << setw(5) << s;
		}
		cout << endl;
	}
	return 0;
}
