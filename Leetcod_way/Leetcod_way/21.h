#pragma once
/****************************************
*21.合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-6
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* ret = new ListNode(-9999, l1);
		auto left = ret;
		auto right = l2;

		ListNode* tmp;
		while (left != NULL && right != NULL)
		{
			if (left->val <= right->val)
			{
				tmp = left;
				left = left->next;
				continue;
			}
			else
			{
				tmp->next = right;
				auto tmp_ = right->next;
				right->next = left;
				tmp = right;
				right = tmp_;
			}
		}
		if (left == NULL)
			tmp->next = right;

		return ret->next;
	}
};

