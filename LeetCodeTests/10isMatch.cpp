/************************************************************************
*
* 文件名：10isMatch.cpp
*
* 文件描述：力扣第10题：正则表达式匹配
*
* 创建人：Haohui Sun, 2021年11月15日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream> 
#include <string>

using namespace std;

bool isMatchCore(string& s, int start1, string& p, int start2) {
	if (s[start1] == '\0' && p[start2] == '\0')
		return true;
	if (s[start1] != '\0' && p[start2] == '\0')
		return false;

	if (p[start2 + 1] != '*') {
		if (s[start1] == p[start2] || (p[start2] == '.' && s[start1] != '\0'))
			return isMatchCore(s, start1 + 1, p, start2 + 1);
		else
			return false;
	}
	else {
		if (s[start1] == p[start2] || (p[start2] == '.' && s[start1] != '\0'))
			return isMatchCore(s, start1 + 1, p, start2 + 2) ||
				   isMatchCore(s, start1, p, start2 + 2) ||
			       isMatchCore(s, start1 + 1, p, start2);
		else
			return isMatchCore(s, start1, p, start2 + 2);
	}

}

bool isMatch(string s, string p) {
	return isMatchCore(s, 0, p, 0);
}

int main() {
	string s;
	cin >> s;
	string p;
	cin >> p;

	cout << isMatch(s, p);
	system("pause");
	return 0;
}