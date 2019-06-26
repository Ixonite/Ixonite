
#include <iostream>
using namespace std;
int main()
{
	int N;
	float sum=0,arifm;
	cout<<"Vvedite N:\n";
	cin>>N;
	float *m = new float [N];
	cout<<"Vvedite chisla"<<endl;
	for(int i=0; i < N; i++) {
		printf("[%d]: ", i);
		
		cin>>m[i];
	}
	for(int i=0; i<N; i++) {
		sum=sum+m[i];
	}
	arifm=sum/N;
	cout<<"Srednee arifmeticheskoe = "<<arifm;
	return 0;
}