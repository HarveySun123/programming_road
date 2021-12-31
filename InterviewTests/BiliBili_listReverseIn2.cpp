/************************************************************************
*
* �ļ�����BiliBili_listReverseIn2.cpp
*
* �ļ�������Bվ�����㷨
* ��Ŀ������
* ������2��Ϊһ�鷴ת
*
* ����������
* {1��2��3��4��5}
*
* ���������
* {5��3��4��1��2}
*
* �����ˣ�Haohui Sun, 2021��11��16��
*
* �汾�ţ�1.0
*
* �޸ļ�¼��
*
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

ListNode* reverse(ListNode* head) {

	// �����еͼ�����
	// һ�����������ָ�������ÿ��������Ҫ��*
	// k=0ʱ��rightָ������ѭ����ָ����һ�ڵ㣬����Ҫ�ظ�ָ����һ�ڵ�
	// ListNode����ʱ�����������˼� -_-|

	ListNode *last = nullptr, *right = head, *left = head;	 
	int k = 2;
	while (right != nullptr) {
		k--;

		// right����һ���β�ڵ㣬���з�ת����
		// left��¼�����׽ڵ��ַ,last��¼�����׽ڵ�
		if (k == 0) {
			ListNode* temp = right->next;
			right->next = last;
			right = temp;

			if (right != nullptr) {
				last = left;
				left = right;
				k = 2;
			}
			
		} else
			right = right->next;
	}

	if (k == 1 && left != nullptr) {
		left->next = last;
	}
	return left;
}

int main() {

	// ��ȡ����������
	int val;
	vector<int> vecData;
	while (cin >> val) {
		vecData.emplace_back(val);
		if (cin.get() == '\n') 
			break;		
	}

	// ��vector��ʼ������
	ListNode* head = nullptr;
	ListNode* cur = head;
	for (int i = 0; i < vecData.size(); ++i) {
		ListNode* node = new ListNode(vecData[i]);
		if (head == nullptr) {
			head = node;
		} else {
			cur->next = node;
		}
		cur = node;
	}

	// ��ת���������
	ListNode* newHead = reverse(head);
	while (newHead != nullptr)
	{
		cout << newHead->val << " ";
		newHead = newHead->next;
	}

	getchar();
	return 0;
}