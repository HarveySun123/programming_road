/************************************************************************
*
* �ļ�����PowTest.cpp
*
* �ļ�������STL��pow����Ч�ʲ���
* �ο���http://www.cppblog.com/shyli/archive/2007/08/25/30823.html
*
* �����ˣ�Haohui Sun, 2021��11��28��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
const int MAX = 10000;
int a[MAX];
int main()
{
	int i, j, n = MAX;
	int rep = 1000; //�ظ�����
	clock_t beg, end;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20000 - 10000; //-10000 <= a[i]< 10000

	cout << "test a[i]*a[i]" << endl;
	beg = clock();
	for (j = 0; j < rep; j++)
		for (i = 0; i < n; i++)
			a[i] * a[i];
	end = clock();
	cout << "time: " << end - beg << "ms" << endl;

	cout << "test pow(a[i], 2.0)" << endl;
	beg = clock();
	for (j = 0; j < rep; j++)
		for (i = 0; i < n; i++)
			pow(a[i], 2.0);
	end = clock();
	cout << "time: " << end - beg << "ms" << endl;

	getchar();
	return 0;
}