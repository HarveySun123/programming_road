/************************************************************************
*
* 文件名：Honor2_numOfNoRoom.cpp
*
* 文件描述：荣耀机试2
* 题目描述:
* a个人出差，b个房间。
* 输入：
* 整形房间数，字符串代表员工抵达顺序（因此最多26员工）
* 输出：
* 不够住返回差几间
* 
* 创建人：Haohui Sun, 2021年11月23日
*
* 版本号：1.0
*
* 修改记录：
*
************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
// 通过75%
int numOfNoRoom(int nRoom, string strMan) {

	unordered_map<char, bool> mapIsIn;
	int res = 0;
	for (auto c : strMan) {
		if (mapIsIn.find(c) == mapIsIn.end()) {
			if (nRoom > 0) {
				mapIsIn[c] = true;
				--nRoom;
			}
			else {
				mapIsIn[c] = false;
				++res;
			}
		}
		else {
			if (mapIsIn[c] == true)
				++nRoom;
			mapIsIn.erase(c);
		}
	}

	return res;
}

int main() {
	int nRoom;
	string strMan;
	cin >> nRoom >> strMan;
	int res = numOfNoRoom(nRoom, strMan);

	if (res <= 0)
		cout << "所有出差人员都成功入住" << endl;
	else
		cout << res << " 个出差人员无法入住" << endl;

	system("pause");
	return 0;
}