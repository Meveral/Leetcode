#pragma once
/****************************************
*148.排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-13
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head)
			return NULL;
		if (!head->next)
			return head;

		auto last_head = head;
		head = head->next;
		while (head)
		{
			auto next_head = head->next;
			int a = head->val;
			if (a <= last_head->val)//若小，不用排序，直接插至末尾
			{
				head->next = last_head;
				last_head = head;
			}
			else
			{
				auto it = last_head;//last_head还要用，所以不要改变其值
				while (it->next&&a > it->next->val)
				{
					it = it->next;
				}
				if (!it->next)
				{
					it->next = head;
					head->next = nullptr;
				}
				else
				{
					auto mid = it->next;
					it->next = head;
					head->next = mid;
				}
			}
			head = next_head;
		}

		return last_head;
	}
};

