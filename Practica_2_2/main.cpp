#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
int RandomGenerator()
{
	static mt19937 rnd(50);
	uniform_int_distribution<int>d(- 1000000000,1000000000);
	return d(rnd);
}
/*void show_vector( vector<int>&a_vec)
{
	for (vector<int>::iterator it = a_vec.begin() ; it!=a_vec.end() ; ++it)
		cout<<*it << endl;
}*/
int main()
{
	vector <int> v1;
	vector<int> v2(10000000);
	mt19937 rnd(50);
	uniform_int_distribution<int>roll(- 1000000000,1000000000);
	for (int i=0; i < 10000000; i++)
		v1.push_back(roll(rnd));
	generate(v2.begin(),v2.end(),RandomGenerator);
	vector<int> v3(v2);
	//show_vector(v3);
	return 0;
}