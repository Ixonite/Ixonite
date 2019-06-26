#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("data_v26.bin", ios::binary);
	if (! fin.good()) {
		cout<< "Файл не открылся\n";
		return 1;
	}
	fin.seekg(0,fin.end); //смещение в конец файла
	size_t razm = fin.tellg(); // узнали размер файла
	cout << razm << endl;
	const size_t razm1 = razm/sizeof(float);
	double *m = new double [razm1];
	fin.seekg(0,fin.beg);
	fin.read((char *) m,razm);
	float *m1 = new float [razm1];
	for (int i = 0 ; i < razm1; i++) {
		m1[i] = 1 / m[i];
		cout << m1[i] << endl;
	}
	ofstream fin1 ("fail1.bin");
	if (! fin1.good()) {
		cout<< "error\n";
		return 2;
	}
	fin1.write((char*)m1,sizeof (m1));
	return 0 ;
}
