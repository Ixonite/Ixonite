#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;
int RandomGenerator()
{
	static mt19937 rnd(50);
	uniform_int_distribution<int>d(- 1000000000,1000000000);
	return d(rnd);
}
int main()
{
	vector <int> v1;
	mt19937 rnd(50);
	uniform_int_distribution<int>roll(- 1000000000,1000000000);
	steady_clock::time_point tp1 = steady_clock::now();
	for (int i=0; i < 10000000; i++)
		v1.push_back(roll(rnd));
		
	steady_clock::time_point tp2 = steady_clock::now();
	duration<double> d = tp2 - tp1;
	cout << "vector 1: " << d.count() << endl;
	
	tp1 = steady_clock::now();
	vector<int> v2(10000000);
	generate(v2.begin(),v2.end(),RandomGenerator);
	tp2 = steady_clock::now();
	d = tp2 - tp1;
	cout << "vector 2: " << d.count() << endl;
	
	tp2 = steady_clock::now();
	vector<int> v3(v2);
	d = tp2 - tp1;
	cout << "vector 3: " << d.count() << endl;
	return 0;
}