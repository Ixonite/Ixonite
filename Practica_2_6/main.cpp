#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;
bool Familya (const wstring& ws1, const wstring& ws2)
{
	int pos1 = ws1.find(L" ");
	int pos2 = ws2.find(L" ");
	return (ws1.substr(0, pos1) == ws2.substr(0, pos2));
}
bool rName (const pair <wstring, int> & p1, const pair <wstring, int> & p2)
{
	return p1.second < p2.second;
}
bool pName (const pair <wstring, int> & p1, const pair<wstring, int> & p2)
{
	return p1.second < p2.second;
}
wstring Name(wstring& s )
{
	int start_pos = s.find(L" ") + 1;
	int pos = s.find(L" ", start_pos) - start_pos;
	return s.substr(start_pos, pos);
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	set <wstring> p;
	wifstream f("name.txt");
	while (!f.eof()) {
		wstring s;
		getline(f, s);
		p.insert(s);
	}
	for (auto it = ++p.begin(); it != p.end(); it++) {
		it = adjacent_find(--it, p.end(), Familya);
		wcout << L"Однофамильцы: " << *(it) << L" и " <<
		      *(it++) << endl;
	}
	map <wstring, int> name;
	map <wstring, int>::iterator it;
	for(auto i : p) {
		name [Name(i)]++;
	}
	auto it1 = max_element(name.begin(), name.end(),pName);
	auto it2 = min_element(name.begin(), name.end(),rName);
	wcout << L"Часто: " << endl;
	for (it = name.begin(); it != name.end(); it++) {
		if (it -> second == it1 -> second)
			wcout << it -> first << endl;
	}
	wcout << L"Редко: " << endl;
	for (it = name.begin(); it != name.end(); it++) {
		if (it -> second == it2 -> second)
			wcout << it -> first << endl;
	}
	f.close();
	return 0;
}