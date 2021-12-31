/************************************************************************
*
* 文件名：PowTest.cpp
*
* 文件描述：STL中pow函数效率测试
* 参考：http://www.cppblog.com/shyli/archive/2007/08/25/30823.html
*
* 创建人：Haohui Sun, 2021年11月28日
*
* 版本号：1.0
*
* 修改记录：
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
	int rep = 1000; //重复次数
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