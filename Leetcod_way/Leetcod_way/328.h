#pragma once
/****************************************
*328. ��ż����
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:

����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:

����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL
˵��:

Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/odd-even-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

***************************************/


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		else if (head->next == nullptr)
			return head;

		ListNode* odd_node = head;
		ListNode* even_node = head->next;
		ListNode* first_even_node = even_node;

		ListNode* tmp_node = even_node->next;
		int sign = 1;
		while (tmp_node != nullptr)
		{
			if ((sign % 2) == 1)
			{
				odd_node->next = tmp_node;
				odd_node = tmp_node;
				++sign;
			}
			else
			{
				even_node->next = tmp_node;
				even_node = tmp_node;
				++sign;
			}
			tmp_node = tmp_node->next;
		}
		even_node->next = nullptr;
		odd_node->next = first_even_node;
		return head;
	}
};

