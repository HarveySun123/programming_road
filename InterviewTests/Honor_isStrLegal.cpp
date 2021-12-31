/************************************************************************
*
* �ļ�����7reverse.cpp
*
* �ļ���������ҫ����
* ��Ŀ������
* �������ַ�������Ƿ���ڷǷ��ַ�������Ϸ��ַ�����ȥ�أ��ͷǷ��ַ�������ȥ�أ���
* �ԺϷ��ַ���ѭ������10�Σ��ٽ���������������������ַ�����abc����ѭ������һ�εĽ��Ϊ��bca������
* 
* ����������
* ��1�� �ַ����е��ַ�����Ϊ��0��-��9������a��-��z������A��-��Z��������Ϊ�Ƿ��ַ������ַ�����Ϊ����������зǷ��ַ����ַ�����Ϊ�Ƿ����룻
* ��2�� ��Ϊ������ַ�������������100��ÿ���ַ������Ȳ�����64��
* ��3�� ��Ϊ������������ַ������ո��Ʊ�����س������з�����Ϊһ���ո�����Ϊ��������ַ�����ʼ�ַ���Ϊ�գ���
* ��4�� ����ÿ��ֻ��һ���ַ���
* ��5�� �����Կ��н�����
* 
* ���������
* ��1�� ����Ϸ��ַ�����ȥ�أ�
* ��2�� ������зǷ��ַ�����
* ��3�� �Խ��1��ȥ�غϷ��ַ���ѭ������10�Σ�
* ��4�� �Խ��3�Ϸ��ַ������򣬰�ASCII���ַ���С����˳������
* 
* ע�����
* ÿ���һ���ַ����ÿո����һ���ַ������룬��Ϊ����������ַ���֮��ֻ����һ���ո���Ϊ���������
* 
*
* �����ˣ�Haohui Sun, 2021��11��15��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
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

	for (int j = 1; j < rsize; ++j)//ȥ�ز����
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
	for (int i = 0; i < rsize; ++i)//�Ƿ��ַ���
	{
		cout << ilegStr[i] << " ";
	}

	cout << endl;
	rsize = leftLegStr.size();
	for (int i = 0; i < rsize; ++i)//�����ַ���
	{
		cout << leftLegStr[i] << " ";
	}

	cout << endl;
	sort(leftLegStr.begin(), leftLegStr.end());//�����ַ���
	rsize = leftLegStr.size();
	for (int i = 0; i < rsize; ++i)//�����ַ���
	{
		cout << leftLegStr[i] << " ";
	}

	return 0;

}