#pragma once
/****************************************
*234.回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-7
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;
		if (!head->next)
			return true;

		ListNode* tmp = head;
		int n{ 1 };
		while (tmp->next)
		{
			++n;
			tmp = tmp->next;
		}

		ListNode* mid_left = NULL;
		ListNode* mid_right = NULL;
		int count{ 0 };
		tmp = head;
		ListNode* last = NULL;

		while (count < (n / 2) - 1)
		{
			auto* tmp_next = tmp->next;
			tmp->next = last;
			last = tmp;
			tmp = tmp_next;
			++count;
		}
		if (n % 2 == 0)//even
		{
			auto* tmp__ = tmp->next;
			mid_left = tmp;
			mid_left->next = last;
			mid_right = tmp__;
		}
		else//odd
		{
			auto* tmp__ = tmp->next->next;
			mid_left = tmp;
			mid_left->next = last;
			mid_right = tmp__;
		}
		while (mid_left != NULL)
		{
			if (mid_left->val != mid_right->val)
				return false;
			mid_left = mid_left->next;
			mid_right = mid_right->next;
		}

		return true;
	}
};


