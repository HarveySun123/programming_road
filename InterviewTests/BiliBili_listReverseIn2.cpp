/************************************************************************
*
* 文件名：BiliBili_listReverseIn2.cpp
*
* 文件描述：B站面试算法
* 题目描述：
* 链表以2个为一组反转
*
* 输入描述：
* {1，2，3，4，5}
*
* 输出描述：
* {5，3，4，1，2}
*
* 创建人：Haohui Sun, 2021年11月16日
*
* 版本号：1.0
*
* 修改记录：
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

	// 面试中低级错误：
	// 一行内声明多个指针变量，每个变量需要加*
	// k=0时，right指针已在循环内指向下一节点，不需要重复指向下一节点
	// ListNode声明时参数类型忘了加 -_-|

	ListNode *last = nullptr, *right = head, *left = head;	 
	int k = 2;
	while (right != nullptr) {
		k--;

		// right到达一组的尾节点，进行反转操作
		// left记录本组首节点地址,last记录上组首节点
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

	// 读取不定长数据
	int val;
	vector<int> vecData;
	while (cin >> val) {
		vecData.emplace_back(val);
		if (cin.get() == '\n') 
			break;		
	}

	// 用vector初始化链表
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

	// 反转并输出链表
	ListNode* newHead = reverse(head);
	while (newHead != nullptr)
	{
		cout << newHead->val << " ";
		newHead = newHead->next;
	}

	getchar();
	return 0;
}