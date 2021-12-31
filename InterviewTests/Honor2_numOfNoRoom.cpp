/************************************************************************
*
* �ļ�����Honor2_numOfNoRoom.cpp
*
* �ļ���������ҫ����2
* ��Ŀ����:
* a���˳��b�����䡣
* ���룺
* ���η��������ַ�������Ա���ִ�˳��������26Ա����
* �����
* ����ס���ز��
* 
* �����ˣ�Haohui Sun, 2021��11��23��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
// ͨ��75%
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
		cout << "���г�����Ա���ɹ���ס" << endl;
	else
		cout << res << " ��������Ա�޷���ס" << endl;

	system("pause");
	return 0;
}