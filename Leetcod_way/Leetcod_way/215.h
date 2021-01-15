#pragma once
/****************************************
*215.数组中的第k个最大元素 
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***************************************/
#include<MeveralUse_HeadersUsual.h>
using namespace std;
//2021-1-14
//很经典的一道题，算法导论，特定情况下的快排.
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int ret = do_it(nums, 0, nums.size() - 1, k);
		return ret;
	}
	int do_it(vector<int>&nums, int a, int b, int k)
	{
		if (a == b)
			return nums[a];

		int a_ = a;
		int b_ = b;
		int mark = 1;
		while (a != b)
		{
			if (mark == 1)
			{
				if (nums[b] > nums[a])
				{
					swap(nums[a], nums[b]);
					mark = 0;
					++a;
				}
				else
					--b;
			}
			else
			{
				if (nums[a < nums[b]])
				{
					swap(nums[a], nums[b]);
					mark = 1;
					--b;
				}
				else
					++a;
			}
		}
		int t = a - a_ + 1;

		if (t == k)
			return nums[a];
		else if (t < k)
		{
			return do_it(nums, a + 1, b_, k - t);
		}
		else
		{
			return do_it(nums, a_, a - 1, k);
		}


	}
};




