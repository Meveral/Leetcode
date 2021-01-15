#pragma once
/****************************************
*206.��ת����
��תһ��������

ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* tmp = NULL;
		
		while (head != NULL)
		{
			ListNode* tmp_node = head->next;
			head->next = tmp;
			tmp = head;
			head = tmp_node;
		}
		return tmp;

	}
};

