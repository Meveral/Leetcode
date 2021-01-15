#pragma once
#include"MeveralUse_HeadersUsual.h"
/****************************************
*141.��������
����һ�������ж��������Ƿ��л���

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

��������д��ڻ����򷵻� true �� ���򣬷��� false ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***************************************/
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool hasCycle(ListNode *head)
	{
		if (head == NULL)
			return 0;

		ListNode* accessed = new ListNode(1);
		ListNode* node = head;
		ListNode* tmp = NULL;
		while (node != NULL)
		{
			if (node->next == accessed)
				return 1;
			else
			{
				tmp = node->next;
				node->next = accessed;
				node = tmp;
			}
		}

		return 0;
	}
};
