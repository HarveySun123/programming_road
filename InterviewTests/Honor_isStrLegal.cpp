/************************************************************************
*
* 文件名：7reverse.cpp
*
* 文件描述：荣耀机试
* 题目描述：
* 对输入字符串检查是否存在非法字符，输出合法字符串（去重）和非法字符串（不去重）。
* 对合法字符串循环左移10次，再进行排序输出。（举例：字符串“abc”，循环左移一次的结果为”bca”）。
* 
* 输入描述：
* （1） 字符串中的字符集合为’0’-‘9’，‘a’-‘z’，‘A’-‘Z’，其余为非法字符（空字符串作为定界符），有非法字符的字符串视为非法输入；
* （2） 作为输入的字符串个数不超过100，每个字符串长度不超过64；
* （3） 作为输入的连续空字符串（空格、制表符、回车、换行符）作为一个空格处理（作为定界符，字符串起始字符不为空）；
* （4） 输入每行只有一个字符；
* （5） 输入以空行结束。
* 
* 输出描述：
* （1） 输出合法字符串并去重；
* （2） 输出所有非法字符串；
* （3） 对结果1的去重合法字符串循环左移10次；
* （4） 对结果3合法字符串排序，按ASCII表字符从小到大顺序排序。
* 
* 注意事项：
* 每输出一个字符后用空格跟下一个字符串隔离，作为输出的所有字符串之间只能有一个空格（作为定界符）。
* 
*
* 创建人：Haohui Sun, 2021年11月15日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string temp;
	string cutstr;
	vector<string> ilegStr;
	vector<string> legStr;
	vector<string> leftLegStr;
	vector<string> sortLegStr;

	int rsize = 0;
	while (cin >> temp)
	{
		int size = temp.size();
		int iflag = 0;
		int mtimes = 0;
		for (int i = 0; i < size; ++i)
		{
			if ( (temp[i] >= '0' && temp[i] <= '9') || 
				(temp[i] >= 'a' && temp[i] <= 'z') ||
				(temp[i] >= 'A' && temp[i] <= 'Z'))
			{
				iflag = 0;
			} else {
				iflag = 1;
				break;
			}
		}

		if (iflag == 0) {
			legStr.push_back(temp);
			if (size <= 10)
			{
				mtimes = 10 % size;
			}
			else {
				mtimes = 10;
			}

			if (mtimes != 0)
			{
				cutstr = temp.substr(0, mtimes);
				temp = temp.erase(0, mtimes);
				temp.append(cutstr);
			}
			leftLegStr.push_back(temp);
		}
		else
		{
			ilegStr.push_back(temp);
		}
	}

	rsize = legStr.size();
	string laststr = legStr[0];
	cout << legStr[0] << " ";

	for (int j = 1; j < rsize; ++j)//去重并输出
	{

		if (legStr[j] == laststr)
			++j;
		else
		{
			cout << legStr[j] << " ";
			laststr = legStr[j];
		}
	}
	cout << endl;
	rsize = ilegStr.size();
	for (int i = 0; i < rsize; ++i)//非法字符串
	{
		cout << ilegStr[i] << " ";
	}

	cout << endl;
	rsize = leftLegStr.size();
	for (int i = 0; i < rsize; ++i)//左移字符串
	{
		cout << leftLegStr[i] << " ";
	}

	cout << endl;
	sort(leftLegStr.begin(), leftLegStr.end());//排序字符串
	rsize = leftLegStr.size();
	for (int i = 0; i < rsize; ++i)//排序字符串
	{
		cout << leftLegStr[i] << " ";
	}

	return 0;

}